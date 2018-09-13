#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#define INF 625e10

ifstream is ("calatorie.in");
ofstream os ("calatorie.out");

long long n, T;
long long N[52], K[52], MSS;
long long DP[52][520], sol;
bool D[520];

int main()
{
    is >> T;
    for (long long t = 0; t < T; ++t)
    {
        is >> n;
        for (long long i = 1; i < n; ++i)
            is >> N[i] >> K[i], DP[i][0] = DP[i-1][0] + N[i], MSS += K[i];
        for (long long i = 0; i < n; ++i)
            for (long long j = 1; j <= MSS; ++j)
                DP[i][j] = INF;
        D[0] = true;
        for (long long i = 1; i < n; ++i)
            for (long long j = MSS; j >= 0; --j)
            {
                if (D[j] == true)
                    DP[i][j] = DP[i-1][j]+N[i];
                if (K[i] <= j && D[j-K[i]] == true)
                    D[j] = true, DP[i][j] = min(DP[i-1][j-K[i]], DP[i][j]);
            }
        sol = INF;
        for (long long j = 0; j <= MSS; ++j)
            sol = min(sol, DP[n-1][j]+(j*j*j*j));
        os << "Consumul minim = " <<  sol << '.' << '\n';
        MSS = 0, n = 0, memset(N, 0, sizeof(N)), memset(K, 0, sizeof(K)), memset(D, 0, sizeof(D)), memset(DP, 0, sizeof(DP));
    }

    is.close();
    os.close();
    return 0;
}
