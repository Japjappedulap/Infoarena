#include <fstream>
using namespace std;

ifstream is ("cal.in");
ofstream os ("cal.out");

int si, sj, n, s, cnt;

int main()
{
    int i, j;
    is >> si >> sj >> s >> n;
    for ( int k = 0; k < n; ++k )
    {
        is >> i >> j;
        int x = 0;
        if (si > i) x += si - i;
        if (si < i) x += i - si;
        if (sj > j) x += sj - j;
        if (sj < j) x += j - sj;
        if (x == s) cnt++;
    }
    os << cnt;
    is.close();
    os.close();
    return 0;
}
