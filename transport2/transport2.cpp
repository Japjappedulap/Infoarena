// Transport2 - 100P
// dijkstra + parsare (fara parsare -> 90P)
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream is ("transport2.in");
ofstream os ("transport2.out");

#define DIM 100002
#define Buffer 1<<17
#define n first
#define cost second

char Pars[Buffer], *p;
int N, M, D[DIM];
vector <pair<int,int> > G[DIM];

struct CMP{ bool operator ()(int a, int b){ return D[a] < D[b]; } };
priority_queue <int, vector <int>, CMP> Q;

int GET();
void OK();

int main()
{
    p = Pars;
    N = GET(); M = GET();
    for (int i = 1, a, b, c; i <= M; ++i)
    {
        a = GET(); b = GET(); c = GET();
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    D[1] = 10000;
    Q.push(1);
    for (int i; !Q.empty(); )
    {
        i = Q.top(); Q.pop();
        if (i == N) break;
        for (const auto& x : G[i])
            if (D[x.n] < min(D[i], x.cost))
            {
                D[x.n] = min(D[i], x.cost);
                Q.push(x.n);
            }
    }
    os << D[N];
    is.close();
    os.close();
}

int GET()   // pentru parsare
{
    int X = 0;
    while (*p < '0' || *p > '9') ++p, OK();
    while (*p >= '0' && *p <= '9') X = 10*X + (*p-'0'), ++p, OK();
    return X;
};

void OK()   // pentru parsare
{
    if (*p == '\0') is.get(Pars, Buffer, '\0'), p = Pars;
};
