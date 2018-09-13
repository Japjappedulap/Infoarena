#include <fstream>
#include <set>
using namespace std;

ifstream is ("easygraph.in");
ofstream os ("easygraph.out");

const int Nmax = 15001;
const int INF = 0x3f3f3f3f;

int Tests;
int N, M;

long long V[Nmax], D[Nmax];
bool Viz[Nmax];

set <int> G[Nmax];

void Solve();
void DFS(int x);

int main()
{
    for (is >> Tests; Tests--; Solve());
    is.close();
    os.close();
};

void Solve()
{
    is >> N >> M;

    for (int i = 1; i <= N; ++i)
        is >> V[i], D[i] = V[i];

    for (int i = 1, a, b; i <= M; ++i)
    {
        is >> a >> b;
        if (G[a].find(b) == G[a].end())
            G[a].insert(b);
    }

    for (int i = 1; i <= N; ++i)
        if (Viz[i] == 0)
            DFS(i);

    long long Sol = -INF;
    for (int i = 1; i <= N; ++i)
        Sol = max(Sol, D[i]);
    os << Sol << '\n';

    for (int i = 1; i <= N; ++i)
        D[i] = V[i] = Viz[i] = 0, G[i].clear();
};

void DFS(int x)
{
    Viz[x] = 1;
    long long AX = 0;
    for (const int& y : G[x])
    {
        if (Viz[y] == 0)
            DFS(y);
        AX = max(AX, D[y]);
    }
    D[x] += AX;
};
