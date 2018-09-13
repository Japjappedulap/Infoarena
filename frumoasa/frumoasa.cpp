#include <fstream>
using namespace std;
#define ll long long
#define MOD 1000000007
ifstream is ("frumoasa.in");
ofstream os ("frumoasa.out");

ll n, k, res, S1, S2, x, y;
ll F[28];

ll LgPow(ll A, ll B);

int main()
{
    is >> n >> k;
    if (k >= 26)
        res = 0;
    else
    {
        F[0] = F[1] = 1;
        for (int i = 2; i <= 26; ++i) F[i] = (F[i-1] * i) % MOD;
        x = 26-k;
        y = MOD-2;
        S1 = (F[26] * LgPow(F[x], y)) % MOD;
        S2 = LgPow(x, n-k) % MOD;
        res = (S1*S2) % MOD;
    }
    os << res;
    is.close();
    os.close();
    return 0;
}

ll LgPow(ll A, ll B)
{
    if (B == 0) return 1;
    if (B == 1) return A;
    if (B % 2 == 0) return LgPow(A*A % MOD, B/2);
    else            return A*LgPow(A*A % MOD, B/2) % MOD;
};
