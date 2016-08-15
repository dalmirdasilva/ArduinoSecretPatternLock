/**
 * Arduino - ArduinoSecretPatternLock driver
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_SECRET_PATTERN_LOCK_FEEDBACKER_H__
#define __ARDUINO_SECRET_PATTERN_LOCK_FEEDBACKER_H__ 1

class Feedbacker {
public:

    enum Feedback {
        ACCESS_DENIED = 0x00,
        ACCESS_GRANTED,
        INVALID_OPERATION,
        ENTER_PROGRAM_MODE,
        EXIT_PROGRAM_MODE,
        SUCCESSFULLY_SAVED
    };

    virtual void sendFeedback(Feedback feedback) = 0;
};

#endif // __ARDUINO_SECRET_PATTERN_LOCK_FEEDBACKER_H__
