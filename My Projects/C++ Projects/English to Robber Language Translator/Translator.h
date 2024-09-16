/* Assignment or exercise number: PA1 - Robber Language Translation */

#include <string>

using namespace std;

class Translator
{
public:
    Translator(); // default constructor
    virtual ~Translator(); //default destructor

    // takes a string (Single English Word) as the input and returns the Rövarspråket translated string
    string translateEnglishWord(string englishWord); 

    // takes a string (Single English Sentence) as the input and returns the Rövarspråket translated string
    string translateEnglishSentence(string englishSentence);
};

