/* Assignment or exercise number: PA1 - Robber Language Translation */

#include <string>

using namespace std;

class Model
{
public:
    Model();    // default constructor
    virtual ~Model(); //default destructor

    // takes consonant as an input and returns a Rövarspråket translated string
    string translateSingleConsonant(char consonant);

    // takes vowel as an input and returns a Rövarspråket translated string
    string translateSingleVowel(char vowel);
};