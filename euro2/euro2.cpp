#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("euro2.in");
ofstream os ("euro2.out");

int n, V1[10005], V2[10005], y;
int lg1 = 1, lg2 = 1;
short D1[10005], D2[10005], L1[10005], L2[10005], sol = 1;
string x;

int BS1(int x);
int BS2(int x);
void Read();

int main()
{
    Read();
    D1[1] = L1[1] = 1;
    L2[1] = D2[1] = 1;
    int pos;
    for (int i = 2; i <= n; ++i)
    {
        pos = BS1(V1[i]);
        D1[i] = pos+1;
        L1[pos+1] = i;
        if (lg1 < pos+1) lg1 = pos+1;
    }
    for (int i = 2; i <= n; ++i)
    {
        pos = BS2(V2[i]);
        D2[i] = pos+1;
        L2[pos+1] = i;
        if (lg2 < pos+1) lg2 = pos+1;
    }
    for (int i = 1, j = n; i <= n; ++i, --j)
        if (D1[i] + D2[j] > sol && D1[i] >= 2 && D2[j] >= 2)
            sol = D1[i] + D2[j];
    os << sol-1;


    is.close();
    os.close();
    return 0;
}

int BS1(int x)
{
    int l = 0, r = lg1, M;
    while (l <= r)
    {
        M = (l+r)/2;
        if (V1[L1[M]] < x && V1[L1[M+1]] >= x) return M;
        else if (V1[L1[M]] < x)   l = M+1;
        else                    r = M-1;
    }
    return lg1;
};

int BS2(int x)
{
    int l = 0, R = lg2, M;
    while (l <= R)
    {
        M = (l+R)/2;
        if (V2[L2[M]] < x && V2[L2[M+1]] >= x) return M;
        else if (V2[L2[M]] < x)   l = M+1;
        else                    R = M-1;
    }
    return lg2;
};

void Read()
{
    is >> n;
    for (int i = 1, j = n; i <= n; ++i, --j)
    {
        is >> x;
        for (int k = 2; k <= 5; ++k) x[k-1] = x[k];
        y = 0;
        for (int k = 0; k <= 5; ++k) y = y*10 + x[k]-'0';
        V1[i] = V2[j] = y;
    }
};
