#include <iostream>
using namespace std;

int height(int n) {
    int result = 1;

    for (bool spring = false; n; --n) {
        result += spring ? 1 : result;
        spring = !spring;
    }

    return result;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
