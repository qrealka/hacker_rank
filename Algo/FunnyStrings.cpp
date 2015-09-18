#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

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

        for (auto&& s : v) {
            auto normal_it1 = s.cbegin();
            auto normal_it2 = next(normal_it1);
            auto reverse_it1 = s.crbegin();
            auto reverse_it2 = next(reverse_it1);

            string result = "Funny";
            for (const auto end = s.cend();
                 normal_it1 != end && normal_it2 != end;
                 normal_it1 = normal_it2++, reverse_it1 = reverse_it2++)
            {
                if (abs(*normal_it2 - *normal_it1) != abs(*reverse_it2 - *reverse_it1)) {
                    result = "Not Funny";
                    break;
                }
            }
            cout << result << endl;
        }
    }
    return 0;
}
