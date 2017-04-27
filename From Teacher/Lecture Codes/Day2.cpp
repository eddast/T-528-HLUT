#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class BigData {
public:
    BigData( size_t n ) : data_( n ) {
    }
private:
    vector<int> data_;
};

int dfs( int depth, const BigData& bd )
{
    if ( depth == 0 ) {
        return 1;
    }
    int count = 0;
    for ( int b = 0; b < 2; b++ ) {
        count += dfs( depth - 1, bd );
    }
    return count;
}

int id_dfs( int depth, const BigData& bd )
{
    int count = 0;
    for ( int d = 1; d <= depth; ++d ) {
        count += dfs( d, bd );
    }
    return count;
}

int main() {

    BigData bd(1000);

    chrono::time_point<chrono::steady_clock> start, end;
    chrono::duration<double> diff;

    start = chrono::steady_clock::now();
    int count = id_dfs( 20, bd );
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << count << endl;
    cout << chrono::duration<double,milli>(diff).count() << "ms.\n";

    return 0;
}