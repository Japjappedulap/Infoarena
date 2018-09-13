/*
Drumuri1 - Constantin Galatan - Lot Juniori Sovata 2014
*/
#include <fstream>
using namespace std;

ifstream is ("drumuri1.in");
ofstream os ("drumuri1.out");

const int MOD = 31607;
const int Nsize = 251;

int N, M, K, L;
bool J[Nsize][Nsize];
int D[3][Nsize][Nsize], lc, lp;

void Read();
void Dynamic();

int main()
{
    Read();
    Dynamic();
    is.close();
    os.close();
}

void Read()
{
    is >> N >> M >> K >> L;
    for (int a, b; M; --M)
    {
        is >> a >> b;
        J[a][b] = 1;
    }
};

void Dynamic()
{
    lc = 1, lp = 0;
    if (J[1][1] == 0)
        D[lc][1][0] = 1;
    if (J[1][1] == 1)
        D[lc][1][1] = 1;

    int Sol = 0;
    for (int i = 1; i <= N; ++i, swap(lc, lp))
    {
        for (int j = 1; j <= N; ++j)
        {
            if (J[i][j] == 1)
                for (int k = 1; k <= K; ++k)
                {
                    D[lc][j][k] += (D[lc][j-1][k-1] + D[lp][j][k-1]);
                    if (D[lc][j][k] >= MOD)
                        D[lc][j][k] -= MOD;
                }
            else
                for (int k = 0; k <= K; ++k)
                {
                    D[lc][j][k] += (D[lc][j-1][k] + D[lp][j][k]);
                    if (D[lc][j][k] >= MOD)
                        D[lc][j][k] -= MOD;
                }
            if (i+j == L+1)
            {
                Sol += D[lc][j][K];
                if (Sol >= MOD)
                    Sol -= MOD;
            }
        }
        for (int j = 1; j <= N; ++j)
            for (int k = 0; k <= K; ++k)
                D[lp][j][k] = 0;
    }
    os << Sol;
};



















