// Lab 06: Generic programming
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

// Gets random tiles from alphabet
list<char> getRandomTiles( int numTiles, int rseed )
{
    static string alphabet( "abcdefghijklmnopqrstuvwxyz" );

    mt19937 gen( static_cast<unsigned int>( rseed ) );
    std::uniform_int_distribution<> dist(0, static_cast<int>(alphabet.size())-1);

    list<char> tiles;
    for ( int i=0; i<numTiles; ++i ) {
        const size_t rnum = static_cast<size_t>(dist(gen));
        tiles.push_back( alphabet.at( rnum ) );
    }
    return tiles;
}

// Read dictionary in from file.
void readDictionary( string fileName, set<string>& dict )
{
    // Defines ifstream from file name string provided
    // Then reads from file word by word
    // and places words in dictionary set
    ifstream dictionary (fileName);
    string word = "";
    if (dictionary.is_open()){
        while (getline(dictionary, word)){
            dict.insert(word);
        }
    }
    else
    {
        // Program terminates if file is invalid
        cout << "Could not open provided word bank" << endl;
        cout << "Program TERMINATING!" << endl;
        exit(1);
    }
}

// Returns true if word is legitimately constructed from the tiles, otherwise false.
bool legitimate( string word, list<char> tiles )
{
    // Iterates through word. If character is found
    // function carries on and erases character from tile
    // (to avoid interpreting duplicates from tiles)
    // otherwise returns false
    list<char>::iterator find_it;
    for(unsigned int i = 0; i < word.size(); i++)
    {
        find_it = find(tiles.begin(), tiles.end(), word[i]);
        if(find_it == tiles.end())
        {
            return false;
        }
        tiles.erase(find_it);
    }

    return true;
}

// Returns true if word is found in dictionary, else false
bool in_dictionary( const string& word, const set<string>& dictionary )
{
    return find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

int main(int argc, char** argv)
{
    // Setting random seed
    // Setting dictionary file
    int rseed = 0;
    if(argc > 1)
        rseed = atoi(argv[1]);
    string dictionaryFile = "./dictionary.txt";
    if(argc > 2)
		dictionaryFile = argv[2];

    // Interface starts, read words into set from
    // dictionary provided
	cout << "Welcome to word-puzzle!\n";
	cout << "Reading dictionary ... ";
	set<string> dictionary;
	readDictionary( dictionaryFile, dictionary );
	cout << "size = " << dictionary.size() << '\n';

	// Setting tiles for user
	cout << "Number of tiles to use: ";
	int numTiles = 0;
	cin >> numTiles;
	list<char> tiles = getRandomTiles( numTiles, rseed );
	cout << "Tiles:  ";
	tiles.sort();
	for(auto ch : tiles)
    {
        cout << ch << " ";
    }
	cout << '\n';

	// Set of correct words and map of inputted words
	// Map stores word and number of attempts per word
	set<string> correctWords;
	map<string, int> inputtedWords;
	int score = 0;
	string word;
	cout << "Enter word ('*' to exit): ";
    while ( cin >> word ) {
        if ( word == "*" ) break;
        cout << word << '\n';

        // If word is legitimately constructed from tiles
        // Program goes on to analyze if it exists in dictionary
        if(legitimate(word, tiles))
        {
            // If word has already been inputted
            if(inputtedWords.find(word) != inputtedWords.end())
            {
                // user gets "already found" feedback if word was in dictionary
                // otherwise no feedback (according to Mooshak at least)
                if(in_dictionary(word, dictionary))
                {
                    cout << "Word already found." << endl;
                }

                // Attempts in map are increased by one
                // per new attempt for word
                map<string, int>::iterator el = inputtedWords.find(word);
                el->second++;
            }

            // If word is in dictionary and legitimate
            // Score is increased and word is added to correct words
            else if( in_dictionary(word, dictionary) )
            {
                score++;
                cout << "Good job! Score = " << score << endl;
                correctWords.insert(word);

                // Word added to inputted words
                pair<string, int> word_attempt(word, 1);
                inputtedWords.insert(word_attempt);
            }

            // Otherwise if word is legit but not in dictionary
            // User gets alerted that word is not in word bank
            else
            {
                cout << "Word not found in dictionary." << endl;

                // Word added to inputted words
                pair<string, int> word_attempt(word, 1);
                inputtedWords.insert(word_attempt);
            }
        }

        // If word is not legitimate, user is alerted
        // Word checked for in inputted words map
        else
        {
            cout << "Word not legitimately constructed from tiles." << endl;

            // If entry already exists in inputted words, attempts are increased
            if(inputtedWords.find(word) != inputtedWords.end())
            {
                map<string, int>::iterator el = inputtedWords.find(word);
                el->second++;
            }
            // Otherwise entry is added in inputted words
            else
            {
                pair<string, int> word_attempt(word, 1);
                inputtedWords.insert(word_attempt);
            }
        }
		cout << "Enter word ('*' to exit): ";
	}

	// Displaying results of game and score
	cout << "\nWords found:\n";
    for(auto el : correctWords)
    {
        cout << "\t" << el << endl;
    }
    cout << "Final score = " << score << endl;
	cout << "\nList of attempts:\n";
    for(auto el : inputtedWords)
    {
        cout << "\t" << get<0>(el) << ":" << get<1>(el) << endl;
    }
}
