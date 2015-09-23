#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
int main()
{
    ostringstream output;
    int t;
    cin >> t;

    while(t--)
    {
        unsigned int n;
        cin >> n;

        vector<int64_t> a(n);

        int64_t first(0), second(0), maximum(std::numeric_limits<int64_t>::max());

        for(unsigned int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] > maximum)
                maximum = a[i];
            if (!i)
                first = a[i];
            if (a[i] > 0)
                second += a[i];
        }

        if (!second)
            second = maximum;

        int64_t cur = 0;
        for(auto i : a)
        {
            cur += i;
            first = max(first, cur);
            if (cur < 0)
                cur = 0;
        }

        output << first << " " << second << endl;
    }
    cout << output.str();

    return 0;
}
