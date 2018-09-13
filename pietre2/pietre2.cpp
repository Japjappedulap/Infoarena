#include <fstream>
#include <cstring>
using namespace std;
#define N 101
ifstream is ("pietre2.in");
ofstream os ("pietre2.out");

int n, v, iK, jK, vK;
int a[N][N], DP[N][N], b[N][N];

void Read();
void BF(int i, int j);

int main()
{
    Read();
    vK = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == 1 || j == 1 || i == n || j == n)
            {
                memset(b, 0, sizeof(b));
                v = 1;
                BF(i, j);
                if (v > vK)
                    vK = v, iK = i, jK = j;
            }


    os << vK-1 << '\n' << iK << ' ' << jK;
    is.close();
    os.close();
    return 0;
}

void BF(int i, int j)
{
    v = max(v, DP[i][j]);
    if (b[i][j] == 1) return;
    b[i][j] = 1;
    if (a[i][j]+1 == a[i-1][j])
    {
        DP[i-1][j] = DP[i][j]+1;
        BF(i-1, j);
    }
    if (a[i][j]+1 == a[i][j+1])
    {
        DP[i][j+1] = DP[i][j]+1;
        BF(i, j+1);
    }
    if (a[i][j]+1 == a[i+1][j])
    {
        DP[i+1][j] = DP[i][j]+1;
        BF(i+1, j);
    }
    if (a[i][j]+1 == a[i][j-1])
    {
        DP[i][j-1] = DP[i][j]+1;
        BF(i, j-1);
    }
};

void Read()
{
    is >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            is >> a[i][j], DP[i][j] = 1;
};
