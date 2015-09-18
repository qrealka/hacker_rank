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
        istringstream input(line);
        vector<int> v;
        copy_n(istream_iterator<int>(input), N, back_inserter(v));

        if (cin >> N) {
            ostringstream output;
            const auto begin = v.cbegin();
            const auto end = v.cend();
            for (int i = 0; i < N; ++i) {
                int value;
                if (cin >> value) {
                    const auto it = lower_bound(begin, end, value);
                    const auto index = it - begin;
                    if (*it == value) {
                        output << "Yes " << index + 1 << endl;
                    } else {
                        output << "No " << index + 1 << endl;
                    }
                }
            }
            cout << output.str();
        }
    } else {
        return -1;
    }

    return 0;
}
