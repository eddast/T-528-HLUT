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

//
// Read dictionary in from file.
//
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
        cout << "Could not open provided word bank" << endl;
        cout << "Program TERMINATING!" << endl;
        exit(1);
    }
}

//
// Returns true if word is legitimately constructed from the tiles, otherwise false.
//
bool legitimate( string word, list<char> tiles )
{
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

bool in_dictionary( const string& word, const set<string>& dictionary )
{
    return find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

int main(int argc, char** argv)
{
    int rseed = 0;
    if(argc > 1)
        rseed = atoi(argv[1]);
    string dictionaryFile = "./dictionary.txt";
    if(argc > 2)
		dictionaryFile = argv[2];

	cout << "Welcome to word-puzzle!\n";
	cout << "Reading dictionary ... ";
	set<string> dictionary;
	readDictionary( dictionaryFile, dictionary );
	cout << "size = " << dictionary.size() << '\n';
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

	set<string> correctWords;
	map<string, int> inputtedWords;
	int score = 0;
	string word;
	cout << "Enter word ('*' to exit): ";
    while ( cin >> word ) {
        if ( word == "*" ) break;
        cout << word << '\n';
        if(inputtedWords.find(word) != inputtedWords.end())
        {
            if(legitimate(word, tiles))
            {
                cout << "Word already found." << endl;
            }
            map<string, int>::iterator el = inputtedWords.find(word);
            el->second++;
        }
        if(legitimate(word, tiles))
        {
            if( in_dictionary(word, dictionary) )
            {
                score++;
                cout << "Good job! Score = " << score << endl;
                correctWords.insert(word);
                pair<string, int> word_attempt(word, 1);
                inputtedWords.insert(word_attempt);
            }
            else
            {
                cout << "Word not found in dictionary." << endl;
                pair<string, int> word_attempt(word, 1);
                inputtedWords.insert(word_attempt);
            }
        }
        else
        {
            cout << "Word not legitimately constructed from tiles." << endl;
            pair<string, int> word_attempt(word, 1);
            inputtedWords.insert(word_attempt);
        }
		cout << "Enter word ('*' to exit): ";
	}
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
	//
	// ==> Implement, output correct words and attempts.
	//     Make sure that the output is formatted exactly as expected (see description).
    //
}