#include <fstream>
using namespace std;

ifstream is ("diagonale.in");
ofstream os ("diagonale.out");

int a[1002][1002], b[1002][1002], n, x;
long long d[2015], c[2015], vmax;

void Read();

int main()
{
    vmax = -1000000000;
    Read();
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
        {
            if (i == j)
                c[n] += a[i][j], d[n] += b[i][j];
            if (i > j)
            {
                x = i - j;
                c[n-x] += a[i][j];
                d[n-x] += b[i][j];
            }
            if (i < j)
            {
                x = j - i;
                c[n+x] += a[i][j];
                d[n+x] += b[i][j];
            }
        }
    for ( int i = 1; i <= (n*2-1); i++ )
        if ( vmax < c[i] ) vmax = c[i];
    for ( int i = 1; i <= (n*2-1); i++ )
        if ( vmax < d[i] ) vmax = d[i];
    os << vmax;
    is.close();
    os.close();
    return 0;
}

void Read()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1, j2 = n; j <= n; ++j, --j2)
        {
            is >> a[i][j];
            b[j2][i] = a[i][j];
        }
};
