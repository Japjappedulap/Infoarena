#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream is ("atac.in");
ofstream os ("atac.out");

const int INF = 0x3f3f3f3f;
const int Nmax = 32001;

int N, M, P;
long long X, Y, A, B, C, D, Z;

int Euler[Nmax<<1], Depth[Nmax<<1], RMQ[18][Nmax<<1], Ind[Nmax], K, Log[Nmax<<1];
int DP[18][Nmax], GrandFather[18][Nmax];

vector < pair<int, int> > G[Nmax];


void Read();
inline void DFS(int, int);
void RangeMinimumQuery();
inline int LCA(int, int);
inline int Query(int, int);
inline int Path(int, int);

int main()
{
    Read();

    DFS(1, 1);

    RangeMinimumQuery();

    for (; M; --M)
    {
        Z = Query(X, Y);
        if (P >= M)
            os << Z << '\n';
        X = (X*A + Y*B) % N + 1;
        Y = (Y*C + Z*D) % N + 1;
    }

    is.close();
    os.close();
}

inline int Path(int x, int y)
{
    int k = Depth[Ind[x]] - Depth[Ind[y]];
    int sol = INF;
    for (int i = 0; i < 17; ++i)
        if (k & (1<<i))
        {
            sol = min(sol, DP[i][x]);
            x = GrandFather[i][x];
        }
    return sol;
};

inline int Query(int a, int b)
{
    if (a == b) return 0;
    int c = LCA(a, b);
    return min(Path(a, c), Path(b, c));
};

void RangeMinimumQuery()
{
    for (int i = 1; i <= K; ++i)
        RMQ[0][i] = i;

    for (int i = 1, k; (1<<i) < K; ++i)
        for (int j = 1; j + (1<<i) <= K+1; ++j)
        {
            k = j + (1<<(i-1));
            if (Depth[RMQ[i-1][j]] <= Depth[RMQ[i-1][k]])
                RMQ[i][j] = RMQ[i-1][j];
            else
                RMQ[i][j] = RMQ[i-1][k];
        }

    for (int i = 1; i < 17; ++i)
        for (int j = 1; j <= N; ++j)
            if (GrandFather[i-1][j] != -1)
            {
                GrandFather[i][j] = GrandFather[i-1][GrandFather[i-1][j]];
                DP[i][j] = min(DP[i-1][j], DP[i-1][GrandFather[i-1][j]]);
            }
};

void Read()
{
    is >> N >> M >> P;
    for (int i = 2; i < 2*N; ++i)
        Log[i] = Log[i>>1] + 1;

    for (int i = 2, x, y; i <= N; ++i)
    {
        is >> x >> y;
        G[x].push_back({i, y});
    }

    is >> X >> Y >> A >> B >> C >> D;
    memset(GrandFather, -1, sizeof(GrandFather));
    memset(DP, INF, sizeof(DP));
};

#define next ax.first
#define cost ax.second

inline int LCA(int a, int b)
{
    int p1 = Ind[a], p2 = Ind[b];
    if (p1 > p2) swap(p1, p2);

    int k = Log[p2-p1];

    if (Depth[RMQ[k][p1]] <= Depth[RMQ[k][p2 - (1<<k) + 1]])
        return Euler[RMQ[k][p1]];
    else
        return Euler[RMQ[k][p2 - (1 << k) + 1]];
};

inline void DFS(int node, int depth)
{
    Ind[node] = ++K;
    Euler[K] = node;
    Depth[K] = depth;

    for (const auto& ax : G[node])
    {
        DP[0][next] = cost;
        GrandFather[0][next] = node;

        DFS(next, depth+1);

        Euler[++K] = node;
        Depth[K] = depth;
    }
};
