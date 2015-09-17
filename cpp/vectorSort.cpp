#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip eol

    string line;
    getline(cin, line);

    if (cin) {
        istringstream ss(line);
        vector<int> v;
        copy_n(istream_iterator<int>(ss), N, back_inserter(v));
        sort(begin(v), end(v));
        copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    } else {
        return -1;
    }

    return 0;
}