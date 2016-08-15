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
    knockLock.listen();
}

```
