#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

ifstream is ("drum3.in");
ofstream os ("drum3.out");

const int MOD = 30013;

int N, K, No, Nv;
int Factorial[5001];

int Lpow(int A, int B)
{
    if (B == 0) return 1;
    if (B == 1) return A;
    if (B % 2 == 0) return (1LL * Lpow(A, B/2) * Lpow(A, B/2)) % MOD;
    if (B % 2 == 1) return (1LL * A * Lpow(A, B/2) * Lpow(A, B/2)) % MOD;
}

int Comb(int n, int k)
{
    return (1LL * Factorial[n] * Lpow(Factorial[n-k], MOD-2) * Lpow(Factorial[k], MOD-2)) % MOD;
}

int main()
{
    is >> N >> K;
    Factorial[0] = 1;
    for (int i = 1; i <= N; ++i)
        Factorial[i] = (Factorial[i-1] * i) % MOD;

    No = (K+2) / 2;
    Nv = (K+1) / 2;

    os << (Comb(N-2, No-1) * Comb(N-2, Nv-1) * 2) % MOD;

    is.close();
    os.close();
}

