#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct X
{
    explicit X(int) {}
};

bool foo(const X&, bool)
{ return false; }

bool foo(int)
{ return true; }


int main() {
    cout << "Hello, World!" << endl;

    std::vector<int> v;

    // uresolved overloaded function
    //std::find_if(v.begin(), v.end(), foo);
    return 0;
}