#include <cstdio>
using namespace std;

int N, D[257][257], Ap[257][257];

int main()
{
    freopen("rf.in", "r", stdin);
    freopen("rf.out", "w", stdout);
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", &D[i][j]), Ap[i][j] = 1;

    for (int i = 1; i <= N; ++i)
        Ap[i][i] = 0;

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                if (i != j && j != k && D[i][k] && D[k][j] && D[i][j] == D[i][k] + D[k][j] && Ap[i][j] < Ap[i][k] + Ap[k][j])
                    Ap[i][j] = Ap[i][k] + Ap[k][j];
                if (i != j && j != k && D[i][k] && D[k][j] && (D[i][j] > D[i][k] + D[k][j] || !D[i][j]))
                    D[i][j] = D[i][k] + D[k][j], Ap[i][j] = Ap[i][k] + Ap[k][j];
            }

    for (int i = 1; i <= N; ++i, printf("\n"))
        for (int j = 1; j <= N; ++j)
            printf("%d ", D[i][j]);

    for (int i = 1; i <= N; ++i, printf("\n"))
        for (int j = 1; j <= N; ++j)
            printf("%d ", Ap[i][j]);
}
