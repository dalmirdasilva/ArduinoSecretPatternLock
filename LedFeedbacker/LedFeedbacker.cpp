#include "LedFeedbacker.h"
#include <Arduino.h>

LedFeedbacker::LedFeedbacker(int ledPin) : ledPin(ledPin) {
    pinMode(ledPin, OUTPUT);
}

void LedFeedbacker::sendFeedback(Feedback feedback) {
    unsigned char blinks = 0;
    switch (feedback) {
    case ENTER_PROGRAM_MODE:
        digitalWrite(ledPin, HIGH);
        break;
    case EXIT_PROGRAM_MODE:
        digitalWrite(ledPin, LOW);
        break;
    case ACCESS_GRANTED:
        blinks = 1;
        break;
    case ACCESS_DENIED:
        blinks = 2;
        break;
    case SUCCESSFULLY_SAVED:
        blinks = 4;
        break;
    case INVALID_OPERATION:
        break;
    }
    for (unsigned char i = 0; i < blinks; i++) {
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        delay(100);
    }
}
