#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

ifstream is ("algoritm.in");
ofstream os ("algoritm.out");

#define BUFFER 1<<18
char Pars[BUFFER], *p;
int GET();
void Check();

using PII = pair<int,int>;
const int INF = 0x3f3f3f3f;
const int MaxN = 100010;

int N, M;
int D[MaxN], S[MaxN];
bool B[MaxN],  BE[MaxN << 1];

struct Edge{int x, y, w; };
Edge E[MaxN << 1];

vector <int> G[MaxN];
priority_queue<PII, vector<PII>, greater<PII> > H;
queue <int> Q;

void Solve();

int main()
{
    p = Pars;
    int T;
    for (T = GET(); T; --T)
        Solve();
    is.close();
    os.close();
}

#define nx E[j].x+E[j].y-i

void Solve()
{
    N = GET();
    M = GET();
    for (int i = 1, a, b, c; i <= M; ++i)
    {
        E[i].x = GET();
        E[i].y = GET();
        E[i].w = GET();
        G[E[i].x].push_back(i);
    }
    memset(D, INF, sizeof(D)); memset(B, 0, sizeof(B)); memset(BE, 0, sizeof(BE)); memset(S, 0, sizeof(S));
    D[1] = 0; S[1] = 1;
    H.push({0, 1});
    for (int i; !H.empty();)
    {
        i = H.top().second;
        B[i] = 1;
        for (const int& j : G[i])
            if (D[nx] > D[i] + E[j].w)
            {
                D[nx] = D[i] + E[j].w;
                H.push({D[nx], nx});
                S[nx] = S[i] + 1;
            }
        while (!H.empty() && B[H.top().second])
            H.pop();
    }
    Q.push(1);
    for (int i; !Q.empty(); )
    {
        i = Q.front();
        Q.pop();
        for (const int& j : G[i])
            if (S[nx] == S[i] + 1 && BE[j] == 0)
            {
                os << j << ' ';
                BE[j] = 1;
                Q.push(nx);
            }
    }
    for (int i = 1; i <= M; ++i)
        if (BE[i] == 0)
            os << i << ' ';
    os << '\n';
    for (int i = 1; i <= N; ++i)
        G[i].clear();
};

int GET()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while ('0' <= *p && *p <= '9') X = X*10 +(*p-'0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BUFFER, '\0'), p = Pars;
};







