#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    float positive(0), negative(0), zero(0);
    if (cin >> N) {
        for (int i = 0; i < N; ++i) {
            int value;
            if (cin >> value) {
                if (value > 0) {
                    ++positive;
                } else if (value < 0) {
                    ++negative;
                } else {
                    ++zero;
                }
            }
        }

        std::cout.setf( std::ios::fixed, std:: ios::floatfield );
        cout.precision(3);
        cout << positive / N << endl
             << negative / N << endl
             << zero / N << endl;
    }
    return 0;
}
