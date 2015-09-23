#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int V, N;
    if (cin >> V >> N) {
        vector<int> v;
        int item, index = -1;
        for (int i = 0; i < N; ++i) {
            if (cin >> item) {
                v.push_back(item);
                if (item == V) index = i;
            }
        }

        /*const auto it = lower_bound(v.cbegin(), v.cend(), V);
        if (it != v.cend() && *it == V) {
            cout << it - v.cbegin() << endl;
        }*/
        cout << index << endl;
    }
    return 0;
}
