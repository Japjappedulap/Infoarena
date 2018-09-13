#include <iomanip>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;

const int Nmax = 17;
const int INF = 0x3f3f3f3f;

ifstream is ("smin.in");
ofstream os ("smin.out");


int N;
int X[Nmax], Y[Nmax];
int D[1<<Nmax];


inline int Area(int A, int B, int C);

int main()
{
    is >> N;
    for (int i = 0; i < N; ++i)
        is >> X[i] >> Y[i];

    memset(D, INF, sizeof(D));
    D[0] = 0;

    for (int mask = 0, Nextmask, A; mask < (1<<N); ++mask)
    {
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                for (int k = j+1; k < N; ++k)
                    {
                        Nextmask = mask | (1<<i) | (1<<j) | (1<<k);
                        A = Area(i, j, k);
                        if (D[Nextmask] > D[mask] + A)
                            D[Nextmask] = D[mask] + A;
                    }

    }
    os << fixed;
    os << double(D[(1<<N)-1])/2;
}

inline int Area(int A, int B, int C)
{
    return abs((X[B] - X[A]) * (Y[C] - Y[A]) - (X[C] - X[A]) * (Y[B] - Y[A]));
};











