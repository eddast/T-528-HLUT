#include <iostream>
#include <fstream> //ifstream, to read from a file.
#include <sstream> //stringstream, e.g. for processing lines of text
#include <string>
#include <algorithm>

using namespace std;

// Only declarations, functions implemented below
int countWords( istream& is ); // a
int countChars( istream& is ); // b
int countLines( istream& is ); // c
int countWordsInLongestLine( istream& in ); // d
void countCharsWordsLines( istream& is,
 int& countChars, int& countWords, int& countLines); // e


int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        // Interpreting argument as file and read it in
        ifstream ifs( argv[1] );
        //ifstream ifi( argv[1] );

        // Check if opening file was successful
        if ( ifs.is_open() )
        {
            //File chosen as input via command line argument


            // a. Test word count : WORKS

            /* int word_count = countWords(ifs);
             * cout << "Your file has " << word_count << " words" << endl;
             */


             // b. Test character count : WORKS

            /* int char_count = countChars(ifs);
             * cout << "Your file has " << char_count << " chars" << endl;
             */

             // c. Test line count : WORKS

            /* int line_count = countLines(ifs);
             * cout << "Your file has " << line_count << " lines" << endl;
             */

             // d. Test longest line word count : WORKS

            /* int longest_line_word_count = countWordsInLongestLine(ifs);
             * cout << "Longest line in file has " << longest_line_word_count << " words" << endl;
             */

             // e. Testing chars, words and lines count : WORKS

             int countChars, countWords, countLines;
             countChars = countWords = countLines = 0;
             countCharsWordsLines(ifs, countChars, countWords, countLines);


            // Finally close file after use
            ifs.close();
        }
        else
        {
            // If opening file was unsuccessful, display proper error message from cerr
            cerr << "File unavailable or could not be opened. Program terminating." << endl;
        }
    }
    else
    {
        // No command line argument chosen:
        // Program assumes text file or string is directed as input by command line

        // a. Test word count : WORKS

        /* int word_count = countWords(cin);
         * cout << "Your input has " << word_count << " words" << endl;
         */


        // b. Test character count : WORKS

        /* int char_count = countChars(cin);
         * cout << "Your input has " << char_count << " chars" << endl;
         */

        // c. Test line count : WORKS

        /* int line_count = countLines(cin);
         * cout << "Your input has " << line_count << " lines" << endl;
         */

        // d. Test longest line word count : WORKS

        /* int longest_line_word_count = countWordsInLongestLine(cin);
         * cout << "Longest line in input has " << longest_line_word_count << " words" << endl;
         */

        // e. Testing chars, words and line count

        int countChars, countWords, countLines;
        countChars = countWords = countLines = 0;
        countCharsWordsLines(cin, countChars, countWords, countLines);
    }
}

int countWords( istream &is )
{
    // Initializes word_count as 0
    // Create a string
    int word_count = 0;
    string word;

    // While word is put into string space is a separator
    // So count is increased every time a word is put into string
    while ( is >> word ) {
        ++word_count;
    }

    // Finally count is returned
    // As the number of words in istream
    return word_count;
}

int countChars( istream& is )
{
    // Initialize char counter as zero
    // Create a char as a char placeholder
    int char_count = 0;
    char ch;

    // "Pumping" in char, char by char via get
    // Also counts white spaces though
    // Increase character count by every char
    while ( is.get(ch) ) {
        ++char_count;
    }

    // Finally return character counter
    // As number of characters
    return char_count;
}

int countLines( istream& is )
{
    // Initialize line counter
    // Creating empty string as line placeholder
    int line_count = 0;
    string line;

    // "Pumping" in line string, line by line via getline
    // Increasing line count by every line
    while ( getline( is, line ) ) {
        ++line_count;
    }

    // Finally return line count
    return line_count;
}

int countWordsInLongestLine( istream& in )
{
    // Initializing variables for longest line and current line
    // Set to zero
    int longest_line, current_line;
    longest_line = current_line = 0;

    // Bool value set to true to evaluate white space processing
    // Initially true so that our parser catches the first word in text
    bool processingWhiteSpaces = true;

    // Iterate through text character by character
    // Detecting weather word is a word or a newline
    char ch;
    while ( in.get( ch ) ) {

        // If white space is encountered, we evaluate our bool value to true
        if ( iswspace( ch ) ) {
            processingWhiteSpaces = true;
        }

        // Every time our bool value is evaluated to true, we set the value to false
        // And raise words, as this means we have now encountered a new word
        // And "parsed" it correctly
        else if ( processingWhiteSpaces ) {
            processingWhiteSpaces = false;
            ++current_line;
        }
        // Lastly, if we encounter a newline, current line is raised
        // And set to longest line if it has more words
        // Lastly, current line is set back to zero for next line
        if ( ch =='\n' ) {
            if(current_line > longest_line){
                longest_line = current_line;
            }
            current_line = 0;
        }
    }
    return longest_line;
}

// "Parser" of words, lines and characters
void countCharsWordsLines( istream& is,
int& countChars, int& countWords, int& countLines)
{
    // Bool value set to true to evaluate white space processing
    // Initially true so that our parser catches the first word in text
    bool processingWhiteSpaces = true;

    // Iterate through file, char by char
    char ch;
    while ( is.get( ch ) ) {
        // Every character iterate through, the character counter is raised
        ++countChars;

        // If white space is encountered, we evaluate our bool value to true
        if ( iswspace( ch ) ) {
            processingWhiteSpaces = true;
        }

        // Every time our bool value is evaluated to true, we set the value to false
        // And raise words, as this means we have now encountered a new word
        // And "parsed" it correctly
        else if ( processingWhiteSpaces ) {
            processingWhiteSpaces = false;
            ++countWords;
        }

        // Lastly, if we encounter a newline, line count is raised
        // As that obviously means a new line was encountered
        if ( ch =='\n' ) { ++countLines; }
    }

    // Displaying results of the parser given the istream parameter
    cout << countLines << "\t" << countWords << "\t" << countChars << endl;
}
