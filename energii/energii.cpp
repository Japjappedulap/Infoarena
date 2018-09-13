#include <fstream>
#define INF 2000000000
using namespace std;

ifstream is ("energii.in");
ofstream os ("energii.out");

int G, W;
int E[1001], C[1001], DP[5001];

int main()
{
    is >> G >> W;
    for (int i = 1; i <= G; ++i)
        is >> E[i] >> C[i];
    for (int i = 1; i <= W; ++i)
        DP[i] = INF;

    for (int i = 1; i <= G; ++i)
        for (int j = W; j >= 0; --j)
            if (j-E[i] >= 0)
            {
                if (DP[j] > DP[j-E[i]] + C[i]) DP[j] = DP[j-E[i]] + C[i];
            }
            else DP[j] = min(DP[j], C[i]);
    if (DP[W] != INF)   os << DP[W];
    else                os << -1;
    is.close();
    os.close();
    return 0;
}
