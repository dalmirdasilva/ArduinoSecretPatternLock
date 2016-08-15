#include <Feedbacker.h>

class LedFeedbacker : public Feedbacker {

    int ledPin;
public:

    LedFeedbacker(int ledPin);

    void sendFeedback(Feedback feedback);
};
