#include <fstream>
#include <vector>
using namespace std;

ifstream is ("concurs.in");
ofstream os ("concurs.out");

const int BUFFER = 1<<18;
char Pars[BUFFER], *p;

inline int GET();
inline void Check();

const int Nmax = 32001;

int N, Q, Root;
int Points[Nmax], bestpoints, bestteamx, bestteamy;
int Euler[Nmax << 1], Depth[Nmax << 1], Ind[Nmax], K;
int RMQ[16][Nmax << 1], Log[Nmax << 1];

vector <int> G[Nmax];

void Read();
inline void DFS(int node, int lvl);
void RangeMinimumQuery();
inline int LCA(int x, int y);

int main()
{
    Read();
    DFS(Root, 0);
    RangeMinimumQuery();
    for (int x, y, boss; Q--; )
    {
        x = GET(), y = GET();
        boss = LCA(x, y);

        if (Points[boss] > bestpoints)
        {
            bestpoints = Points[boss];
            bestteamx = x;
            bestteamy = y;
        }

        if (Points[boss] == bestpoints)
        {
            if (bestteamx > x)
                bestteamx = x, bestteamy = y;

            if (bestteamx == x && bestteamy > y)
                bestteamy = y;
        }
    }
    os << bestpoints << ' ' << bestteamx << ' ' << bestteamy;
    is.close();
    os.close();
}

inline int LCA(int x, int y)
{
    int p1 = Ind[x], p2 = Ind[y];
    if (p1 > p2) swap(p1, p2);
    int k = Log[p2-p1];
    if (Depth[RMQ[k][p1]] <= Depth[RMQ[k][p2 - (1 << k) + 1]])
        return Euler[RMQ[k][p1]];
    else
        return Euler[RMQ[k][p2 - (1 << k) + 1]];
};

void RangeMinimumQuery()
{
    for (int i = 1; i <= K; ++i)
        RMQ[0][i] = i;
    for (int i = 2; i <= K; ++i)
        Log[i] = Log[i >> 1] + 1;
    for (int i = 1, k; (1 << i) <= K; ++i)
        for (int j = 1; j + (1 << i) <= K+1; ++j)
        {
            k = (1 << (i-1));
            if (Depth[RMQ[i-1][j]] <= Depth[RMQ[i-1][j+k]])
                RMQ[i][j] = RMQ[i-1][j];
            else
                RMQ[i][j] = RMQ[i-1][j+k];
        }
};

inline void DFS(int node, int lvl)
{
    Ind[node] = ++K;
    Euler[K] = node;
    Depth[K] = lvl;
    for (const int& next : G[node])
    {
        DFS(next, lvl+1);
        Euler[++K] = node;
        Depth[K] = lvl;
    }
};

void Read()
{
    bool IsRoot[Nmax];
    p = Pars;
    N = GET();
    Q = GET();
    for (int i = 1; i <= N; ++i)
        Points[i] = GET(), IsRoot[i] = 1;
    for (int i = 1, x, y; i < N; ++i)
    {
        x = GET();
        y = GET();
        G[x].push_back(y);
        IsRoot[y] = 0;
    }
    for (int i = 1; i <= N; ++i)
        if (IsRoot[i] == 1)
        {
            Root = i;
            break;
        }
};

inline int GET()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while ('0' <= *p && *p <= '9') X = X*10 + (*p - '0'), ++p, Check();
    return X;
};

inline void Check()
{
    if (*p == '\0') is.get(Pars, BUFFER, '\0'), p = Pars;
};
