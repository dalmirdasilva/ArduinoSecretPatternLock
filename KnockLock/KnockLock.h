#include <RandomAccess.h>
#include <Feedbacker.h>

#define KNOCK_LOCK_MAX_KNOCKS                               16
#define KNOCK_LOCK_MAX_TIME_BETWEEN_KNOCKS                  1000
#define KNOCK_LOCK_DISSIPATE_KNOCK_DEBOUNCE_TIME            100
#define KNOCK_LOCK_RELEASE_BUTTON_DEBOUNCE_TIME             500
#define KNOCK_LOCK_PROGRAM_BUTTON_MIN_TIME_PRESSED          1500

// Shuldn't be bigger than sizeof(char)
#define KNOCK_LOCK_NORMALIZATION_LENGTH                     100
#define KNOCK_LOCK_PATTERN_SAVED_BLINKS                     3
#define KNOCK_LOCK_TIME_MISSMATCH_THRESHOLD                 25
#define KNOCK_LOCK_AVG_TIME_MISSMATCH_THRESHOLD             15
#define KNOCK_LOCK_BIP_FREQUENCY                            10

class KnockLock {

    int knockPin;

    int programPin;

    int buzzerPin;

    Feedbacker *feedbacker;

    RandomAccess *storage;

    int patternSize;

    int knocksSize;

    bool programMode;

    unsigned char pattern[KNOCK_LOCK_MAX_KNOCKS];

    unsigned int knocks[KNOCK_LOCK_MAX_KNOCKS];

    enum Feedback {
        ENTER_PROGRAM_MODE = 0x00,
        EXIT_PROGRAM_MODE,
        PATTERN_SAVED,
        KNOCKS_MISMATCH
    };
public:

    KnockLock(int knockPin, int programPin, int buzzerPin, Feedbacker *feedbacker, RandomAccess *storage);

    void initialize();

    bool listen(unsigned long timeout = 0);

    void playback();

    void bip(unsigned int duration = 100);

private:

    /**
     * Enter in the program mode. Keep programPin in high impedance for
     * KNOCK_LOCK_PROGRAM_BUTTON_MIN_TIME_PRESSED millis.
     */
    void enterProgramMode();

    /**
     * Exits from program mode. After record the patter.
     */
    void exitProgramMode();

    bool isInProgramMode();

    /**
     * After the first knock it records the times between knocks.
     */
    void processKnocks();

    void knockDelay();

    void normalizeKnocks();

    bool validateKnocks();

    bool doKnocksMatchPattern();

    void loadPattern();

    void savePattern();
};
