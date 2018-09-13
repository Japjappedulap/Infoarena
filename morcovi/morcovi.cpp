#include <fstream>
#include <iomanip>
using namespace std;

ifstream is ("morcovi.in");
ofstream os ("morcovi.out");

int N, P, S[12], Sol;
int D[1<<12][1001];

void Print(int x)
{
    if (x == 0) return;

    Print(x/2);
os << x%2;
}

int main()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
        is >> D[0][i];
    is >> P;
    for (int i = 0; i < P; ++i)
        is >> S[i];

    for (int mask = 1; mask < (1<<P); ++mask)
        for (int i = 1; i <= N; ++i)
            for (int p = 0; p < 12; ++p)
                if ( (mask & (1 << p)) != 0 )
                {
                    if (i + S[p] <= N)
                        D[mask][i] = max(D[mask][i], D[mask & ~(1<<p)][i + S[p]] + D[0][i]) ;
                    if (i - S[p] > 0)
                        D[mask][i] = max(D[mask][i], D[mask & ~(1<<p)][i - S[p]] + D[0][i]) ;
                }
    for (int i = 1; i <= N; ++i)
        Sol = max(Sol, D[(1<<P)-1][i]);
    os << Sol;


    is.close();
    os.close();
}
