#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream is ("reinvent.in");
ofstream os ("reinvent.out");

#define BF 1<<17
char Ps[BF], *p;

int GET();
void Check();

int N, M, X, a, b, D[100004];
int B[100004];

vector <int> V[100004];
queue <int> Q;

int BFS();

int main()
{
    p = Ps; Check();
    N = GET(), M = GET(), X = GET();
    for (int i = 1; i <= M; ++i)
    {
        a = GET(); b = GET();
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for (int i = 1; i <= X; ++i)
        a = GET(), Q.push(a), D[a] = 1, B[a] = a;
    os << BFS();
}

int BFS()
{
    int i, j;
    for (; !Q.empty(); Q.pop())
    {
        i = Q.front();
        for (j = 0; j < V[i].size(); ++j)
        {
            if (D[V[i][j]] != 0 && B[V[i][j]] != B[i])
                return D[V[i][j]] + D[i] - 1;
            if (D[V[i][j]] == 0)
            {
                D[V[i][j]] = D[i] + 1;
                B[V[i][j]] = B[i];
                Q.push(V[i][j]);
            }
        }
    }
};

int GET()
{
    int X = 0;
    while (*p <= '0' || *p > '9') ++p, Check();
    while (*p >= '0' && *p <= '9') X = X*10 + (*p-'0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Ps, BF, '\0'), p = Ps;
};






