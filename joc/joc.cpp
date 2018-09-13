#include <fstream>
using namespace std;

ifstream is ("joc.in");
ofstream os ("joc.out");

int N, M, A[1001][1001], D[1001][1001], Mx[1001][1001], X, I, J;

int main()
{
    X = -(1<<18);
    is >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            is >> A[i][j], D[i][j] = X;

    Mx[1][1] = D[1][1] = A[1][1];
    for (int i = 2; i <= N; ++i)
    {
        D[i][1] = A[i][1] - Mx[i-1][1];
        Mx[i][1] = max(Mx[i-1][1], D[i][1]);
        if (Mx[i][1] > X)
                X = Mx[i][1], I = i, J = 1;
    }
    for (int j = 2; j <= M; ++j)
    {
        D[1][j] = A[1][j] - Mx[1][j-1];
        Mx[1][j] = max(Mx[1][j-1], D[1][j]);
        if (Mx[1][j] > X)
                X = Mx[1][j], I = 1, J = j;
    }
    for (int i = 2; i <= N; ++i)
        for (int j = 2; j <= M; ++j)
        {
            D[i][j] = A[i][j] - max(Mx[i][j-1], Mx[i-1][j]);
            Mx[i][j] = max(Mx[i][j-1], max(Mx[i-1][j], D[i][j]));
            if (Mx[i][j] > X)
                X = Mx[i][j], I = i, J = j;
        }
    os << X << ' ' << I << ' ' << J << '\n';
    is.close();
    os.close();
}
