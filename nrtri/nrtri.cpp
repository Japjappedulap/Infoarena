#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is("nrtri.in");
ofstream os("nrtri.out");

int n, x;
int cnt;
int sum;

vector<int> v;

int main()
{
    is >> n;
    for ( int i = 0; i < n; ++i )
    {
        is >> x;
        v.push_back(x);
    }
    int dr, st, m;
    sort(v.begin(), v.end());
    for ( int i = 0; i < n - 2; ++i )
        for ( int j = i + 1; j < n - 1; ++j )
        {
            sum = v[i] + v[j];
            dr = n-1;
            st = j+1;
            while (st < dr)
            {
                m = (st + dr) / 2;
                if (v[m] > sum)
                    dr = m-1;
                else
                    st = m+1;
            }
            if (sum >= v[dr]) dr++;
            cnt += dr - j - 1;
        }
    os << cnt;
    is.close();
    os.close();
    return 0;
}
