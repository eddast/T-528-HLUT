#ifndef TOH_H
#define TOH_H
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class toh
{
    public:
        // Constructors/destructors
        toh(int peg_, int disks_, int loc_ = 0);
        virtual ~toh();

        // Gets values of pegs and disks
        int get_num_pegs();
        int get_topmost_disk(int peg);

        // Moves topmost disk from peg to peg
        void move( int peg_from, int peg_to );

        // Solves puzzle of towers of Hanoi
        int solve_puzzle(int disks, int peg_source, int peg_destination, int peg_spare);

        // Overloaded operators
        friend bool operator ==(toh &lp, toh &rr);
        friend ostream& operator <<(ostream& out, toh &t);

    private:
        // Initializers
        int peg;
        int disks;

        // Variable for Hanoi puzzle
        int moves;

        // Pegs of disks
        vector<vector<int> > pegs_;

        // Const indicating no disks
        const int NO_DISKS = -1;

        // Private helper functions
        void check_peg_validity(int peg_);

};

#endif // TOH_H
