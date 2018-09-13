#include <fstream>
using namespace std;

ifstream is("cabana.in");
ofstream os("cabana.out");

#define MOD 1000000007

long long T, N, K, x;
int Fact[1000001];
//long long Inv[1000001];
long long Sol1, Sol2;

void Precalc();
int LgExp(int a, long long b);

int main()
{
    is >> T;
    Precalc();
    for ( int i = 1; i <= T; ++i )
    {
        is >> N >> K;
        Sol1 = LgExp(Fact[K],N/K);
        x = K-(N%K);
        Sol2 = ( 1LL * Fact[K] * LgExp(Fact[x], MOD-2))%MOD;
        os << (( 1LL * Sol1 * Sol2)%MOD) << '\n';
    }
    return 0;
}

void Precalc()
{
    Fact[0] = 1;
    Fact[1] = 1;
    for ( int i = 2; i <= 1000000; ++i )
        Fact[i] = (1LL * Fact[i-1] * i) % MOD;
}

int LgExp(int a, long long b)
{
    if (b == 0) return 1;
    long long aux = LgExp(a,b/2)%MOD;
    aux = ( 1LL * aux*aux) % MOD;
    if(b % 2 == 1) aux=( 1LL * aux*a)%MOD;
    return aux;
}
