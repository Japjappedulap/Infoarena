#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

ifstream is ("razboi.in");
ofstream os ("razboi.out");

using PII = pair<int,int>;
#define node first
#define cost second

int N, T;
bool B[16001];
vector <PII> G[16001];
vector <int> Du, Dd, depth;

void Solve();
void DFS(int x);
void UDFS(int x);
void DDFS(int x);

int main()
{
    is >> T;
    for (int t = 1; t <= T; ++t)
    {
        os << "Testul nr #" << t << '\n';
        Solve();
    }
    is.close();
    os.close();
}

void Solve()
{
    is >> N;
    depth.resize(N+1); Du.resize(N+1); Dd.resize(N+1);
    for (int i = 1; i <= N; ++i) depth[i] = Du[i] = Dd[i] = 0;
    for (int i = 1, a, b, c; i < N; ++i)
    {
        is >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    DDFS(1);
    UDFS(1);
    int res = 1<<30;
    for (int i = 1; i <= N; ++i)
    {
        Dd[i] = max(Dd[i], Du[i]);
        if (Dd[i]) res = min(Dd[i], res);
    }
    for (int i = 1; i <= N; ++i)
        if (Dd[i] == res)
            os << i << '\n';
    for (int i = 1; i <= N; ++i)
        G[i].clear();
};

void DDFS(int x)
{
    B[x] = 1;
    for (const auto& f : G[x])
        if (B[f.node] == 0)
        {
            depth[f.node] = depth[x]+1;
            DDFS(f.node);
            Dd[x] = max( Dd[x], Dd[f.node]+f.cost);
        }
};

void UDFS(int x)
{
    B[x] = 0;
    for (const auto& f : G[x])
        if (B[f.node] == 1)
        {
            for (const auto& bro : G[x])
                if (bro.node != f.node && depth[bro.node] == depth[f.node])
                    Du[f.node] = max(Du[f.node], Dd[bro.node] + bro.cost + f.cost);
            Du[f.node] = max(Du[f.node], Du[x] + f.cost);
            UDFS(f.node);
        }
};



























