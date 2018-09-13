#include <fstream>
#include <cstring>
#include <bitset>
using namespace std;

#define NDIM 50001
#define INF 1<<28

#define BUFFER 1<<17
char Pars[BUFFER], *p;

int GET();
void Check();

ifstream is ("distante.in");
ofstream os ("distante.out");

int N, M, T, D[NDIM], S;
bitset <NDIM> B;

bool Solve();

int main()
{
    p = Pars, Check();
    for (T = GET(); T; --T)
        if (Solve())
            os << "DA\n";
        else
            os << "NU\n";
    is.close();
    os.close();
};

bool Solve()
{
    N = GET(); M = GET(); S = GET();\
    bool ok = 1;
    for (int i = 1; i <= N; ++i)
        D[i] = GET(), B[i] = 0;
    if (D[S]) ok = 0;
    B[S] = 1;
    for (int i = 1, a, b, c; i <= M; ++i)
    {
        a = GET(); b = GET(); c = GET();
        if (D[a] + c < D[b] || D[b] + c < D[a]) ok = 0;
        if (D[a] + c == D[b]) B[b] = 1;
        if (D[b] + c == D[a]) B[a] = 1;
    }
    for (int i = 1; i <= N; ++i)
        if (B[i] == 0) return 0;
    return ok;
};

int GET()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while (*p >= '0' && *p <= '9') X = X*10 + (*p-'0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BUFFER, '\0'), p = Pars;
};
