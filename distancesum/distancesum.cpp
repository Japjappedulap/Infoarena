#include <fstream>
#include <algorithm>
using namespace std;

ifstream is ("distancesum.in");
ofstream os ("distancesum.out");

#define x first
#define y second
#define BF 1<<20
char Pars[BF], *p;
int GET();
void Check();

int N, M, A, B;
long long X[100002], Y[100002];
long long Sx1[100002], Sx2[100002];
long long Sy1[100002], Sy2[100002];

void Solve();

int main()
{
    p = Pars;
    N = GET(), M = GET();
    for (int i = 1, a, b; i <= N; ++i)
        a = GET(), b = GET(), X[i] = a+b, Y[i] = a-b;;
    sort(X+1, X+N+1);
    sort(Y+1, Y+N+1);
    for (int i = 2; i <= N; ++i)
    {
        Sx1[i] = Sx1[i-1] + (i-1)*(X[i] - X[i-1]);
        Sy1[i] = Sy1[i-1] + (i-1)*(Y[i] - Y[i-1]);
    }
    for (int i = N-1; i > 0; --i)
    {
        Sx2[i] = Sx2[i+1] + (X[i+1] - X[i])*(N-i);
        Sy2[i] = Sy2[i+1] + (Y[i+1] - Y[i])*(N-i);
    }
    Y[0] = X[0] = -(2e9+99);
    Y[N+1] = X[N+1] = 2e9+99;
    for (int m = 1, a, b; m <= M; ++m)
    {
        a = GET(), b = GET();
        A = a+b, B = a-b;
        Solve();
    }
}

void Solve()
{
    int p1, p2, L, R, M;
    long long Ox, Oy;
    for (L = 1, R = N; L <= R; )
    {
        M = (L+R) / 2;
        if (X[M] == A){
            p1 = M-1, p2 = M+1;
            break;
        }
        if (X[M] < A && A < X[M+1]){
            p1 = M, p2 = M+1;
            break;
        }
        if (X[M-1] < A && A < X[M]){
            p1 = M-1, p2 = M;
            break;
        }
        if (X[M] < A)
            L = M+1;
        if (X[M] > A)
            R = M-1;
    }
    Ox = (Sx1[p1] + p1*(A-X[p1])) + (Sx2[p2] + (N-p2+1) * (X[p2]-A));
    for (L = 1, R = N; L <= R; )
    {
        M = (L+R) / 2;
        if (Y[M] == B)
        {
            p1 = M-1, p2 = M+1;
            break;
        }
        if (Y[M] < B && B < Y[M+1])
        {
            p1 = M, p2 = M+1;
            break;
        }
        if (Y[M-1] < B && B < Y[M])
        {
            p1 = M-1, p2 = M;
            break;
        }
        if (Y[M] < B)
            L = M+1;
        if (Y[M] > B)
            R = M-1;
    }
    Oy = (Sy1[p1] + p1*(B-Y[p1])) + (Sy2[p2] + (N-p2+1) * (Y[p2]-B));
    os << (Ox+Oy)/2 << '\n';
};

int GET()
{
    int X = 0, sgn = 1;
    while (*p < '0' || *p > '9')
    {
        if (*p == '-') sgn = -1;
        ++p, Check();
    }
    while (*p >= '0' && *p <= '9') X = X*10 + (*p - '0'), ++p, Check();
    return X*sgn;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BF, '\0'), p = Pars;
};
