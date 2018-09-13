#include <algorithm>
#include <fstream>
#include <vector>
#include <bitset>
#include <stack>
using namespace std;

#define NSZ 50005
#define INF 1<<18

ifstream is ("retele.in");
ofstream os ("retele.out");

int N, M;
int Index[NSZ], L[NSZ], idx;
bitset <NSZ> B;
vector <int> G[NSZ], C;
vector < vector<int> > SCC;
stack <int> S;

void TARZAN(int x);

int main()
{
    is >> N >> M;
    for (int i = 1; i <= N; ++i)
        Index[i] = INF;
    for (int i = 1, A, B; i <= M; ++i)
    {
        is >> A >> B;
        G[A].push_back(B);
    }
    for (int i = 1; i <= N; ++i)
        if (Index[i] == INF)
            TARZAN(i);
    os << SCC.size() << '\n';
    for (int i = 0; i < SCC.size(); ++i)
        sort(SCC[i].begin(), SCC[i].end());
    sort(SCC.begin(), SCC.end());
    for (int i = 0; i < SCC.size(); ++i, os << '\n')
    {
        os << SCC[i].size() << ' ';
        for (const auto& j : SCC[i])
            os << j << ' ';
    }

}

void TARZAN(int x)
{
    Index[x] = L[x] = idx++;
    S.push(x); B[x] = 1;
    int node;
    for (int j = 0; j < G[x].size(); ++j)
    {
        node = G[x][j];
        if (Index[node] == INF)
        {
            TARZAN(node);
            L[x] = min(L[x], L[node]);
        }
        else if (B[node] == 1)
            L[x] = min(L[x], L[node]);
    }
    if (Index[x] == L[x])
    {
        do{
            node = S.top(); S.pop();
            C.push_back(node);
            B[node] = 0;
        }
        while (node != x);
        SCC.push_back(C);
        C.clear();
    }
};












