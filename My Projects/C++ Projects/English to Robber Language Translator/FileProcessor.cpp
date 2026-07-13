/* Assignment or exercise number: PA1 - Robber Language Translation */

#include <fstream>
#include "Translator.h"
#include "FileProcessor.h"

    FileProcessor::FileProcessor(){} // default constructor
    FileProcessor::~FileProcessor(){} //default destructor

    // takes two strings (English File and Rövarspråket File) as the input and returns void
    // The method produces a html file that has the original English text in bold followed by an empty line, followed by the Rövarspråket translation in italics.
    void FileProcessor::processFile(string englishFileTxt, string rovarsprakeFileHtml) 
    {
        ifstream inputFile;
        inputFile.open(englishFileTxt);
        string englishSentence;

        string html = "";
        ofstream outputFile;
        outputFile.open(rovarsprakeFileHtml);

        while (getline(inputFile, englishSentence))
        {
            Translator translator;
            string robberSentence;
            robberSentence = translator.translateEnglishSentence(englishSentence);

            html = createHtml(englishSentence, robberSentence);
            html += "\n";
            outputFile << html;

        }
        inputFile.close();
        outputFile.close();
    }

    string FileProcessor::createHtml(string englishSentence, string robberSentence)
    {
        string message;
        englishSentence += "\n";
        message = "<html> <head> </head> <body> <b> <br>" + englishSentence + "\r</b> <br>" + "<i> " + robberSentence + "</i> </body> </html>";
        return message;
    }
