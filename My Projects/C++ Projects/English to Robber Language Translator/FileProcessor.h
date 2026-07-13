/* Assignment or exercise number: PA1 - Robber Language Translation */

#include <string>

using namespace std;

class FileProcessor
{
public:
    FileProcessor(); // default constructor
    virtual ~FileProcessor(); //default destructor

    // takes two strings (English File and Rövarspråket File) as the input and returns void
    // The method produces a html file that has the original English text in bold followed by an empty line, followed by the Rövarspråket translation in italics.
    void processFile(string englishFile, string rovarsprakeFile);

private:
    string createHtml(string englishSentence, string robberSentence);
};