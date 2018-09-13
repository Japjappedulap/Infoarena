#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream is ("berarii2.in");
ofstream os ("berarii2.out");

#define BF 1<<17
char Pars[BF], *p;

int GET();
void Check();

int N, M, P, sol;
vector <vector<int> > V;
vector <bool> B;
queue <int> Q;

int main()
{
    p = Pars;
    N = GET(); M = GET(); P = GET();
    V.resize(N+1); B.resize(N+1);
    for (int i = 1, a, b; i <= M; ++i)
        a = GET(), b = GET(), V[b].push_back(a);
    for (int i = 1, a; i <= P; ++i)
        a = GET(), Q.push(a), B[a] = 1;
    for (int i; !Q.empty(); Q.pop())
    {
        i = Q.front();
        for (int j = 0; j < V[i].size(); ++j)
            if (B[V[i][j]] == 0)
            {
                B[V[i][j]] = 1;
                Q.push(V[i][j]);
            }
    }
    for (int i = 1; i <= N; ++i)
        if (B[i] == 0)
            ++sol;
    os << sol << '\n';
    for (int i = 1; i <= N; ++i)
        if (B[i] == 0)
            os << i << '\n';
    is.close();
    os.close();
}

int GET()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while (*p >= '0' && *p <= '9') X = X * 10 + (*p - '0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BF, '\0'), p = Pars;
};
