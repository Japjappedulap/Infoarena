#include <fstream>
using namespace std;

ifstream is ("gcd.in");
ofstream os ("gcd.out");

int A, B, MOD, T;

void Solve();
int GCD(int x, int y);
int Lpow(int x, int y);

int main()
{
    for (is >> T; T; --T) Solve();
    is.close();
    os.close();
}

void Solve()
{
    is >> A >> B >> MOD;
    int G = GCD(A, B);
    os << Lpow(2, G)-1 << '\n';
};

int Lpow(int x, int y)
{
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0)
        return Lpow((1LL*x*x) % MOD, y / 2) % MOD;
    if (y % 2 == 1)
        return (1LL*x*Lpow((1LL*x*x) % MOD, y / 2)) % MOD;
};

int GCD(int x, int y)
{
    int r;
    while (y)
    {
        r = x%y;
        x = y;
        y = r;
    }
    return x;
};
