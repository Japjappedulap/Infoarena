#include <fstream>
#include <cstring>
using namespace std;

int DP1[90000];
int DP2[90000];
#define AD 45000

ifstream is ("diamant.in");
ofstream os ("diamant.out");

int n, m, p, sum;

int main()
{
    is >> n >> m >> p;
    if (p > 44100 || p < -44100)
    {
        os << 0;
        return 0;
    }
    DP2[AD] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            sum += i*j;
            memcpy(DP1, DP2, sizeof(DP1));
            memset(DP2, 0, sizeof(DP2));
            for (int k = AD-sum; k <= AD+sum; ++k)
                DP2[k] = (DP1[k] + DP1[k+i*j] + DP1[k-i*j])%10000;
        }
    os << DP2[AD+p];
    is.close();
    os.close();
    return 0;
}
