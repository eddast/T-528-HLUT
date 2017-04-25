#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class BigData
{
    public:
        BigData (size_t n): data_( n ){}
    private:
        vector<int> data_;
};

int dfs_fast( int depth, const BigData& bd ){
    if( depth == 0 ){
        return 1;
    }
    int counter = 0;
    for( int b = 0; b < 2; b++ ){
        counter += dfs_fast( depth - 1, bd );
    }
    return counter;
}

int dfs_slow( int depth, const BigData bd ){
    if( depth == 0 ){
        return 1;
    }
    int counter = 0;
    for( int b = 0; b < 2; b++ ){
        counter += dfs_slow( depth - 1, bd );
    }
    return counter;
}

int main()
{
    BigData bd(10);

    // Only available in C++11:

    cout << "Executing dfs_fast..." << endl;

    chrono::time_point<chrono::steady_clock> start, end;
    chrono::duration<double> diff;
    start = chrono::steady_clock::now();

    int count = dfs_fast( 20, bd );
    cout << "count: " << count << endl;

    end = chrono::steady_clock::now();
    diff = end - start;

    cout << "Operation took: " << chrono::duration<double, milli>(diff).count() << "ms" << endl << endl;

    cout << "Executing dfs_slow..." << endl;

    chrono::time_point<chrono::steady_clock> startt, endd;
    chrono::duration<double> difff;
    startt = chrono::steady_clock::now();

    int countt = dfs_slow( 20, bd );
    cout << "count: " << countt << endl;

    endd = chrono::steady_clock::now();
    difff = endd - startt;

    cout << "Operation took: " << chrono::duration<double, milli>(difff).count() << "ms" << endl;

    return 0;
}
