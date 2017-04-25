#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    /* C++11, eini nýi control-structure-inn:
     * (Compile-ar ekki hér)
     * for(int d : data)
     * {
     *      cout << d << endl;
     * }
     */

     // Producing warnings
    vector<int> data;
    for(unsigned int i = 0; i < data.size(); i++)
    {
        if(data[i] = 5) // Produces warning
        {
            // Do something
        }
    }

    int i = 100;
    i = i / 2.5;
    i = static_cast<int>(i / 2.5); // Does NOT produce warning but should!
                                   // Due to inexplicit reference
                                   // (first casting to float, then back to int)


    // Reading input from a file
    cout << "Echoing from file..." << endl;
    ifstream ifs("input.txt.txt");
    if(ifs.is_open())
    {
        string word;
        while(ifs >> word)
        {
            cout << word << " ";
        }
        cout << endl << endl;
        ifs.close();
    }
    else
    {
        cout << "Could not open file" << endl;
    }

    // Reading input from a file
    cout << "Echoing from file as command line parameter..." << endl;
    ifstream ifs_arg(argv[1]);
    if(ifs_arg.is_open())
    {
        string word;
        while(ifs_arg >> word)
        {
            cout << word << " ";
        }
        cout << endl << endl;
        ifs_arg.close();
    }
    else
    {
        cout << "Could not open file" << endl << endl;
    }


    // Reading input from a string
    cout << "Input a sentence for program to echo: ";
    string sentence;
    while(cin >> sentence)
    {
        cout << sentence << " ";
    }

    return 0;


}
