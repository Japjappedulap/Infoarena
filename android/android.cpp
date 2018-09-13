#include <fstream>
#include <cmath>
using namespace std;

ifstream is ("android.in");
ofstream os ("android.out");

const int MOD = 666013;

int N, M;
int D[1<<20][20];
int Matrix[20][20];

int GetNth(int i, int j);
int GCD(int A, int B);

void Input();

int main()
{
    Input();
    int sol = 0;
    for (int i = 0; i < N*M; ++i)
        D[0][i] = D[1<<i][i] = 1;
    for (int mask = 1; mask < (1<<(N*M)); ++mask)
        for (int mainbit = 0; mainbit < N*M; ++mainbit)
        {

            if (mask & (1<<mainbit))   //checkbit
                for (int bit = 0; bit < N*M; ++bit)
                    if (bit != mainbit && mask & (1<<bit) && (Matrix[bit][mainbit] & mask) == Matrix[bit][mainbit])
                    {
                        D[mask][mainbit] += D[mask - (1<<mainbit)][bit];
                        if (D[mask][mainbit] >= MOD)
                            D[mask][mainbit] -= MOD;
                    }

            sol += D[mask][mainbit];
            if (sol >= MOD)
                sol -= MOD;
        }

    os << sol;
    is.close();
    os.close();
}


void Input()
{
    is >> N >> M;
    for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
        for (int x = 0; x < N; ++x)
        for (int y = 0; y < M; ++y)
        {
            int gcd = GCD(abs(i-x), abs(j-y));
            if (gcd == 0)
                continue;
            int k = i, l = j;
            for (int p = 1; p < gcd; ++p)
            {
                k -= (i-x) / gcd;
                l -= (j-y) / gcd;
                Matrix[GetNth(i, j)][GetNth(x, y)] |= (1 << GetNth(k, l));
            }
        }


};

int GetNth(int i, int j)
{
    return M * i + j;
};

int GCD(int A, int B)
{
   if(B == 0) return A;
   A %= B;
   return GCD(B, A);
}
