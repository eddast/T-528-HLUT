#include "toh.h"

/*
 * @param: pegs are number of pegs, disks are number of disks
 *  loc is desired peg to place disks on (in numbers)
 *  default value of loc is 0, indicating leftmost peg
 */
toh::toh( int peg_, int disks_, int loc_ ){
    // Initializing number of disks and pegs
    peg = peg_;
    disks = disks_;
    moves = 0;

    // Checks if loc is valid
    check_peg_validity(loc_);

    // Initializing an empty int vector
    vector<int> v;

    // Filling spots of pegs with the empty vector
    for(int i = 0; i < peg; i++)
    {
        pegs_.push_back(v);
    }

    // Pushes disks onto peg location loc
    // Higher integer disk = larger disk
    for(int i = disks; i > 0; i--){
        pegs_[loc_].push_back(i);
    }
}

toh::~toh(){
    // Deliberately empty
    // Nothing to "destruct"
}

/* @returns: number of pegs in puzzle
 * stored in pegs variable
 */
 int toh::get_num_pegs(){
     return peg;
 }

 /* @param: specified peg in puzzle
  * @returns: value of topmost disk on peg,
  * @returns: NO_DISKS if no disc is on peg
  */
int	toh::get_topmost_disk( int peg ){
    if(pegs_[peg].size() == 0){
        return NO_DISKS;
    }
    else{
        return pegs_[peg][0];
    }
}

/* @param: peg_from is peg to move disc from, peg_to is peg to move disk to
 *  moves top-most disk from peg_from to peg_to
 *  peg parameter values need to be within range
 *  disk needs to be on source peg, if not method should assert
 */
void toh::move( int peg_from, int peg_to ){
    // Checks validity of user-inputted pegs
    // Should assert if peg is not valid
    check_peg_validity(peg_from);
    check_peg_validity(peg_to);

    // Gets value of the topmost disk
    // No action if peg_from has no discs
    // otherwise function continues
    int topmost = get_topmost_disk(peg_from);
    if(topmost != NO_DISKS)
    {
        //pops topmost disk off the source peg's vector's front
        pegs_[peg_from].erase(pegs_[peg_from].begin());

        // Then pushes the value onto desired peg in front
        pegs_[peg_to].insert(pegs_[peg_to].begin(), topmost);
    }

}

/* Checks validity of peg inputted by user
 * Asserts if invalid peg is taken in
 */
void toh::check_peg_validity(int peg_){
    assert(peg_ < peg && peg_ >= 0);
}

/* @returns: true if left peg and right peg have
 * same number of pegs with identical disk arrangement
 */
bool operator ==(toh &lp, toh &rr){
    if(lp.peg == rr.peg){
        for(int i = 0; i < lp.peg; i++){
            if(lp.pegs_[i] != rr.pegs_[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

/* @returns: ostream after outputting puzzle peg by peg
 * Output format is as follows: [ 6 5 4 3 2 1 0 ] [ ] [ ]
 */
ostream& operator <<(ostream& out, toh &t){
    for(int i = 0; i < t.peg; i++)
    {
        out << "[ ";
        for(unsigned int j = 0; j < t.pegs_[i].size(); j++)
        {
            out << t.pegs_[i][j] << " ";
        }
        out << "] ";
    }
    return out;
}


// Comments/explanations adapted from Wikipedia site (https://en.wikipedia.org/wiki/Tower_of_Hanoi)
int toh::solve_puzzle(int disks, int peg_source, int peg_destination, int peg_spare)
{
    // Peg needs to be three, or puzzle is not valid
    if(peg == 3){
        // Base case: 0 disks = do nothing and return number of moves
        if(disks > 0){
            // Move m-1 disks from source to space - rules not violated
            // m is then top of source peg
            solve_puzzle(disks - 1, peg_source, peg_spare, peg_destination);

            // Move the disk m from the source to the target peg.
            // Obviously a valid move
            move(peg_source, peg_destination);

            // For every recursive call move is made, so for
            // every recursive call moves are raised
            moves++;

            // Move the m − 1 disks on the spare peg to target peg by
            // So they are placed on top of the disk m
            solve_puzzle(disks - 1, peg_spare, peg_destination, peg_source);
        }

        // returns moves variable after altering it according to
        // number of moves used in program
        return moves;
    }
    else{
        cout << "Pegs are not exactly three, they need to be to solve the puzzle" << endl;
        // Return -1 as an "error"
        return -1;
    }
}



