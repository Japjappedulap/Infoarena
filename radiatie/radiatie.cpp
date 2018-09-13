#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define PII pair<int, int>
#define Edge pair<int,PII>
#define x first
#define y second
#define BF 1<<20
char Pars[BF], *p;
int GET();
void Check();


ifstream is ("radiatie.in");
ofstream os ("radiatie.out");

int N, M, Qr;
vector <Edge> E;

int Depth[15001], D[15001];
int T[15001], ApmSize;

void Read();
void Make_APM();
void GetLvl(int X);
void Solve();
int Root(int k);
int FindLCA(int A, int B);

int main()
{
    Read();
    Make_APM();
    Solve();
}

void Read()
{
    p = Pars;
    N = GET(), M = GET(), Qr = GET();
    for (int a, b, c; M; --M)
        a = GET(), b = GET(), c = GET(), E.push_back({c, {a, b}});
};

void Make_APM()
{
    for (int i = 1; i <= N; ++i)
        T[i] = i;
    sort(E.begin(), E.end());
    int Rx, Ry;
    for (const auto& m : E)
    {
        Rx = Root(m.y.x);
        Ry = Root(m.y.y);
        if (Rx != Ry)
        {
            T[Ry] = Rx;
            D[Ry] = m.x;
            ApmSize++;
        }
        if (ApmSize >= N-1)
            break;
    }
    for (int i = 1; i <= N; ++i)
        if (Depth[i] == 0)
            GetLvl(i);
};

void GetLvl(int X)
{
    if (T[X] == X) return;
    GetLvl(T[X]);
    Depth[X] = Depth[T[X]]+1;
};

void Solve()
{
    for (int X, Y; Qr; --Qr)
        X = GET(), Y = GET(), os << FindLCA(X, Y) << '\n';
};

int FindLCA(int A, int B)
{
    int val = 0;
    while (Depth[A] > Depth[B])
    {
        val = max(val, D[A]);
        A = T[A];
    }
    while (Depth[A] < Depth[B])
    {
        val = max(val, D[B]);
        B = T[B];
    }
    while (A != B)
    {
        val = max(val, max(D[A], D[B]));
        A = T[A], B = T[B];
    }
    return val;
};

int Root(int k)
{
    while (T[k] != k) k = T[k];
    return k;
};

int GET()
{
    int X = 0;
    while (*p < '0' || *p > '9')++p, Check();
    while (*p >= '0' && *p <= '9') X = X*10 + (*p - '0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BF, '\0'), p = Pars;
};
