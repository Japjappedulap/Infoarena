#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("prefix.in");
ofstream os ("prefix.out");

const int Nmax = 1000004;

int T;
char P[Nmax];
int D[Nmax];

void Solve()
{
    is >> (P+1);
    int N = strlen(P+1);
    for (int i = 2, k = 0; i <= N; ++i)
    {
        while (k > 0 && P[k+1] != P[i])
            k = D[k];
        if (P[k+1] == P[i])
            ++k;
        D[i] = k;
    }
    for (int i = N; i > 0; --i)
        if (D[i] != 0 && i % (i - D[i]) == 0)
        {
            os << i << '\n';
            return;
        }
    os << "0\n";
}

int main()
{
    for (is >> T; T; --T)
        Solve();
}
