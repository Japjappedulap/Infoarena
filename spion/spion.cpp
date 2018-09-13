#include <fstream>
using namespace std;

#define MOD 100003

ifstream is ("spion.in");
ofstream os ("spion.out");

char x;
long long N, K;
int F[MOD];

int T;
void T1();
void T2();
long long C(long long n, long long k);
long long Lg_Exp(long long A, long long B);

int main()
{
    is >> T;
    if (T == 1) T1();
    if (T == 2) T2();
}

void T1()
{
    while (is >> x)
    {
        if (x == 'E') K++;
        N++;
    }
    os << K+1;
};

void T2()
{
    F[0] = F[1] = 1;
    while (is >> x)
    {
        if (x == 'E') K++;
        N++;
        F[N] = (F[N-1] * N) % MOD;
    }
    os << C(N, K);
};

long long C(long long n, long long k)
{
    long long R = ((F[N] * Lg_Exp(F[N-K], MOD-2)) % MOD) * Lg_Exp(F[K], MOD-2) % MOD;
    return R;
};

long long Lg_Exp(long long A, long long B)
{
    if (B == 1) return A;
    if (B == 0) return 1;
    if (B % 2 == 0) return (Lg_Exp(((A*A) % MOD), B/2) % MOD);
    if (B % 2 == 1) return ((A*Lg_Exp(((A*A) % MOD), B/2)) % MOD);
};
