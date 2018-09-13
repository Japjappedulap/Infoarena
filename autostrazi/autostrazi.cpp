#include <fstream>
#include <vector>
using namespace std;

ifstream is ("autostrazi.in");
ofstream os ("autostrazi.out");

using VI = vector<int>;
const int MOD = 30011;
int N, K, S, sol;
int R[101];
VI G[101];
bool Viz[101];

VI DFS(int x);

int main()
{
    is >> N >> S >> K;
    for (int i = 1; i <= K; ++i)
        is >> R[i];
    for (int i = 1, a, b; i < N; ++i)
    {
        is >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    VI Sol = DFS(1);
    for (int i = 0; i <= S; ++i)
        sol += Sol[i];
    sol %= MOD;
    os << sol;
    is.close();
    os.close();
}

VI DFS(int x)
{
    Viz[x] = 1;
    VI X(S + 1);
    X[0] = 1;
    for (const int& f : G[x])
    {
        if (Viz[f] == 1) continue;

        VI F = DFS(f);
        VI Ax(S + 1);

        for (int i = 0, r; i <= K; ++i)
            for (int k = 0; k + R[i] <= S; ++k)
                for (int j = 0; j + k + R[i] <= S; ++j)
                {
                    r = max(j, k + R[i]);
                    Ax[r] = (Ax[r] + X[j] * F[k]) % MOD;
                }
        X = Ax;
    }
    return X;
};



























