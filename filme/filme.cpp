#include <fstream>
#include <algorithm>
using namespace std;

ifstream is ("filme.in");
ofstream os ("filme.out");

int x, y, n, m, s[10002];
int res;

int main()
{
    is >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        is >> x >> y;
        s[i] = x+y;
    }
    sort (s, s+n);
    for (int i = 0; s[i] <= m && i < n; ++i)
        m -= s[i], res++;
    os << res;
    is.close();
    os.close();
    return 0;
}
