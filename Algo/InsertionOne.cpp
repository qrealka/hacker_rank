#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void insertionSort(vector<int>&  ar)
{
    if (ar.size() < 2)
        return;

    auto it = ar.rbegin();
    const auto value = *it;

    for (auto nxt = next(it); it != ar.rend(); it = nxt++) {
        if (*nxt > value) {
            *it = *nxt;
            copy(ar.cbegin(), ar.cend(), ostream_iterator<int>(cout, " "));
            cout << endl;
        } else {
            *it = value;
            break;
        }
        if (nxt == ar.rend())
            break;
    }
    copy(ar.cbegin(), ar.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main(void)
{
    int _ar_size;
    cin >> _ar_size;

    vector <int>  _ar;
    for(int _ar_i=0; _ar_i<_ar_size; ++_ar_i) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    insertionSort(_ar);

    return 0;
}
