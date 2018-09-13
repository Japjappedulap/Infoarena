#include <fstream>
using namespace std;

#define MOD 666013

ifstream is ("perm4.in");
ofstream os ("perm4.out");

int N, K;
int D[3][3002], CL = 1, PL = 2;

int main()
{
    is >> N >> K;
    D[1][0] = D[2][0] = D[2][1] = 1;
    for (int i = 3; i <= N; ++i, swap(CL, PL))
        for (int j = 0; j < i; ++j)
            D[CL][j] = (D[PL][j-1] + D[PL][j+1] * (j+1) + D[PL][j] * (i-j-1)) % MOD;
    os << D[PL][K];
    return 0;
}
