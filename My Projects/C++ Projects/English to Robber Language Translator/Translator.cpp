/* Assignment or exercise number: PA1 - Robber Language Translation */

#include "Model.h"
#include "Translator.h"
#include <sstream>

    Translator::Translator(){} // default constructor
    Translator::~Translator(){} //default destructor

    // takes a string (Single English Word) as the input and returns the Rövarspråket translated string
    string Translator::translateEnglishWord(string englishWord) 
    {
        string robberWord;
        Model model;
        int len = englishWord.length();
        for (int i = 0; i<len; ++i)
        {
            if (isalpha(englishWord[i]))
            {
                if (englishWord[i] == 'a'|| 
                    englishWord[i] == 'e'||
                    englishWord[i] == 'i'|| 
                    englishWord[i] == 'o'|| 
                    englishWord[i] == 'u'|| 
                    englishWord[i] == 'A'|| 
                    englishWord[i] == 'E'|| 
                    englishWord[i] == 'I'|| 
                    englishWord[i] == 'O'|| 
                    englishWord[i] == 'U') 
                {
                    robberWord += model.translateSingleVowel(englishWord[i]);
                } 
                else 
                {
                    robberWord += model.translateSingleConsonant(englishWord[i]) ;
                }
            }
            else 
            {
                robberWord += englishWord[i];
            }
        }

        return robberWord + " ";
    }

    // takes a string (Single English Sentence) as the input and returns the Rövarspråket translated string
    string Translator::translateEnglishSentence(string englishSentence) 
    {
        // int i = 0;
        // int j = 0;
        // string englishWord;
        string robberWord;
        string robberSentence;

        istringstream iSS(englishSentence);
        
        while ( iSS >> robberWord) {
            robberSentence += translateEnglishWord(robberWord);
        }

// Previous attempt without usage of istringstream

        // while(englishSentence[i] != NULL)
        // {
        //     while(englishSentence[j] != ' ' || englishSentence[j] != NULL)
        //     {
        //         j++;
        //     }
        //     englishWord = englishSentence.substr(i,j); 
        //     robberWord = translateEnglishWord(englishWord);

        //     robberSentence += robberWord;
        //     robberSentence += englishSentence[j];

        //     if (englishSentence[j]==NULL) 
        //         break;

        //     j++;
        //     i = j;
        // }

        return robberSentence;
    }

