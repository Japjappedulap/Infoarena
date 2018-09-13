// un kmp genial
#include <fstream>
using namespace std;

ifstream is ("zlego.in");
ofstream os ("zlego.out");

const int Buff = 1<<18;
char Pars[Buff], *p;
int GET();
void Check();

const int Nmax = 250001;

int N;
int V[Nmax], C[Nmax];
int KMP[Nmax];
long long R[Nmax];

void Solve();

int main()
{
    p = Pars;
    for (int Tests = GET(); Tests; --Tests)
        Solve();
    is.close();
    os.close();
}

void Solve()
{
    N = GET();
    for (int i = 1; i <= N; ++i)
        V[i] = GET();
    for (int i = 1; i <= N; ++i)
        C[i] = GET(), R[i] = C[i];

    for (int i = 2, k = 0; i <= N; ++i)
    {
        while (k > 0 && V[i] != V[k+1]) k = KMP[k];
        if (V[i] == V[k+1]) ++k;
        KMP[i] = k;
    }
    for (int i = N; i > 0; --i)
        R[KMP[i]] += R[i];

    for (int i = 1; i <= N; ++i)
        os << R[i] << '\n';
};

int GET()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while ('0' <= *p && *p <= '9') X = X*10 + (*p - '0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, Buff, '\0'), p = Pars;
};
