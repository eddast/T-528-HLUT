#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int example_warning() {
  std::vector<int> data;
  data.push_back(10);
  data.push_back(5);

  for ( int d : data ) { // C++11
    std::cout << d << std::endl;
  }
  for ( int i=0; i<data.size(); ++i ) {
    if ( data[i] == 5 ) {
      std::cout << "Bingo!" << std::endl;
    }
  }
  std::cout << "Hello, World!" << std::endl;
  return 0;
}

//
// This program prints out its
// command-line arguments.
//
int command_line_arguments( int argc, char *argv[] )
{
  std::cout << "Arguments:\n";
  for ( int i = 0; i < argc; ++i ) {
    std::cout << ' ' << argv[i] << std::endl;
  }
  return 0;
}

//
// This program reads in text from
// standard input and prints out the
// inputted 'words’, one per line.
//
int read_cin( )
{
  string word;
  while ( cin >> word ) {
    cout << "  '" << word << "'\n";
  }
  return 0;
}

int countWords( istream& in ) {
  int count = 0;
  string word;
  while ( in >> word ) {
    ++count;
  }
  return count;
}

int main( int argc, char *argv[] ) {
  int count = 0;
  if ( argc > 1 ) {
    ifstream ifs( argv[1] );
    if ( ifs.is_open() ) {
      count = countWords( ifs );
      ifs.close();
    }
  }
  else { count = countWords( cin ); }
  cout << count << '\n';
}
