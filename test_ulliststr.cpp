#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;

int main(int argc, char* argv[])
{
    ULListStr dat;
    dat.push_back("A");
    dat.push_front("B");
    dat.push_back("C");
    cout << dat.size() << endl;
    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
    dat.pop_back();
    cout << dat.size() << endl;
    cout << dat.get(0) << " " << dat.get(1) << endl;
    dat.pop_front();
    cout << dat.size() << endl;
    cout << dat.get(0) << endl;
    dat.pop_front();
    cout << dat.size() << endl;
    dat.push_back("D");
    dat.push_back("E");
    dat.push_back("F");
    dat.push_back("G");
    dat.push_back("H");
    dat.pop_front();
    dat.pop_front();
    dat.push_front("Z");
    cout << dat.size() << endl;
    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << endl;
}
