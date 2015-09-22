#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int N;
    if (cin >> N) {
        vector<string> v;
        for (int i = 0; i < N; ++i) {
            string s;
            if (cin >> s) {
                v.push_back(s);
            }
        }

        for (auto s : v) {
            if (next_permutation(begin(s), end(s))) {
                cout << s << endl;
            } else {
                cout << "no answer" << endl;
            }
        }
    }
    return 0;
}
