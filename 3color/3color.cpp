#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <cstring>
using namespace std;

ifstream is ("3color.in");
ofstream os ("3color.out");

int N, M;
int D[1004];
vector <int> G[1004];
bitset <1004> B;
bool Bm[190];

queue <int> Q;

void BF(int node);
int GetMinimum(int node);

int main()
{
    is >> N >> M;
    for (int i = 1, a, b; i <= M; ++i)
    {
        is >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < N; ++i)
        if (D[i] == 0)
            BF(i);
    for (int i = 0; i < N; ++i)
        os << D[i]-1 << ' ';
    is.close();
    os.close();
}

void BF(int nod)
{
    int i, j;
    D[nod] = 1;
    B[nod] = 1;
    for (Q.push(nod); !Q.empty(); Q.pop())
    {
        i = Q.front();
        for (const auto& f : G[i])
            if (B[f] == 0)
            {
                B[f] = 1;
                D[f] = GetMinimum(f);
                Q.push(f);
            }

    }
};

int GetMinimum(int node)
{
    memset(Bm, 0, sizeof(Bm));
    for (const auto& x : G[node])
        Bm[D[x]] = 1;
    for (int i = 1; i <= 100; ++i)
        if (Bm[i] == 0)
            return i;
};











