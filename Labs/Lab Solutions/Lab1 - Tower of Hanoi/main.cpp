#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include "toh.h"

using namespace std;

// Main takes in argument interpreted as number of disks
int main(int argc, char *argv[])
{
    // Argument needs to be exactly one
    if(argc == 2)
    {
        // Puzzle initialized with input argument as disks
        cout << "----- Initializing puzzle ----- " << endl;
        int disks = atoi(argv[1]);
        cout << "Disks specified: " << disks << endl;
        toh tower(3, disks);
        cout << "Initial tower: " << endl;
        cout << tower << endl << endl;

        // Solving puzzle and measuring it's time
        cout << "----- Solving puzzle ----- " << endl;
        chrono::time_point<chrono::steady_clock> start, end;
        chrono::duration<double> diff;
        start = chrono::steady_clock::now();
        int moves_ = tower.solve_puzzle(disks, 0, 2, 1);
        end = chrono::steady_clock::now();
        diff = end - start;

        // Tower solutions after solving puzzle
        cout << "Number of moves explored: " << moves_ << endl;
        cout << "Tower after solution: " << endl;
        cout << tower << endl;

        // Not much difference in my examples, but solve_puzzle function
        // has an exponential growth so as soon as disks are 20, there is
        // some visible time change. Everything over 25 disks runs extremely slow
        cout << "Time of operation in milliseconds: " << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    }
    else{
        // Program terminates due to invalid number of arguments
        // Lets user know why program terminated
        cout << "Program terminating due to invalid number of command-line arguments" << endl;
        cout << "Argument should be a single integer, indicating number of disks" << endl;
    }
}


