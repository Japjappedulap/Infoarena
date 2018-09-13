#include <fstream>
using namespace std;

ifstream is ("order.in");
ofstream os ("order.out");

int N, P, x, pos;
int Arb[120003];

void Build(int n, int L, int R);
void Update(int n, int L, int R);

int main()
{
    is >> N;
    Build(1, 1, N);

    pos = 1;
    P = N;
    for (int i = 1; i <= N; ++i)
    {
        pos += i;
        if (i != 1)
            pos -= 1;
        if (pos > P)
            pos %= P;
        x = pos;
        if (pos == 0)
            x = pos = P;
        if (i == N)
            x = pos = 1;
        Update(1, 1, N);
    }
    is.close();
    os.close();
}

void Update(int n, int L, int R)
{
    if (L == R)
    {
        os << L << ' ';
        Arb[n] = 0;
        return;
    }
    int M = (L + R) / 2;
    if (x <= Arb[2*n])
        Update(2*n, L, M);
    else
        x -= Arb[2*n], Update(2*n+1, M+1, R);
    Arb[n] = Arb[2*n] + Arb[2*n+1];
    P = Arb[n];
};


void Build(int n, int L, int R)
{
    if (L == R)
    {
        Arb[n] = 1;
        return;
    }
    int M = (L + R) / 2;
    Build(2*n, L, M);
    Build(2*n+1, M+1, R);
    Arb[n] = Arb[2*n] + Arb[2*n+1];
};
