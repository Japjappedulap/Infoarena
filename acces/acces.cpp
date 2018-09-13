#include <fstream>
using namespace std;

ifstream is ("acces.in");
ofstream os ("acces.out");

int n, m, Q, x, y;
bool b[1001][1001];
int DP[1001][1001];

void Read();
void DINA();
void Write();

int main()
{
    Read();
    DINA();
    Write();
    is.close();
    os.close();
    return 0;
}

void Read()
{
    is >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            is >> b[i][j];
};

void DINA()
{
    for (int i = 1; i <= n; ++i)
        if (b[i][1] == 1) DP[i][1] = 0;
        else    DP[i][1] = DP[i-1][1] + 1;
    for (int j = 1; j <= m; ++j)
        if (b[1][j] == 1) DP[1][j] = 0;
        else    DP[1][j] = DP[1][j-1] + 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= m; ++j)
            if (b[i][j] == 0)
            {
                if (b[i-1][j] == 0 && b[i][j-1] == 0)
                    DP[i][j] = DP[i-1][j] + DP[i][j-1]+1 - DP[i-1][j-1];
                if (b[i-1][j] == 0 && b[i][j-1] == 1)
                    DP[i][j] = DP[i-1][j] + 1;
                if (b[i-1][j] == 1 && b[i][j-1] == 0)
                    DP[i][j] = DP[i][j-1] + 1;
            }
            else
            {
                if (b[i-1][j] == 0 && b[i][j-1] == 0)
                    DP[i][j] = DP[i-1][j-1];
                if (b[i-1][j] == 1 && b[i][j-1] == 0)
                    DP[i][j] = DP[i-1][j];
                if (b[i-1][j] == 0 && b[i][j-1] == 1)
                    DP[i][j] = DP[i][j-1];
                if (b[i-1][j] == 1 && b[i][j-1] == 1)
                    DP[i][j] = DP[i-1][j-1];
            }
};

void Write()
{
    is >> Q;
    for (int i = 1; i <= Q; ++i)
    {
        is >> x >> y;
        os << DP[x][y] << '\n';
    }
};
