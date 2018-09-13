#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("pufarina.in");
ofstream os ("pufarina.out");

int x, T, n, v[15], cmmdc, s;
double aux;

int CMMDC(int x, int y);

int main()
{
    is >> T;
    for (int t = 0; t < T; ++t)
    {
        is >> n;
        cmmdc = 20000000;
        s = 0;
        for (int i = 1; i <= n; ++i)
        {
            is >> aux;
            aux += 0.0005;
            v[i] = aux * 1000;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cmmdc = min(cmmdc, CMMDC(v[i], v[j]));
        for (int i = 1; i <= n; ++i)
        {
            v[i]/=cmmdc;
            s += v[i];
        }
        if (s > 50000)
            os << "ALEGERI FRAUDATE";
        else
            os << s;
        os << '\n';
        memset(v, 0, sizeof(v));
    }
    is.close();
    os.close();
    return 0;
}

int CMMDC(int x, int y)
{
    if (x == y)
        return x;
    int r;
    r = x % y;
    while (r)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
};
