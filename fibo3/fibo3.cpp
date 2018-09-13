/*
Solutie Dani Mocanu O(-1)
sol += min() - max() + 1
lucram cu abscise, in min() fixam abscisa pctului de intersectie dintre dreapta Fib[i] si cel mai la dreapta-jos pct din dreptunghi
in max() fixam abscisa pctului de intersectie dintre dreapta Fib[i] si cel mai la stanga-sus pct din dreptunghi
dreapta fib[i] = toate perechile (x,y) care x+y = fib[i]
dupa ce avem cele doua abscise fixate, facem diferenta si adaugam 1 PTR CA E INTERVAL INCHIS evident wtf
grije ca fib[i] sa se intersecteze cu dreptunghiu, altfel faci balarii
nu vad dinamica
*/
#include <fstream>
using namespace std;

const int BFSIZE = 1<<17;
char S[BFSIZE], *p;
inline long long Get();
inline void Check();

ifstream is ("fibo3.in");
ofstream os ("fibo3.out");

long long A, B, C, D, N;
long long Fib[91];

int main()
{
    p = S;
    Fib[0] = Fib[1] = 1;
    for (int i = 2; i < 91; ++i)
        Fib[i] = Fib[i-1] + Fib[i-2];

    N = Get();
    int i;
    for (long long Sol; N; --N)
    {
        A = Get(); B = Get(); C = Get(); D = Get();
        for (i = 1; Fib[i] < A+B; ++i);
        for (Sol = 0; Fib[i] <= C+D; ++i)
            Sol += (min(C, Fib[i]-B) - max(A, Fib[i]-D) + 1);
        os << Sol << '\n';
    }
    is.close();
    os.close();
}

inline long long Get()
{
    while (*p < '0' || '9' < *p) ++p, Check();
    long long X = 0;
    while ('0' <= *p && *p <= '9') X = X * 10 + (*p-'0'), ++p, Check();
    return X;
};

inline void Check(){ if (*p == '\0') is.get(S, BFSIZE, '\0'), p = S;};
