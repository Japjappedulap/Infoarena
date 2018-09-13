#include <fstream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

ifstream is ("clepsidra.in");
ofstream os ("clepsidra.out");

const int Nmax = 200005;
const int MOD = 666013;

int N, M;
int D[Nmax];        // nr de componente conexe ramase dupa eliminarea nodului i
int NrMod[Nmax];
int Lowlink[Nmax], Depth[Nmax];
vector <int> Graph[Nmax];
stack < pair<int,int> > Stk;

void Read();
void DFS(int node, int father, int level);
void Extract(int node, int next);

int main()
{
    Read();
    DFS(1, 0, 1);

    for (int i = 2; i <= N; ++i)
        NrMod[i] = (NrMod[i-1] * 2 + 2) % MOD;

    for (int i = 1; i <= N; ++i)
        os << NrMod[D[i]] << '\n';

    is.close();
    os.close();
}

void DFS(int node, int father, int level)
{
    Lowlink[node] = Depth[node] = level;
    for (const int& next : Graph[node])
    {
        if (next == father)
            continue;
        if (Depth[next] == 0)
        {
            Stk.push({node, next});
            DFS(next, node, level+1);
            Lowlink[node] = min(Lowlink[node], Lowlink[next]);
            if (Depth[node] <= Lowlink[next])
                Extract(node, next);
        }
        else
            Lowlink[node] = min(Lowlink[node], Depth[next]);
    }
};

void Extract(int node, int next)
{
    set<int> Set;
    int X, Y;
    do
    {
        X = Stk.top().first;
        Y = Stk.top().second;
        Stk.pop();
        Set.insert(X);
        Set.insert(Y);
    }
    while (!Stk.empty() && X != node && Y != next);
    for (const int& i : Set)
        D[i]++;
};

void Read()
{
    is >> N >> M;
    for (int x, y; M; --M)
    {
        is >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
};

