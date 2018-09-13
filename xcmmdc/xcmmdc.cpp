#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream is ("xcmmdc.in");
ofstream os ("xcmmdc.out");

int N, M, Q, KM;
int D[13][1010][1010], Log[1010], Sol[1010];

void CMMDC(int i, int j);
int GCD (int A, int B) { if (A == 0) return B; return GCD(B % A, A); }

int main()
{
    is >> N >> M >> KM >> Q;
    for (int i = 2; i <= max(N, M); ++i)
        Log[i] = Log[i / 2] + 1;

    for (int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            is >> D[0][i][j];

    for (int L = 1; (1 << L) <= (min(N, M)); ++L)
        for (int i = 1; i + (1 << L) - 1 <= N; ++i)
            for (int j = 1; j + (1 << L) - 1 <= M; ++j)
                D[L][i][j] = GCD(GCD(D[L-1][i][j], D[L-1][i + (1 << (L - 1))][j]),
                                   GCD(D[L-1][i][j + (1 << (L - 1))], D[L-1][i + (1 << (L - 1))][j + (1 << (L - 1))]));


    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            CMMDC(i, j);

    for (int i = 0, k; i < Q; ++i)
        is >> k, os << Sol[k] << '\n';

    is.close();
    os.close();
}

void CMMDC(int i, int j)
{
    int Min, Max, L, R, MID, gcd, Lg, i2, j2;
    Min = Max = 0;
    L = 1, R = min(N - i + 1, M - j + 1);
    while (L <= R)
    {
        MID = (L+R)/2;
        Lg = Log[MID];
        i2 = i + MID - (1 << Lg);
        j2 = j + MID - (1 << Lg);
        gcd = GCD(GCD(D[Lg][i][j], D[Lg][i][j2]), GCD(D[Lg][i2][j], D[Lg][i2][j2]) );
        if (gcd > KM)
            Min = MID+1, L = MID+1;
        else
            R = MID-1;
    }
    L = 1, R = min(N - i + 1, M - j + 1);
    while (L <= R)
    {
        MID = (L+R)/2;
        Lg = Log[MID];
        i2 = i + MID - (1 << Lg);
        j2 = j + MID - (1 << Lg);
        gcd = GCD(GCD(D[Lg][i][j], D[Lg][i][j2]), GCD(D[Lg][i2][j], D[Lg][i2][j2]) );
        if (gcd >= KM)
            Max = MID, L = MID+1;
        else
            R = MID-1;
    }
    for (int i = Min; i <= Max; ++i)
        Sol[i]++;
};























