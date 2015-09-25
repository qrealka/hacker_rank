#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

int main()
{
    ostringstream output;
    int t;
    cin >> t;

    while(t--)
    {
        int N;
        if (cin >> N) {
            vector<int> v;
            copy_n(istream_iterator<int>(cin), N, back_inserter(v));
            bool result = v.size() == 1;

            if (v.size() > 2) {
                for (int left = 0, right = v.size()-1, sumLeft = v[0], sumRight = v[v.size()-1]; left < right; ) {
                    const auto delta = right - left;
                    if (delta <= 2) {
                        result = sumLeft == sumRight && delta == 2;
                        break;
                    }

                    if (sumLeft < sumRight) {
                        sumLeft += v[++left];
                    } else if (sumLeft > sumRight){
                        sumRight += v[--right];
                    } else {
                        if (v[left+1] < v[right-1]) {
                            sumLeft += v[++left];
                        } else if (v[left+1] > v[right-1]) {
                            sumRight += v[--right];
                        } else {
                            if (delta > 3) {
                                sumLeft += v[++left];
                                sumRight += v[--right];
                            } else if (delta == 3) {
                                sumLeft += v[++left];
                            }
                        }
                    }
                }
            }
            output << (result ? "YES" : "NO") << endl;
        }
    }
    cout << output.str();

    return 0;
}
