#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "matrix.h"

using namespace matrix;
using namespace std;

// Function declarations: implementation below

// "Interface"
void Interface();
void main_menu(string input, vector<string> airports, Matrix flights);

// "Logic"
void count_connecting_flights(string source, string dest, string max_connect, Matrix flights, vector<string> airports);
bool check_airport_exist(string airport, vector<string> airports);
Matrix istream_to_matrix( istream &in , vector<string> &airports );



int main(int argc, char *argv[])
{
    // One command line argument needs to be specified
    if(argc > 1)
    {
        // Read in flight information from file
        string line;
        ifstream flight_info(argv[1]);
        // Action taken if flight information can be accessed
        if (flight_info.is_open())
        {
            vector<string> airports;
            Matrix flights = istream_to_matrix(flight_info, airports);

            // Displays initial menu
            Interface();

            // Gets initial input
            string input;
            cout << "> ";
            getline(cin, input);

            // Loops functionality of program
            main_menu(input, airports, flights);
        }
        else
        {
            // No access to file = program terminates
            cout << "Unable to access flight information" << endl;
            cout << "Program TERMINATING" << endl;
        }
        // Closes file if it's open
        if(flight_info.is_open())
        {
            flight_info.close();
        }
    }
    else
    {
        // Program terminates if no command line is specified
        cout << "Command line argument must be specified!" << endl;
        cout << "Program TERMINATING" << endl;
    }

    return 0;
}

Matrix istream_to_matrix( istream &in , vector<string> &airports )
{
    // Create a string of airports
    vector<int> tmp;
    string airports_;
    string matrix_elements;

    // Gets airport names from first line
    if (getline(in, airports_))
    {
        istringstream iss(airports_);
        string s;
        while ( getline( iss, s, ' ' ) ) {
            airports.push_back(s);
        }
    }

    // Creates the matrix from the rest
    Matrix flights(airports.size(), airports.size());

    // Create a char as a char placeholder
    string input;

    while ( getline(in, input) ) {
        istringstream iss(input);
        string s1;
        while ( getline( iss, s1, ' ' ) ) {
            int input = atoi(s1.c_str());
            tmp.push_back(input);
        }
    }
    int k = 0;
    for(unsigned int i = 0; i < airports.size(); i++)
    {
        for(unsigned int j = 0; j < airports.size(); j++)
        {
            flights(i,j) = tmp[k];
            k++;
        }
    }

    return flights;
}

// Initial menu interface
void Interface()
{
    cout << "-----------------------------------------------" << endl;
    cout << "\tWelcome to the Matrix AirPlanner!" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Enter source and destination airports" << endl;
    cout << "and maximum number of connection flights." << endl;
    cout << "Type 'quit' to exit the program." << endl << endl;
}

// Counts number of connecting flights
void count_connecting_flights(string source, string dest, string max_connect, Matrix flights, vector<string> airports)
{
    int max_conn;
    max_conn = atoi(max_connect.c_str());

    int source_idx;
    int dest_idx;

    for(unsigned int i = 0; i < airports.size(); i++)
    {
        if(airports[i] == source)
        {
            source_idx = i;
        }
        if(airports[i] == dest)
        {
            dest_idx = i;
        }
    }

    cout << flights << endl;
    cout << "reading (" << source_idx << "," << dest_idx << ")" << endl;
    cout << flights(source_idx, dest_idx) << " results found" << endl << endl;
    cout << "From airport: " << source << endl;
    cout << "To airport: " << dest << endl;
    cout << "With a max " << max_conn << " connecting flights" << endl;
    cout << endl;
}

// Checks if airport specified exists
bool check_airport_exist(string airport, vector<string> airports)
{
    for(unsigned int i = 0; i < airports.size(); i++)
    {
        if(airports[i] == airport)
        {
            return true;
        }
    }
    return false;
}

// Loops through functionality of program
void main_menu(string input, vector<string> airports, Matrix flights)
{
    while(input != "quit" && input != "Quit" && input != "QUIT")
    {
        vector<string> input_args;
        string tmp;
        stringstream inp(input);

        while (inp >> tmp)
        {
            input_args.push_back(tmp);
        }

        // Arguments need to be exactly three to count flights
        if(input_args.size() == 3)
        {
            cout << endl;

            // Airport names need to exists to check flights
            if(check_airport_exist(input_args[0], airports) && check_airport_exist(input_args[1], airports))
            {
                count_connecting_flights(input_args[0], input_args[1], input_args[2], flights, airports);
            }
            else
            {
                cout << "Airport name/s not found" << endl << endl;
            }
        }
        // Arguments need to be exactly three
        // Otherwise user is asked to input again
        else
        {
            cout << "One or more argument/s missing! Try again:" << endl << endl;
        }

        // Next input for next loop
        cout << "> ";
        getline(cin, input);
    }

    // Outputs if user wants to quit program
    cout << "M'kay, bye bye then :-(" << endl;
}
