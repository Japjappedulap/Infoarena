#include <fstream>
#include <cstdlib>
using namespace std;

ifstream is ("oras.in");
ofstream os ("oras.out");

int G[204][204];
int N;

void Solve(int k);

int main()
{
    is >> N;
    Solve(N);
    for (int i = 1; i <= N; ++i, os << '\n')
        for (int j = 1; j <= N; ++j)
            os << G[i][j];
    is.close();
    os.close();
}

void Solve(int k)
{
    if (k < 3 || k == 4)
    {
        os << -1;
        exit(0);
    }
    if (k == 3)
    {
        G[1][2] = G[2][3] = G[3][1] = 1;
        return;
    }
    if (k == 6)
    {
        G[1][2] = G[1][4] = G[1][6] = 1;
        G[2][3] = G[2][5] = G[2][6] = 1;
        G[3][1] = G[3][5] = 1;
        G[4][2] = G[4][3] = G[4][5] = 1;
        G[5][1] = G[5][6] = 1;
        G[6][4] = G[6][3] = 1;
        return;
    }
    Solve(k-2);
    for (int i = 1; i < k-1; ++i)
        G[i][k] = 1, G[k-1][i] = 1;
    G[k][k-1] = 1;
};
