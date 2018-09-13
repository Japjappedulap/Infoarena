#include <fstream>
#include <vector>
using namespace std;

ifstream is ("arbore4.in");
ofstream os ("arbore4.out");

const int BUFFER = 1<<18;       //
char Parser[BUFFER], *p;        //
inline int GET();               //    CITIRE
inline void Check();            //

const int MOD = 666013;
const int Nmax = 100007;

int N;
int SubTreeSize[Nmax], Din[Nmax];

int Fact[Nmax], InvFact[Nmax];

bool Viz[Nmax];

vector <int> G[Nmax];


void Precalc();                             //
inline int Comb(int A, int B);              //
inline int LPOW(int A, int B);              //smart C(n, k) calculation
inline int InversModular(int X);            //

inline void FindTreeSize(int node);
inline void Solve(int node);


int main()
{
    p = Parser;
    N = GET();
    for (int i = 1, a , b; i < N; ++i)
    {
        a = GET(), b = GET();
        G[a].push_back(b);
        G[b].push_back(a);
    }
    Precalc();

    FindTreeSize(1);
    Solve(1);

    os << Din[1];
    return 0;
}


inline void Solve(int node)
{
    Viz[node] = 0;
    Din[node] = 1;
    int NodesLeft = SubTreeSize[node] - 1;
    for (const int& son : G[node])
    {
        if (Viz[son] == 0) continue;
        Solve(son);
        Din[node] = (1LL * Din[node] * Din[son] * Comb(NodesLeft, SubTreeSize[son])) % MOD;
        NodesLeft -= SubTreeSize[son];
    }
};

inline void FindTreeSize(int node)
{
    Viz[node] = 1;
    SubTreeSize[node] = 1;
    for (const int& next : G[node])
    {
        if (Viz[next] == 1) continue;
        FindTreeSize(next);
        SubTreeSize[node] += SubTreeSize[next];
    }
};




void Precalc()
{
    Fact[0] = InvFact[0] = 1;
    for (int i = 1; i <= N; ++i)
        Fact[i] = (1LL * Fact[i-1] * i) % MOD, InvFact[i] = -1;
};

inline int Comb(int A, int B)
{
    return (1LL * Fact[A] * InversModular(A-B) * InversModular(B)) % MOD;
};

inline int InversModular(int X)
{
    if (InvFact[X] != -1) return InvFact[X];
    InvFact[X] = LPOW(Fact[X], MOD-2);
    return InvFact[X];
};

inline int LPOW(int A, int B)
{
    if (B == 0) return 1;
    if (B == 1) return A;
    if (B % 2 == 0) return LPOW((1LL * A * A) % MOD, B / 2) % MOD;
    if (B % 2 == 1) return (1LL * A * LPOW((1LL * A * A) % MOD, B / 2)) % MOD;
};




inline int GET()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while ('0' <= *p && *p <= '9') X = X*10 + (*p - '0'), ++p, Check();
    return X;
};

inline void Check()
{
    if (*p == '\0') is.get(Parser, BUFFER, '\0'), p = Parser;
};
