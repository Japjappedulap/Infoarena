#include <fstream>
#include <vector>
using namespace std;

ifstream is ("sir23.in");
ofstream os ("sir23.out");

int N;
int D[1001][1001];
int X[1001][1001];

int main()
{
    is >> N;

    for (int i = 1; i <= N; i++) { D[1][i] = i; D[2][i] = i * i; }

    for (int i = 3; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            if (j >= 2)
                X[i][j] = (X[i][j-1] + D[i-2][j-2]) % 1000000;
            D[i][j] = (D[i][j-1] + D[i-1][j-1] + D[i-2][j-1] + X[i][j]) % 1000000;
        }

    os << D[N][N];

    is.close();
    os.close();
}
