#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("petrecere.in");
ofstream os ("petrecere.out");

short n, A(2), B(1), C(3);
short D[4][3050];

void Add(short a, short b, short c);
void Mult(short C, short k);

int main()
{
    is >> n;
    if (n == 1)
        os << 1;
    else
    {
    D[1][1] = 1;
    D[2][1] = 2;
    D[2][0] = D[1][0] = 1;
    for (short i = 3; i <= n; ++i)
    {
        swap(C, B);
        swap(A, B);
        memset(D[A], 0, sizeof(D[A]));
        Mult(C, i-1);
        Add(A, B, C);

    }
    for (short i = D[A][0]; i >= 1; --i)
        os << D[A][i];
    }

    is.close();
    os.close();
    return 0;
}

void Mult(short x, short k)
{
    short i, t = 0;
    for (i = 1; i <= D[x][0] || t; ++i, t /= 10)
        D[x][i] = (t += D[x][i] * k) % 10;
    D[x][0] = i-1;
};

void Add(short a, short b, short c)
{
    short i, t = 0;
    for (i = 1; i <= D[b][0] || i <= D[c][0] || t; ++i, t /= 10)
        D[a][i] = (t += D[b][i] + D[c][i]) % 10;
    D[a][0] = i-1;
};
