#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("expozitie.in");
ofstream os ("expozitie.out");

short n, d, k;
short L1[503][500], L2[503][500];

void Solve();
void Add(short j);


int main()
{
    is >> n >> d >> k;
    Solve();
    is.close();
    os.close();
    return 0;
}

void Solve()
{
    if (n < d*k) {os << 0; return;}
    if (n == d*k) {os << 1; return;}
    n -= (d*k);
    for (short i = 1; i <= d; ++i)
        L2[i][0] = 1, L2[i][1] = i;
    for (short i = 2; i <= n; ++i)
    {
        memcpy(L1, L2, sizeof(L1));
        memset(L2,  0, sizeof(L2));
        L2[1][0] = 1, L2[1][1] = 1;
        for (short j = 2; j <= d; ++j)
            Add(j);
    }
    for (short i = L2[d][0]; i > 0; --i)
        os << L2[d][i];
};

void Add(short j)
{
    short i, t = 0;
    for (i = 1; i <= L2[j-1][0] || i <= L1[j][0] || t; ++i, t /= 10)
    {
        L2[j][i] = (t += L2[j-1][i] + L1[j][i]) % 10;
    }
    L2[j][0] = i-1;
};
