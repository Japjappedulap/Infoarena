#include <fstream>
#include <vector>
using namespace std;

ifstream is ("iepuri2.in");
ofstream os ("iepuri2.out");

const int MOD = 30011;
using VI = vector <int>;

int N, K, root;
bool B[101];

VI G[101], Vroot;

VI DFS(int);

int main()
{
    is >> N >> K;
    for (int i = 1, a, b; i < N; ++i)
    {
        is >> a >> b;
        B[b] = 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i)
        if (B[i] == 0)
        {
            B[i] = 1;
            root = i;
            break;
        }
    Vroot = DFS(root);

    os << Vroot[K] << '\n';
    is.close();
    os.close();
}

VI DFS(int node)
{
    B[node] = 0;
    VI vnode(K+1, 1), sum(K+1);
    for (int i = 1; i <= K; ++i)
        sum[i] = i;
    VI vson;
    int tmp, Ax;
    for (const auto& son : G[node])
    {
        if (B[son] == 0) continue;
        vson = DFS(son);
        for (int i = 1; i <= K; ++i)
        {
            Ax = 0;
            tmp = (vson[K]-vson[i]);
            if (tmp < 0 )
                tmp += MOD;
            Ax = (Ax + vnode[i] * tmp) % MOD;
            vnode[i] = Ax;
        }
    }
    for (int i = 1; i <= K; ++i)
    {
        sum[i] = sum[i-1] + vnode[i];
        if (sum[i] >= MOD)
            sum[i] -= MOD;
    }
    return sum;
};


















