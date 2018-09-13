#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int Nmax = 127;
const int Di[] = {-1, 0, 1, 0};
const int Dj[] = {0, 1, 0, -1};

int N, M, sol, val;
int V[Nmax][Nmax];
int D[Nmax][Nmax];

void DF(int i, int j);
bool Ok(int i, int j);

int main()
{
    freopen("bila.in", "r", stdin);
    freopen("bila.out", "w", stdout);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &V[i][j]);
    memset(D, -1, sizeof(D));

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (D[i][j] == -1)
                DF(i, j);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (D[i][j] > sol)
                sol = D[i][j], val = V[i][j];
            else
                if (D[i][j] == sol && val > V[i][j])
                    val = V[i][j];

    printf("%d %d", sol, val);
}

void DF(int i, int j)
{
    int iv, jv, mn = V[i][j];
    for (int d = 0; d < 4; ++d)
    {
        iv = i + Di[d];
        jv = j + Dj[d];
        if (Ok(iv, jv) && mn > V[iv][jv])
            mn = V[iv][jv];
    }
    if (mn == V[i][j])
    {
        D[i][j] = 1;
        return;
    }
    for (int d = 0; d < 4; ++d)
    {
        iv = i + Di[d];
        jv = j + Dj[d];
        if (Ok(iv, jv) && mn == V[iv][jv] && D[iv][jv] == -1)
            DF(iv, jv), D[i][j] = D[iv][jv] + 1;
        else
            if (Ok(iv, jv) && mn == V[iv][jv] && D[iv][jv] != -1)
                D[i][j] = D[iv][jv]+1;
    }
};

bool Ok(int i, int j)
{
    if (i < 1 || i > N || j < 1 || j > M) return 0;
    return 1;
};


















