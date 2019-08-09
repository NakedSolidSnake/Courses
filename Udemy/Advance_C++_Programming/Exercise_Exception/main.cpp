#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream file;
  char c;

  file.exceptions(ifstream::failbit | ifstream::badbit);

  try{
    file.open("file.txt");

    while(!file.eof()){
      file.get(c);
      cout << c; 
    }
    cout << endl;
  }
  catch(ifstream::failure &e){
    cerr << e.what() << endl;
    return 1;
  }

  file.close();
  return 0;
}
