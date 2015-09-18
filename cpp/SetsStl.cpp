#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N;

    if (cin >> N) {
        set<int> s;
        ostringstream output;
        for (int i = 0; i < N; ++i) {
            int type, value;
            if (cin >> type >> value) {
                switch (type) {
                    case 1:
                        s.insert(value);
                        break;
                    case 2:
                        s.erase(value);
                        break;
                    case 3:
                        const auto it = s.find(value);
                        output << (it == s.end() ? "No" : "Yes") << endl;
                        break;
                }
            }
        }
        cout << output.str();
    }

    return 0;
}
