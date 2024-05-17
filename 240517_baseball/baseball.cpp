#include <stdexcept>
using namespace std;

struct GuessResult {
    bool sovled;
    int strikes;
    int balls;
};

class Baseball {
public:
    explicit Baseball(const string& question)
        : question(question),
        strikesCnt{0},
        ballCnt{0}    
    {

    }

    GuessResult guess(const string& guessNumber) {
        assertIllegalArgument(guessNumber);
        checkMatch(guessNumber);
        return { isSoved(), strikesCnt, ballCnt};
    }

    void checkMatch(const string& guessNumber)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (guessNumber[i] != question[j]) continue;

                if (i == j) {
                    strikesCnt++;
                }
                else {
                    ballCnt++;
                }
                continue;
            }
        } 
    }

    bool isSoved() {
        return strikesCnt == 3 ? true : false;
    }

    void assertIllegalArgument(const string& guessNumber) {
        if (guessNumber.length() != 3) {
            throw length_error("Must be three letters.");
        }

        for (char ch : guessNumber) {
            if (ch >= '0' && ch <= '9') continue;
            throw invalid_argument("Must be number");
        }

        if (isDuplicatedNumber(guessNumber)) {
            throw invalid_argument("Must not have the same number");
        }
    }
    bool isDuplicatedNumber(const string& guessNumber) {
        if (guessNumber[0] == guessNumber[1]
            || guessNumber[0] == guessNumber[2]
            || guessNumber[1] == guessNumber[2])
            return true;
        return false;
    }
private:
    string question;
    int ballCnt;
    int strikesCnt;
};