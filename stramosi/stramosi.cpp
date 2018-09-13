#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

#define NZ 300004
#define nr first
#define sol second

ifstream is ("stramosi.in");
ofstream os ("stramosi.out");

int N, M, stk[NZ], K, Qry[NZ];
vector <int> G[NZ];
vector <pair<int,int> > Q[NZ];
bitset <NZ> B, root;

inline void DFS(int t);

int main()
{
    is >> N >> M;
    for (int i = 1, a; i <= N; ++i)
    {
        is >> a;
        if (a == 0) root[i] = 1;
        else G[a].push_back(i);
    }
    for (int i = 1, nod, tr; i <= M; ++i)
    {
        is >> nod >> tr;
        Q[nod].push_back({tr, i});
    }
    for (int i = 1; i <= N; ++i)
        if (root[i])
            DFS(i);

    for (int i = 1; i <= M; ++i)
        os << Qry[i] << '\n';
    is.close();
    os.close();
}

inline void DFS(int t)
{
    B[t] = 1;
    stk[++K] = t;
    if (Q[t].empty() == 0)
        for (const auto& req : Q[t])
        {
            if (K <= req.nr) Qry[req.sol] = 0;
            else Qry[req.sol] = stk[K-req.nr];
        }
    for (const auto& f : G[t])
        if (B[f] == 0)
            DFS(f);
    --K;
};
