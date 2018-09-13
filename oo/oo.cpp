#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("oo.in");
ofstream os ("oo.out");

int a[100001], dp[100001];
int n, res;


int main()
{
    is >> n;
    for (int i = 1; i <= n; ++i)
        is >> a[i];
    for (int i = 3; i <= n-1; ++i)
    {
        if (i < 3)   dp[i] = max(dp[i-1], a[i]+a[i-1]);
        else dp[i] = max(dp[i-1], dp[i-3]+a[i]+a[i-1]);
        res = max(dp[i], res);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 5; i <= n-1; ++i)
    {
        if (i < 3)   dp[i] = max(dp[i-1], a[i]+a[i-1]);
        else dp[i] = max(dp[i-1], dp[i-3]+a[i]+a[i-1]);
        res = max(dp[i]+a[1]+a[2], res);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 4; i <= n-2; ++i)
    {
        if (i < 3)   dp[i] = max(dp[i-1], a[i]+a[i-1]);
        else dp[i] = max(dp[i-1], dp[i-3]+a[i]+a[i-1]);
        res = max(dp[i]+a[1]+a[n], res);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 3; i <= n-3; ++i)
    {
        if (i < 3)   dp[i] = max(dp[i-1], a[i]+a[i-1]);
        else dp[i] = max(dp[i-1], dp[i-3]+a[i]+a[i-1]);
        res = max(dp[i]+a[n]+a[n-1], res);
    }
    os << res;
    is.close();
    os.close();
    return 0;
}
