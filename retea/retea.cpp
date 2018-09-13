#include <fstream>
#include <cstring>
#include <cfloat>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

ifstream is ("retea.in");
ofstream os ("retea.out");

typedef pair<int, int> PII;

const int Nmax = 1001;
const int Mmax = 100001;
const int Kmax = 11;

const int INF = 0x3f3f3f3f;

int N, M, K;
int D[Nmax][Kmax];

vector <PII> Graph[Nmax];

priority_queue <pair<int, PII> , vector<pair<int, PII>>, greater<pair<int, PII>> > Q;  // {entry cost, node}

void Input();
void Dijkstra();

void debug()
{
    os << '\n';

    for (int i = 1; i <= N; ++i, os << '\n')
        for (int j = 0; j <= K; ++j)
            if (D[i][j] == INF)
                os << "X.XXXX ";
            else
            {os << fixed;
                os << setprecision(4) << D[i][j] << ' ';}
    os << '\n';
}

int main()
{

    Input();
    Dijkstra();

    is.close();
    os.close();
}

void Input()
{
    is >> N >> M >> K;
    for (int a, b, c; M; --M)
    {
        is >> a >> b >> c;
        Graph[a].push_back({b, c<<10});
        Graph[b].push_back({a, c<<10});
    }
};

#define y next.first
#define cost next.second

void Dijkstra()
{
    for (int i = 2; i <= N; ++i)
        for (int j = 0; j <= K; ++j)
            D[i][j] = INF;
    Q.push({0, {1, 0}});
    for (int x, k, curcost; !Q.empty();)
    {
        x = Q.top().second.first;
        k = Q.top().second.second;
        curcost = Q.top().first;
        Q.pop();
        if (curcost > D[x][k])
            continue;
        if (x == N)
        {
            os << fixed << setprecision(4) << (double)D[x][k] / (1<<10);
            return;
        }
        for (const PII& next : Graph[x])
            for (int q = 0; k + q <= K; ++q)
                if (D[y][k + q] > D[x][k] + (cost >> q) )
                {
                    D[y][k + q] = D[x][k] + (cost >> q);
                    Q.push({D[y][k+q], {y, k+q}});
                }
    }
};
