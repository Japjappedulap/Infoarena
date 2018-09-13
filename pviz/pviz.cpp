#include <fstream>
using namespace std;

ifstream is ("pviz.in");
ofstream os ("pviz.out");

int N, M, X[2001], D[2001][2001];

int main()
{
    is >> N >> M;
    for (int i = 1; i <= N; ++i)
        is >> X[i];
    D[0][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            D[i][j] = (D[i-1][j-1] + D[i-1][j]*(X[j]-i+1)) % 10007;
    os << D[N][M];
    is.close();
    os.close();
}
