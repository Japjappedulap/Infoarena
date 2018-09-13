#include <fstream>
#include <cstdio>
using namespace std;

#define BF 1<<18
char Pars[BF], *p;

int GET();
void Check();

ifstream is ("saracsaurege.in");

int N, M;
short arb[200001], best;

void Up(int N, int L, int R, int pos, int val);
void Qr(int N, int L, int R, int pos, int val);

int main()
{
    p = Pars;
    N = GET();
    M = GET();
    for (int i = 1, x; i <= N; ++i)
    {
        x = GET();
        Up(1, 1, N, i, x);
    }
    freopen("saracsaurege.out", "w", stdout);
    for (int i = 1, x, y, k = 0; i <= M; ++i, k = 0)
    {
        x = GET(), y = GET();
        best = 0;
        Qr(1, 1, N, x, y);
        printf("%d\n", best);
    }
    is.close();
}

void Qr(int N, int L, int R, int X, int Y)
{
    if (X <= L && R <= Y)
        best = max(best, arb[N]);
    else
    {
        int M = (L+R)/2;
        if (X <= M) Qr(N*2, L, M, X, Y);
        if (M < Y) Qr(N*2+1, M+1, R, X, Y);
    }
};

void Up(int N, int L, int R, int pos, int val)
{
    if (L == R)
        arb[N] = val;
    else
    {
        int M = (L+R)/2;
        if (pos <= M) Up(2*N, L, M, pos, val);
        else Up(2*N+1, M+1, R, pos, val);
        arb[N] = max(arb[2*N], arb[2*N+1]);
    }
};

int GET()
{
    int X = 0;
    while (*p < '0' || *p > '9') ++p, Check();
    while (*p >= '0' && *p <= '9') X = X*10 + (*p - '0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BF, '\0'), p = Pars;
};
