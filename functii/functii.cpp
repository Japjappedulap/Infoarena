#include <fstream>
using namespace std;

#define MOD 30103

ifstream is ("functii.in");
ofstream os ("functii.out");

int N, K, sol;
int F[10002] = {1};

int LgPow(int x, int y);
int Comb(int n, int k);

int main()
{
    is >> N >> K;
    for (int i = 1; i <= N; ++i)
        F[i] = (i*F[i-1]) % MOD;
    sol = (1LL * (LgPow(2, K)-2) * Comb(N,K)) % MOD;
    os << sol;
    is.close();
    os.close();
}

int Comb(int n, int k)
{
    int R = F[n];
    R = (1LL * R * LgPow(F[k], MOD-2) * LgPow(F[n-k], MOD-2) ) % MOD;
    return R % MOD;
};

int LgPow(int x, int y)
{
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 1) return (LgPow((1LL*x*x)%MOD, y/2) * x) % MOD;
    if (y % 2 == 0) return LgPow((1LL*x*x)%MOD, y/2) % MOD;
};
