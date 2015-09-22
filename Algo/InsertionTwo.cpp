#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename Iterator>
void insertIntoSort(Iterator begin, Iterator end, Iterator from) {
    const auto value = *from;

    for (; from != begin; from = end--) {
        if (*end > value) {
            iter_swap(from, end);
        } else {
            *from = value;
            break;
        }
        if (end == begin)
            break;
    }
}

void insertionSort(vector<int>&  ar)
{
    if (ar.size() < 2)
        return;

    for (auto it = next(ar.begin()), begin = ar.begin(), end = ar.end(); it != end; ++it) {
        insertIntoSort(begin, prev(it), it);
        copy(begin, end, ostream_iterator<int>(cout, " "));
        cout << endl;
    }
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
