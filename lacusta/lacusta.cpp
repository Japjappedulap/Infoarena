#include <fstream>
#include <iomanip>
#define MAX 2000000000
using namespace std;

ifstream is ("lacusta.in");
ofstream os ("lacusta.out");

short a[251][251];
short b[251][251], n, m;

void DP();

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            is >> a[i][j];
    if (n == 1)
    {
        os << a[1][1]+a[1][m];
        return 0;
    }
    DP();
    is.close();
    os.close();
    return 0;
}

void DP()
{
    int jm1, vm = 1000;
    b[2][1] = 999;
    for ( int j = 2; j <= m; ++j )
        b[2][j] = a[1][1] + a[2][j] + a[1][j];
    for ( int i = 3; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            vm = MAX;
            b[i][j] = a[i][j] + a[i-1][j];
            for ( int j2 = 1; j2 <= m; ++j2 )
                if ( b[i-1][j2] < vm && j != j2 && b[i-1][j2] != -1)
                    vm = b[i-1][j2];
            b[i][j] += vm;
        }
    int mm = MAX;
    for ( int j = 1; j < m; ++j )
        if ( mm > b[n][j] )
            mm = b[n][j];
    os << mm + a[n][m];
};
