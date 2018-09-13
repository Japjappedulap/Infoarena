#include <cstdio>
#include <vector>
using namespace std;

int N, v[105], Nr, ES[105], LS[105];
vector <int> G[105], Gt[105];

void DFS(int k);
void DFS2(int k);

int main()
{
    freopen("pm2.in", "r", stdin);
    freopen("pm2.out", "w", stdout);
    scanf("%i", &N);
    Nr = N+2;
    for (int i = 1; i <= N; ++i)
        scanf("%i", &v[i]);
    for (int i = 1, M; i <= N; ++i)
    {
        scanf("%i", &M);
        for (int j = 1, x; j <= M; ++j)
            scanf("%i", &x), G[x].push_back(i), Gt[i].push_back(x);
        if (M == 0)
            G[0].push_back(i), Gt[i].push_back(0);
        G[i].push_back(N+1);
        Gt[N+1].push_back(i);
    }
    for (int i = 0; i <= N; ++i)
        ES[i] = -999999999, LS[i] = 999999999;
    ES[0] = 0;
    DFS(0);
    LS[N+1] = ES[N+1];
    DFS2(N+1);
        printf("%i\n", ES[N+1]);
    for (int i = 1; i <= N; ++i)
        printf("%i %i\n", ES[i], LS[i]-v[i]);
}

void DFS(int k)
{
    for (const auto&f : G[k])
        if (ES[f] < ES[k]+v[k])
            ES[f] = ES[k]+v[k], DFS(f);
};

void DFS2(int k)
{
    for (const auto&f : Gt[k])
        if (LS[f] > LS[k]-v[k])
            LS[f] = LS[k]-v[k], DFS2(f);
}
