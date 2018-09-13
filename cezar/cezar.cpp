#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

using VI = vector <int>;
using VS = vector <short>;
using PII = pair<short,int>;

int N, K;
VS G[10001];
VI F;

struct CMP{ bool operator () (short a, short b) { return F[a]>F[b]; }};
priority_queue<short, VS, CMP> Q;

void Read();
void Solve();

int main()
{
    Read();
    Solve();
}

void Read()
{
    freopen("cezar.in", "r", stdin);

    scanf("%i%i", &N, &K);
    F = VI(N+1, 1);
    for (int i = 1, a, b; i < N; ++i)
    {
        scanf("%i%i", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
};

void Solve()
{
    freopen("cezar.out", "w", stdout);
    for (int i = 1; i <= N; ++i)
        if (G[i].size() == 1)
            Q.push(i);
    int M = N-1-K, sol = 0;
    for (int node, next, k = 1; k <= M; ++k)
    {
        node = Q.top();
        Q.pop();
        next = G[node][0];
        F[next] += F[node];
        sol += F[node];
        G[node].clear();
        for (auto ax = G[next].begin(); ax != G[next].end(); ++ax)
            if (*ax == node)
            {
                G[next].erase(ax);
                break;
            }
        if (G[next].size() == 1)
            Q.push(next);
    }
    printf("%i", sol);
};
