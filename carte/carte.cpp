#include <algorithm>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

ifstream is ("carte.in");
ofstream os ("carte.out");

const int Nmax = 3001;

int N, M, Tests;
char Text[Nmax];
int KMP[Nmax], DP[Nmax];
bitset<Nmax> B[Nmax];

void Solve();

int main()
{
    for (is >> Tests; Tests; --Tests)
        Solve();

    is.close();
    os.close();
}

void Solve()
{
    is >> Text;
    is >> N;

    string w;
    int Tsize = strlen(Text);

    for (int o = 1; o <= N; ++o)
    {
        is >> w;
        w += ' ';

        for (int i = 1, k = 0; i < w.size(); ++i)
        {
            while (k > 0 && w[k] != w[i])
                k = KMP[k-1];
            if (w[k] == w[i])
                ++k;
            KMP[i] = k;
        }

        for (int i = 0, k = 0; i < Tsize; ++i)
        {
            while (k > 0 && w[k] != Text[i])
                k = KMP[k-1];
            if (w[k] == Text[i])
                ++k;
            if (k == w.size()-1)
                B[i-w.size()+2][i] = 1;
        }
    }

    memset(DP, 0x3f3f3f3f, sizeof(DP));
    DP[0] = 0;

    for (int i = 1; i <= Tsize; ++i)
    {
        DP[i] = min(DP[i], DP[i-1]+1);
        for (int j = 1; j <= i; ++j)
            if (B[j-1][i-1] == 1)
                DP[i] = min(DP[i], DP[j-1]);
    }

    os << DP[Tsize] << '\n';
    for (int i = 0; i < Tsize; ++i)
        B[i].reset();
};
