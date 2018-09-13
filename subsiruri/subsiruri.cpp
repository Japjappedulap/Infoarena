#include <fstream>
using namespace std;

ifstream is ("subsiruri.in");
ofstream os ("subsiruri.out");

int n, lmax, result;
int v[1002], DP[1002], S[1002];


int main()
{
    is >> n;
    for (int i = 1; i <= n; ++i)
    {
        is >> v[i];
        DP[i] = 1;
        for (int j = i-1; j >= 1; --j)
            if (v[i] > v[j] && DP[i] < DP[j]+1)
                DP[i] = DP[j]+1, lmax = max(lmax, DP[i]);
        for (int j = i-1; j >= 1; --j)
            if (DP[i] == DP[j] + 1 && v[i] > v[j])
                S[i] += S[j];
        if (S[i] == 0) S[i] = 1;
        S[i] %= 9901;
    }
    for (int i = 1; i <= n;++i)
        if (DP[i] == lmax)
            result = (result + S[i]) % 9901;
    os << lmax << '\n' << result;
    is.close();
    os.close();
    return 0;
}
