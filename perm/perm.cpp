#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("perm.in");
ofstream os ("perm.out");

short N, K;
short D[2][203][400], Lc, Lp;
short Aux[400];

void Add(short A[], short B[])
{
      short i, t = 0;
      for (i = 1; i <= A[0] || i <= B[0] || t; i++, t /= 10)
              A[i] = (t += A[i] + B[i]) % 10;
      A[0] = i - 1;
}

void Multiply(short A[], short B)
{
      short i, t = 0;
      for (i = 1; i <= A[0] || t; i++, t /= 10)
              A[i] = (t += A[i] * B) % 10;
      A[0] = i - 1;
}

void SHOW(short i, short j)
{
    for (short x = D[i][j][0]; x > 0; --x)
        os << D[i][j][x];
    os << ' ';
}

int main()
{
    is >> N >> K;
    Lc = 1;

    D[0][1][0] = 1;
    D[0][1][1] = 1;

    for (short i = 2; i <= N; ++i, swap(Lc, Lp))
    {
        for (short j = 1; j <= i; ++j)
            memset(D[Lc][j], 0, sizeof(D[Lc][j]));
        for (short j = 1; j <= i; ++j)
        {
            memset(Aux, 0, sizeof(Aux));
            Add(D[Lc][j], D[Lp][j-1]);
            Add(Aux, D[Lp][j]);
            Multiply(Aux, (i-1));
            Add(D[Lc][j], Aux);
        }
    }
    SHOW(Lp, K);

}
