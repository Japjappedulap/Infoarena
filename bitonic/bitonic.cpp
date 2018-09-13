#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("bitonic.in");
ofstream os ("bitonic.out");

int n, T, res, pos, V[1001], DP[1001], B[1001], nr, DPI[1001], V2[1001], DP2[1001], B2[1001], nr2, DPI2[1001];

void Solve();
int BS(int x);
int BS2(int x);

int main()
{
    is >> T;
    for (int t = 0; t < T; ++t)
        Solve();
    is.close();
    os.close();
    return 0;
};

void Solve()
{
    memset(DP, 0 , sizeof(DP));memset(DP2, 0 , sizeof(DP2));memset(B, 0 , sizeof(B));memset(B2, 0 , sizeof(B2));memset(V, 0 , sizeof(V));memset(V2, 0 , sizeof(V2));res = 0;
    is >> n;
    for (int i = 1, j = n; i <= n; ++i, --j) is >> V[i], V2[j] = V[i];
    DP[1] = B[1] = 1; nr = 1; DP2[1] = B2[1] = 1, nr2 = 1; DPI[1] = DPI2[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        pos = BS(V[i]);
        DP[i] = pos+1, B[pos+1] = i;
        if (nr < pos+1) nr = pos+1;
    }
    for (int i = 2; i <= n; ++i)
    {
        pos = BS2(V2[i]);
        DP2[i] = pos+1, B2[pos+1] = i;
        if (nr2 < pos+1) nr2 = pos+1;
    }
    for (int i = 1; i <= n; ++i, DPI[i] = 1)
        for (int j = 1; j < i; ++j)
            if (DPI[i] <= DPI[j]+1 && V[i] < V[j]) DPI[i] = DPI[j]+1;
    for (int i = 1; i <= n; ++i, DPI2[i] = 1)
        for (int j = 1; j < i; ++j)
            if (DPI2[i] <= DPI2[j]+1 && V2[i] < V2[j]) DPI2[i] = DPI2[j]+1;
    for (int i = 1, j = n; i <= n; ++i, --j)
    {
        if (DP2[j] + DP[i]-1 > res) res = DP2[j]+DP[i]-1;
        if (DPI[i] + DPI2[j]-1 > res) res = DPI[i] + DPI2[j]-1;
    }
    os << res << '\n';
};

int BS(int x)
{
    int L = 0, R = nr, M;
    while (L <= R)
    {
        M = (L+R)/2;
        if (V[B[M]] < x && V[B[M+1]] >= x) return M;
        else    if (V[B[M]] < x) L = M+1;
        else                     R = M-1;
    }
    return nr;
};

int BS2(int x)
{
    int L = 0, R = nr2, M;
    while (L <= R)
    {
        M = (L+R)/2;
        if (V2[B2[M]] < x && V2[B2[M+1]] >= x) return M;
        else    if (V2[B2[M]] < x) L = M+1;
        else                     R = M-1;
    }
    return nr2;
};
