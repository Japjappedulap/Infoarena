#include <fstream>
using namespace std;

ifstream is ("nrcuv.in");
ofstream os ("nrcuv.out");

int n, m, sol;
bool B[50][50];
int DP[1005][50];
char x, y;

int main()
{
    is >> n >> m;
    for (int i = 1; i <= m; ++i)
        is >> x >> y, B[x-96][y-96] = B[y-96][x-96] = 1;
    for (int j = 1; j <= 26; ++j)
        DP[1][j] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= 26; ++j)
            for (int k = 1; k <= 26; ++k)
                if (B[k][j] == 0 && B[j][k] == 0)
                {
                    DP[i][j] += DP[i-1][k];
                    DP[i][j] %= 104659;
                }
    for (int j = 1; j <= 26; ++j)
    {
        sol += DP[n][j];
        sol %= 104659;
    }
    os << sol;
    is.close();
    os.close();
    return 0;
}
