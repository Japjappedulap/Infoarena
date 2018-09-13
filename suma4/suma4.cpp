#include <fstream>
using namespace std;

ifstream is ("suma4.in");
ofstream os ("suma4.out");

int N, S, M;
int A[58][58][58], Auto[58];
int D[58][58][58];

void Path_Generator(int k, int i, int j);

int main()
{
    is >> N;
    Auto[1] = 1;
    S = N;
    for (M = 1; S != 0; ++M)
    {
        S -= M*M;
        for (int j = 1; j <= M; ++j)
            for (int k = 1; k <= M; ++k)
                is >> A[M][j][k];
    }--M;
    for (int i = 2; i <= M; ++i)
        Auto[i] = Auto[i-1] + i*i;
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= M; ++j)
            D[M][i][j] = A[M][i][j];

    for (int k = M-1; k > 0; --k)
        for (int i = 1; i <= k; ++i)
            for (int j = 1; j <= k; ++j)
                D[k][i][j] = A[k][i][j] + min(min(D[k+1][i][j], D[k+1][i+1][j]), min(D[k+1][i][j+1], D[k+1][i+1][j+1]));

    os << M << ' ' << D[1][1][1] << '\n';
    Path_Generator(1, 1, 1);
    is.close();
    os.close();
}

void Path_Generator(int k, int i, int j)
{
    if (k > M) return;
    os << (Auto[k-1] + ((i-1)*k) + j) << ' ';
    if (D[k+1][i][j] + A[k][i][j] == D[k][i][j])
    {
        Path_Generator(k+1, i, j);
        return;
    }
    if (D[k+1][i][j+1] + A[k][i][j] == D[k][i][j])
    {
        Path_Generator(k+1, i, j+1);
        return;
    }
    if (D[k+1][i+1][j] + A[k][i][j] == D[k][i][j])
    {
        Path_Generator(k+1, i+1, j);
        return;
    }
    if (D[k+1][i+1][j+1] + A[k][i][j] == D[k][i][j])
    {
        Path_Generator(k+1, i+1, j+1);
        return;
    }
};
















