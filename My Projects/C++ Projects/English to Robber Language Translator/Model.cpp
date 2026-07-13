/* Assignment or exercise number: PA1 - Robber Language Translation */

#include <string>
#include "Model.h"

using namespace std;

    Model::Model(){}    // default constructor
    Model::~Model(){} //default destructor

    // takes consonant as an input and returns a Rövarspråket translated string
    string Model::translateSingleConsonant(char consonant)
    {
        string finalCon = "";
        finalCon += consonant;
        finalCon += "o";
        finalCon += tolower(consonant);
        return finalCon;
    }

    // takes vowel as an input and returns a Rövarspråket translated string
    string Model::translateSingleVowel(char vowel)
    {
        string finalVol = "";
        finalVol += vowel;
        return finalVol;
    }
