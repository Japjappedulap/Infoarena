#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

ifstream is ("cerere.in");
ofstream os ("cerere.out");

int N, v[100004], S[100004], D[100004], K, root;
vector <int> G[100004];
bitset <100004> B, HF;

void DFS(int t);

int main()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
        is >> v[i];
    for (int i = 1, a, b; i < N; ++i)
    {
        is >> a >> b;
        G[a].push_back(b);
        HF[b] = 1;
    }
    for (int i = 1; i <= N; ++i)
        if (HF[i] == 0)
        {
            root = i;
            break;
        }
    B[root] = 1;
    DFS(root);
    for (int i = 1; i <= N; ++i)
        os << D[i] << ' ';
    is.close();
    os.close();
}

void DFS(int t)
{
    for (const auto& f : G[t])
        if (B[f] == 0)
        {
            if (v[f] == 0) S[++K] = 0;
            else           S[++K] = S[K-v[f]]+1;
            D[f] = S[K];
            B[f] = 1;
            DFS(f);
        }
    S[K--] = 0;
};






















