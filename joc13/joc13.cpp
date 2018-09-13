#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("joc13.in");
ofstream os ("joc13.out");

int D[2][5003][11];
int A[2][5003], N, K;

int main()
{
    is >> N >> K;
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j <= N; ++j)
            is >> A[i][j];

    memset(D, -0x3f3f3f3f, sizeof(D));

    D[0][1][1] = A[0][1];
    D[1][1][1] = A[0][1] + A[1][1];

    for (int j = 2; j <= N; ++j)
    {
        for (int i = 0; i < 2; ++i) //calculam valorile pentru intrare in celula din <-
        {
            for (int k = 2; k <= min(K, j); ++k)
                D[i][j][k] = max(D[i][j-1][k-1]+A[i][j], D[i][j][k]);


        }
        for (int i = 0; i < 2; ++i)
            for (int k = 2; k <= min(K, j); ++k)
                D[i][j][1] = max(D[(i+1)%2][j][k]+A[i][j], D[i][j][1]);

    }
    int mx = -0x3f3f3f3f;
    for (int i = 1; i <= K; ++i)
        mx = max(mx, D[1][N][i]);
    os << mx;

}
