#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

ifstream is ("gather.in");
ofstream os ("gather.out");

#define PII pair<int,int>
#define Node pair<int, PII >

const int Nmax = 777, Kmax = 16;
const long long INF = 0x3f3f3f3f;

int N, M, K;
int Dij[Nmax], P[Kmax];

long long RF[Kmax][Kmax][Kmax];
long long D[1<<Kmax][Kmax];

vector <Node> G[Nmax];
priority_queue <PII, vector<PII>, greater <PII>> Q;

void Read();
void Dijkstra(int Source, int MaxCap);
void Dynamic();

int main()
{
    Read();
    for (int i = 0; i <= K; ++i)
        for (int cap = 0; cap <= K; ++cap)
        {
            Dijkstra(P[i], cap);
            for (int j = 0; j <= K; ++j)
                RF[i][j][cap] = Dij[P[j]];
        }
    Dynamic();
    int SOL = INF;
    for (int j = 0; j < K; ++j)
        if (D[(1<<K)-1][j] < SOL)
            SOL = D[(1<<K)-1][j];
    os << SOL << '\n';
    os.close();
}

void Dynamic()
{
    ++K;
    for (int i = 0; i < 1<<K; ++i)
        for (int j = 0; j < K; ++j)
            D[i][j] = INF;
    D[1][0] = 0;
    int axk, nrbiti;
    for (int mask = 2; mask < 1<<K; ++mask)
        for (int i = 0; i < K; ++i)
            if (mask & (1<<i))
            {
                nrbiti = 0;
                for (int j = 0; j < K; ++j)
                    if (mask & (1<<j))
                        ++nrbiti;
                --nrbiti;
                axk = (mask & ~(1<<i));
                for (int j = 0; j < K; ++j)
                    if (D[axk][j] < INF)
                        D[mask][i] = min(D[mask][i], D[axk][j] + (RF[j][i][nrbiti]) * (nrbiti));
            }
};

void Read()
{
    is >> K >> N >> M;
    for (int i = 1; i <= K; ++i)
        is >> P[i];
    P[0] = 1;
    for (int a, b, c, d; M; --M)
    {
        is >> a >> b >> c >> d;
        G[a].push_back({b, {c, d}});
        G[b].push_back({a, {c, d}});
    }
    is.close();
};

#define node iter.first
#define cost iter.second.first
#define capacity iter.second.second

bool Rlx[Nmax];

void Dijkstra(int Source, int MaxCap)
{
    memset(Dij, INF, sizeof(Dij));
    memset(Rlx, 0, sizeof(Rlx));
    Q.push({0, Source});
    Dij[Source] = 0;
    for (int i; !Q.empty();)
    {
        i = Q.top().second;
        Rlx[i] = 1;
        for (const auto& iter : G[i])
            if (Dij[node] > Dij[i] + cost && capacity >= MaxCap - 1)
            {
                Dij[node] = Dij[i] + cost;
                Q.push({Dij[node], node});
            }
        while (!Q.empty() && Rlx[Q.top().second])
            Q.pop();
    }
};
