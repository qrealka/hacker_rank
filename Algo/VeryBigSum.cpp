#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    int N;
    if (cin >> N) {
        vector<int32_t> v;
        copy_n(istream_iterator<int32_t>(cin), N, back_inserter(v));

        int64_t sum(0);
        sum = accumulate(begin(v), end(v), sum);

        cout << sum <<endl;
    }
    return 0;
}
