#include <fstream>
using namespace std;

ifstream is ("azerah.in");
ofstream os ("azerah.out");

const int MOD = 1000000007;
int N, X, Z, O, T, ax;

void Solve();

int main()
{
    for (is >> T; T; --T)
        Solve();
    is.close();
    os.close();
}

void Solve()
{
    is >> N;
    Z = O = 0;
    for (int i = 1; i <= N; ++i)
    {
        is >> X;
        X %= 2;
        if (X == 0)
        {
            Z <<= 1;
            O <<= 1;
            Z++;
        }
        if (X == 1)
        {
            ax = O;
            O += Z;
            Z += ax;
            O++;
        }
        Z %= MOD;
        O %= MOD;
    }
    os << Z <<  '\n';
};
