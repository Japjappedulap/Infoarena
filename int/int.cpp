#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#define TX pair<int,int>
#define s second
#define f first

ifstream is ("int.in");
ofstream os ("int.out");

struct COMP{
    bool operator()(const TX &left, const TX &right)
    {
        return left.s < right.s;
    }
};

int n, a, b, cnt;
vector <TX> v;

int main()
{
    is >> n;
    for (int i = 0; i < n; ++i)
    {
        is >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), COMP());
    b = -2e9;
    for (int i = 0; i < n; ++i)
        if (v[i].f >= b)
            b = v[i].s, cnt++;
    os << cnt;
    is.close();
    os.close();
    return 0;
}
