#include <Arduino.h>
#include <KnockLock/KnockLock.h>

KnockLock::KnockLock(int knockPin, int programPin, int buzzerPin, Feedbacker *feedbacker, RandomAccess *storage)
        : knockPin(knockPin), programPin(programPin), buzzerPin(buzzerPin), feedbacker(feedbacker), storage(storage), patternSize(0), knocksSize(0), programMode(false) {
}

void KnockLock::initialize() {
    pinMode(knockPin, INPUT);
    pinMode(programPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    loadPattern();
}

void KnockLock::playback() {
    for (unsigned char i = 0; i < patternSize; i++) {
        bip();
        delay(pattern[i] * 5);
    }
    bip();
}

void KnockLock::bip(unsigned int duration) {
    unsigned int iterrations = duration / KNOCK_LOCK_BIP_FREQUENCY;
    for (unsigned int j = 0; j < iterrations; j++) {
        digitalWrite(buzzerPin, HIGH);
        delay(KNOCK_LOCK_BIP_FREQUENCY);
        digitalWrite(buzzerPin, LOW);
    }
}

bool KnockLock::listen(unsigned long timeout) {
    unsigned long startTime = millis();
    do {
        if (digitalRead(programPin) == HIGH) {
            enterProgramMode();
        }
        if (digitalRead(knockPin) == HIGH) {
            processKnocks();
            if (validateKnocks()) {
                feedbacker->sendFeedback(Feedbacker::ACCESS_GRANTED);
                return true;
            }
            if (isInProgramMode()) {
                exitProgramMode();
            } else {
                feedbacker->sendFeedback(Feedbacker::ACCESS_DENIED);
            }
        }
    } while (timeout == 0 || millis() - startTime < timeout);
    return false;
}

void KnockLock::processKnocks() {
    unsigned long startTime, now;
    knocksSize = 0;
    now = millis();
    startTime = now;
    knockDelay();
    do {
        unsigned char knock = digitalRead(knockPin);
        if (knock == HIGH) {
            knocks[knocksSize] = now - startTime;
            knocksSize++;
            startTime = now;
            knockDelay();
        }
        now = millis();
    } while ((now - startTime < KNOCK_LOCK_MAX_TIME_BETWEEN_KNOCKS) && (knocksSize < KNOCK_LOCK_MAX_KNOCKS));
}

void KnockLock::normalizeKnocks() {
    unsigned int maxKnockTime = 0;
    for (int i = 0; i < knocksSize; i++) {
        if (knocks[i] > maxKnockTime) {
            maxKnockTime = knocks[i];
        }
    }
    for (int i = 0; i < knocksSize; i++) {
        knocks[i] = map(knocks[i], 0, maxKnockTime, 0, KNOCK_LOCK_NORMALIZATION_LENGTH);
    }
}

bool KnockLock::validateKnocks() {
    if (knocksSize == 0) {
        return false;
    }
    normalizeKnocks();
    if (isInProgramMode()) {
        savePattern();
        return false;
    }
    // Need be checked after isInProgramMode
    if (knocksSize != patternSize) {
        return false;
    }
    return doKnocksMatchPattern();
}

bool KnockLock::doKnocksMatchPattern() {
    int totalTimeMissmatch = 0;
    int timeMissmatch = 0;
    for (int i = 0; i < patternSize; i++) {
        timeMissmatch = abs(((int)knocks[i]) - pattern[i]);
        if (timeMissmatch > KNOCK_LOCK_TIME_MISSMATCH_THRESHOLD) {
            return false;
        }
        totalTimeMissmatch += timeMissmatch;
    }
    if (totalTimeMissmatch / patternSize > KNOCK_LOCK_AVG_TIME_MISSMATCH_THRESHOLD) {
        return false;
    }
    return true;
}

void KnockLock::enterProgramMode() {
    unsigned long startTime = millis();
    do {
        if (digitalRead(programPin) == LOW) {
            return;
        }
    } while ((millis() - startTime) < KNOCK_LOCK_PROGRAM_BUTTON_MIN_TIME_PRESSED);
    programMode = true;
    feedbacker->sendFeedback(Feedbacker::ENTER_PROGRAM_MODE);
    while (digitalRead(programPin) == HIGH) {
    }
    delay(KNOCK_LOCK_RELEASE_BUTTON_DEBOUNCE_TIME);
}

void KnockLock::exitProgramMode() {
    programMode = false;
    feedbacker->sendFeedback(Feedbacker::EXIT_PROGRAM_MODE);
}

bool KnockLock::isInProgramMode() {
    return programMode;
}

void KnockLock::knockDelay() {
    int itterations = KNOCK_LOCK_DISSIPATE_KNOCK_DEBOUNCE_TIME / 20;
    for (int i = 0; i < itterations; i++) {
        delay(10);
        analogRead(knockPin);
        delay(10);
    }
}

void KnockLock::loadPattern() {
    storage->seek(0);
    patternSize = storage->readUnsignedChar();
    if (patternSize < 0) {
        patternSize = 0;
    }
    if (patternSize > KNOCK_LOCK_MAX_KNOCKS) {
        patternSize = KNOCK_LOCK_MAX_KNOCKS;
    }
    for (int i = 0; i < patternSize; i++) {
        pattern[i] = storage->readUnsignedChar();
    }
}

void KnockLock::savePattern() {
    storage->seek(0);
    storage->writeUnsignedChar(knocksSize & 0xff);
    for (int i = 0; i < knocksSize; i++) {
        storage->writeUnsignedChar(knocks[i] & 0xff);
        pattern[i] = knocks[i];
    }
    patternSize = knocksSize;
    feedbacker->sendFeedback(Feedbacker::SUCCESSFULLY_SAVED);
    playback();
}
