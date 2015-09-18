#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N;

    if (cin >> N) {
        map<string,int> s;
        ostringstream output;
        for (int i = 0; i < N; ++i) {
            string key;
            int type, value;
            if (cin >> type >> key) {
                switch (type) {
                    case 1:
                        if (cin >> value)
                            s[key] += value;
                        break;
                    case 2:
                        s.erase(key);
                        break;
                    case 3:
                        const auto it = s.find(key);
                        output << (it == s.end() ? 0 : it->second) << endl;
                        break;
                }
            }
        }
        cout << output.str();
    }

    return 0;
}
