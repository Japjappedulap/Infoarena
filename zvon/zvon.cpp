#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream is ("zvon.in");
ofstream os ("zvon.out");

#define BF 1<<17
char Pars[BF], *p;
int GET();
void Check();

int T;
int N, c[100002];
vector <int> v[100002];

void Solve();
void DFS(int i);
inline int CMP(const int a, const int b){
    return (c[a] > c[b]);
}

int main()
{
    p = Pars;
    for(T = GET(); T; --T)
        Solve();
    is.close();
    os.close();
}

void Solve()
{
    N = GET();
    int a, b;
    for (int i = 1; i < N; ++i)
    {
        a = GET(), b = GET();
        v[a].push_back(b);
    }
    DFS(1);
    os << c[1] << '\n';
    for (int i = 1; i <= N; ++i) v[i].clear(); memset(c, 0, sizeof(c));
};

void DFS(int i)
{
    if (v[i].empty()) return;
    for (int j = 0; j < v[i].size(); ++j)
        DFS(v[i][j]);
    sort(v[i].begin(), v[i].end(), CMP);
    for (int j = 0; j < v[i].size(); ++j)
        c[i] = max(c[i], c[v[i][j]]+j+1);
};

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
