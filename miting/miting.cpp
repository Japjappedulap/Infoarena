#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

ifstream is ("miting.in");
ofstream os ("miting.out");

const int INF = 0x3f3f3f3f;
const int Di[] = {-1, 0, 1, 0};
const int Dj[] = {0, 1, 0, -1};

queue <pair <int, int> > Q;

int N, M, K;
char A[61][61], W[11];
int Dp[11][11][61][61], Posi[11], Posj[11];

inline bool OK(int i, int j) {if (i < 1 || j < 1 || i > N || j > M || A[i][j] == '#')   return 0; return 1;};

inline void Lee(int S, int D);

void Solve1();
void Solve2();

int main()
{
    int Task;
    is >> Task;
    is >> N >> M >> W+1;
    K = strlen(W+1);
    for (int i = 1; i <= N; ++i)
        is >> A[i] + 1;
    if (Task == 1)
        Solve1();
    else
        Solve2();
    is.close();
    os.close();
}

inline void Lee(int S, int D)
{
    for (int i, j, iv, jv, Dir; !Q.empty(); Q.pop())
    {
        i = Q.front().first;
        j = Q.front().second;
        for (Dir = 0; Dir < 4; ++Dir)
        {
            iv = i + Di[Dir];
            jv = j + Dj[Dir];
            if (OK(iv, jv) && Dp[S][D][iv][jv] > Dp[S][D][i][j] + 1)
            {
                Dp[S][D][iv][jv] = Dp[S][D][i][j] + 1;
                Q.push({iv, jv});
            }
        }
    }
};

void Solve2()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if ('A' <= A[i][j] && A[i][j] <= 'Z')
                for (int k = 1; k <= K; ++k)
                    if (A[i][j] == W[k])
                        Posi[k] = i, Posj[k] = j;
    memset(Dp, INF, sizeof(Dp));
    for (int i = 1; i <= K; ++i)
    {
        Q.push({Posi[i], Posj[i]});
        Dp[i][i][Posi[i]][Posj[i]] = 0;
        Lee(i, i);
    }

    for (int dif = 1; dif <= K; ++dif)
        for (int l = 1, r, dmin; l+dif <= K; ++l)
        {
            r = l + dif;
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= M; ++j)
                {
                    dmin = Dp[l][r][i][j];
                    for (int k = l; k < r; ++k)
                        dmin = min(dmin, Dp[l][k][i][j] + Dp[k+1][r][i][j]);
                    if (Dp[l][r][i][j] > dmin)
                    {
                        Dp[l][r][i][j] = dmin;
                        Q.push({i, j});
                    }
                }
            Lee(l, r);
        }
    int sol = INF;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            sol = min(sol, Dp[1][K][i][j]);
    os << sol;
};

void Solve1()
{
    int x1 = 999, y1 = 999, x2 = 0, y2 = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if ('A' <= A[i][j] && A[i][j] <= 'Z')
                x1 = min(x1, i), x2 = max(x2, i), y1 = min(y1, j), y2 = max(y2, j);
    os << (x2-x1+1)*(y2-y1+1);
};
