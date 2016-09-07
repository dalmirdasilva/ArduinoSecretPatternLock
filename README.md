# ArduinoSecretPatternLock

```
#include <Arduino.h>
#include <RandomAccessByteArray.h>
#include <KnockLock.h>
#include <LedFeedbacker.h>

#define LED_FEEDBACK_PIN            13
#define BUZZER_PIN                  11
#define PUSH_BUTTON_PROGRAM_PIN     5
#define KNOCK_SENSOR_PIN            6
#define BUFFER_MAX_SIZE             KNOCK_LOCK_MAX_KNOCKS + 1

unsigned char patterBuffer[BUFFER_MAX_SIZE];

LedFeedbacker feedbacker(LED_FEEDBACK_PIN);
RandomAccessByteArray storage(patterBuffer, BUFFER_MAX_SIZE);
KnockLock knockLock(KNOCK_SENSOR_PIN, PUSH_BUTTON_PROGRAM_PIN, BUZZER_PIN, &feedbacker, &storage);

void setup() {
    Serial.begin(9600);
    knockLock.initialize();
}

void loop() {
    if (knockLock.listen()) {
        knockLock.bip(400);
    }
}

```

# On Eclipse

#include <Arduino.h>
#include <RandomAccessInternalEeprom.h>
#include <KnockLock.h>
#include <LedFeedbacker.h>

#define LED_FEEDBACK_PIN            13
#define BUZZER_PIN                  11
#define PUSH_BUTTON_PROGRAM_PIN     5
#define KNOCK_SENSOR_PIN            A0
#define BUFFER_MAX_SIZE             KNOCK_LOCK_MAX_KNOCKS + 1

LedFeedbacker feedbacker(LED_FEEDBACK_PIN);
RandomAccessInternalEeprom storage(0, BUFFER_MAX_SIZE);
KnockLock knockLock(KNOCK_SENSOR_PIN, PUSH_BUTTON_PROGRAM_PIN, BUZZER_PIN, &feedbacker, &storage);

void setup() {

    Serial.begin(9600);

    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, INPUT);

    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);

    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);

    knockLock.initialize();
}

void loop() {
    if (knockLock.listen()) {
        knockLock.bip(400);
    }
}

int main(void) {
    init();
#if defined(USBCON)
    USBDevice.attach();
#endif
    setup();
    for (;;) {
        loop();
        if (serialEventRun) {
            serialEventRun();
        }
    }
    return 0;
}
