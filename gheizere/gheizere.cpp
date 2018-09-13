#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("gheizere.in");
ofstream os ("gheizere.out");
#define TX pair<int,int>
#define x first
#define y second
#define NSIZE 252
#define INF 0x3f3f3f3f
int n, m, p;

struct Gheizer{
    int i, j, r, t, d;
}  G[NSIZE*4];

TX Start, Finish;
int DP[2][NSIZE][NSIZE], X;

void Read();
void Solve();
void Volcanoes(int TIME, int IND);

int main()
{
    Read();
    memset(DP[0], INF, sizeof DP[0]);
    DP[0][Start.x][Start.y] = 1;
    Volcanoes(0, 0);
    Solve();
    is.close();
    os.close();
    return 0;
}

void Solve()
{
    int LC = 1, LP = 0;
    for (int k = 1; k <= 500; ++k, swap(LC, LP))
    {
        memset(DP[LC], INF, sizeof DP[LC]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                X = INF;
                if (i > 1) X = min(DP[LP][i-1][j], X);
                if (j > 1) X = min(DP[LP][i][j-1], X);
                if (i < n) X = min(DP[LP][i+1][j], X);
                if (X < INF) DP[LC][i][j] = X+1;
                else         DP[LC][i][j] = INF;
            }
        Volcanoes(k, LC);
        if (DP[LC][Finish.x][Finish.y] != INF)
        {
            os << DP[LC][Finish.x][Finish.y];
            return;
        }
    }
    os << "-1";
};

void Volcanoes(int TIME, int IND)
{
    for (int k = 1; k <= p; ++k)
        if (TIME % (G[k].t + G[k].d) >= G[k].t)
            for (int i = max(1, G[k].i - G[k].r); i <= min(n, G[k].i + G[k].r); ++i)
                for (int j = max(1, G[k].j - G[k].r); j <= min(m, G[k].j + G[k].r); ++j)
                    DP[IND][i][j] = INF;
};

void Read()
{
    is >> n >> m >> p;
    Start.y = 1, Finish.y = m;
    is >> Start.x >> Finish.x;
    for (int i = 1; i <= p; ++i)
        is >> G[i].i >> G[i].j >> G[i].r >> G[i].t >> G[i].d;
};
