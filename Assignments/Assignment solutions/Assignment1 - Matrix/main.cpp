#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "matrix.h"

using namespace matrix;
using namespace std;

// "Interface" function declarations
void Interface();
void main_menu(string input, vector<string> airports, Matrix flights);

// "Logic" function declarations
Matrix count_connecting_flights(string source, string dest, string max_connect, Matrix flights, vector<string> airports);
bool check_airport_exist(string airport, vector<string> airports);
Matrix istream_to_matrix( istream &in , vector<string> &airports );


int main(int argc, char *argv[])
{
    // One command line argument needs to be specified
    if(argc == 2)
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
        // Program terminates without a valid file
        else
        {
            // No access to file = program terminates
            cout << "Unable to access flight information provided" << endl;
            cout << "Program TERMINATING" << endl;
        }
        // Closes file if it's open
        if(flight_info.is_open())
        {
            flight_info.close();
        }
    }
    // If user provides an optional second argument
    // adjacency matrix is outputted to file
    else if(argc == 3)
    {
        // Read in flight information from file
        string line;
        ifstream flight_info(argv[1]);
        // Action taken if flight information can be accessed
        if (flight_info.is_open())
        {
            vector<string> airports;
            Matrix flights = istream_to_matrix(flight_info, airports);
            cout << "Adjacency matrix outputted to specified file" << endl;

        }
        else
        {
            // No access to file = program terminates
            cout << "Unable to access flight information provided" << endl;
            cout << "Program TERMINATING" << endl;
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

    // Gets integer value from each value in matrix
    // Pushes it in vector
    while ( getline(in, input) ) {
        istringstream iss(input);
        string s1;
        while ( getline( iss, s1, ' ' ) ) {
            int input = atoi(s1.c_str());
            tmp.push_back(input);
        }
    }

    // Then pushes from vector to matrix
    int k = 0;
    for(unsigned int i = 0; i < airports.size(); i++)
    {
        for(unsigned int j = 0; j < airports.size(); j++)
        {
            flights(i,j) = tmp[k];
            k++;
        }
    }

    // returns matrix
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
Matrix count_connecting_flights(string source, string dest, string max_connect, Matrix flights, vector<string> airports)
{
    // Casts command line argument to integer
    // If not an integer, cast is computed as 0
    int max_conn;
    max_conn = atoi(max_connect.c_str());

    // Finding indexes of source and destination airports
    // To later read from result matrix
    int source_idx, dest_idx;
    for(unsigned int i = 0; i < airports.size(); i++)
    {
        if(airports[i] == source){source_idx = i; }
        if(airports[i] == dest){dest_idx = i; }
    }

    // Calculating result matrix based on max_conn value
    // temp_matrix calculates the multiplication
    // results calculates addition accordingly
    Matrix result = flights;
    Matrix temp_matrix = flights;
	for (int i = 0; i < max_conn; i++) {
        for (int j = i; j < max_conn; j++) {
            temp_matrix = temp_matrix * flights;
        }
        result += temp_matrix;
        temp_matrix = flights;
    }

    // Displaying result
    cout << result(source_idx, dest_idx) << " results found" << endl << endl;
    cout << "From airport: " << source << endl;
    cout << "To airport: " << dest << endl;
    cout << "Maximum connecting flights: " << max_conn << endl;
    cout << endl;

    // Returns result matrix
    return result;
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

            // Airport names need to exists in file to check flights
            // If they do actions are taken
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

    // Outputs this beautiful farewell message if user wants to quit
    cout << "M'kay, bye bye then :-(" << endl;
}
