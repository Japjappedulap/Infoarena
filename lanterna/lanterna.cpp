#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

ifstream is ("lanterna.in");
ofstream os ("lanterna.out");

int N, M, K, Target;
int Good[55];
int D[55][1005];

vector < pair <int, int> > Time[55], Watt[55];

queue <pair<int,int>> Q;

void MakeEdge(int a, int b, int c, int d);
int Dijkstra(int W);

int main()
{
    is >> N >> K;
    for (int i = 1; i <= N; ++i)
        is >> Good[i];
    is >> M;
    for (int i = 1, a, b, c, d; i <= M; ++i)
    {
        is >> a >> b >> c >> d;
        MakeEdge(a, b, c, d);
    }
    Target = Dijkstra(K);
    int L = 1, R = K, Cost = K;
    while ( L <= R )
    {
        int M = (L+R)/2;
        int T = Dijkstra(M);
        if (T > Target)  L = M + 1;
        else
             if ( T == Target )
             {
                Cost = M;
                R = M - 1;
             }
    }
    os << Target << ' ' << Cost;
    is.close();
    os.close();
}

int Dijkstra(int W)
{
    memset(D, INF, sizeof(D));
    D[1][W] = 0;
    Q.push({1, W});
    for (int i, node, dist, actualcost, cost; !Q.empty(); )
    {
        i = Q.front().first;
        actualcost = Q.front().second;
        Q.pop();
        for (int j = 0; j < Time[i].size(); ++j)
        {
            if (actualcost < Watt[i][j].second) continue;
            node = Time[i][j].first;
            dist = Time[i][j].second;
            if (Good[node]) cost = W;
            else            cost = actualcost - Watt[i][j].second;
            if (D[node][cost] > D[i][actualcost] + dist)
            {
                D[node][cost] = D[i][actualcost] + dist;
                Q.push({node, cost});
            }
        }
    }
    int sol = INF;
    for (int i = 0; i <= W; ++i)
        sol = min(D[N][i], sol);
    return sol;
};

void MakeEdge(int a, int b, int c, int d)
{
    Time[a].push_back({b, c});
    Time[b].push_back({a, c});
    Watt[a].push_back({b, d});
    Watt[b].push_back({a, d});
};
