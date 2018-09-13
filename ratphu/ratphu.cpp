#include <fstream>
using namespace std;

ifstream is ("ratphu.in");
ofstream os ("ratphu.out");

int P, N, Mod;
int C[18];
long long D[1<<18][21], X;

int main()
{
    is >> X >> P;
    for(; X; C[N++] = X % 10, X /= 10, C[N] %= P);
    D[0][0] = 1;
    for(int mask = 0; mask < (1 << N); ++mask)
        for (int i = 0; i < P; ++i)
            if (D[mask][i])
                for (int j = 0; j < N; ++j)
                    if ((mask & (1 << j)) == 0)
                    {
                        Mod = (i * 10 + C[j]);
                        while (Mod >= P)
                            Mod -= P;
                        D[mask | (1 << j)][Mod] += D[mask][i];
                    }
    os << D[(1 << N) - 1][0];
    is.close();
    os.close();
}
