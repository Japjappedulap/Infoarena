#include <fstream>
using namespace std;

ifstream is ("taste.in");
ofstream os ("taste.out");

unsigned long long X, Y, L=0, R, M, A, B, p;
unsigned long long Pow[64] = {1};

unsigned long long OK(unsigned long long i);

int main()
{
    is >> X >> Y;
    for (int i = 1; i <= 63; ++i)
        Pow[i] = Pow[i-1]*2;
    R = Y;
    A = Y;
    while (L <= R)
    {
        M = L + (R-L)/2;
        p = OK(M);
        if (M * Pow[p] >= X && M*Pow[p] <= Y && A+B > M+p)
            A = M, B = p;
        if (M * Pow[p] < X)
            L = M+1;
        else
            R = M-1;
    }
    if (A == Y && B == 0)
        os << X << ' ' << 0;
    else
    {
        while (A%2 == 0)
            A/=2, B++;
        os << A << ' ' << B;
    }

    is.close();
    os.close();
}

unsigned long long OK(unsigned long long i)
{
    for (unsigned long long j = 0; j <= 63; ++j)
        if (i * Pow[j] >= X)
            return j;
};
