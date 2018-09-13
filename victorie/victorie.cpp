#include <fstream>
#include <cstring>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
using namespace std;

ifstream is ("victorie.in");
ofstream os ("victorie.out");

const int Nmax = 100005;
using PII = pair<int,int>;

int N, M;
int Depth[Nmax], Lowlink[Nmax], belong[Nmax];
vector <int> Graph[Nmax];
stack <PII> Stk;

vector < set<int> > BC;
bitset <Nmax> Explored, GBC;
set <int> Sol;

void Read();
inline void DFS(int node, int father);
inline void Extract(int node, int next);
inline void DF(int node, int C);

int main()
{
    Read();
    for (int i = 1; i <= N; ++i)
        if (Depth[i] == 0)
        {
            DFS(i, 0);
            while (!Stk.empty()) Stk.pop();
        }

    for (size_t i = 1; i <= BC.size(); ++i)
    {
        for (const int& j : BC[i-1])
            belong[j] = i;
        Explored.reset();

        DF(*BC[i-1].begin(), i);
        if (GBC[i] == 1)
            for (const int& j : BC[i-1])
                Sol.insert(j);

    }
    os << Sol.size() << '\n';
    for (const int& i : Sol)
        os << i << ' ';


    is.close();
    os.close();
}

inline void DF(int node, int C)
{
    Explored[node] = 1;
    for (const int& next : Graph[node])
        if (belong[next] == C)
        {
            if (Explored[next] == 0)
                DF(next, C);
            else
                if (Depth[node] % 2 == Depth[next] % 2 && node != next)
                    GBC[C] = 1;
        }
};

void Read()
{
    is >> N >> M;
    for (int a, b; M; --M)
    {
        is >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
};

inline void DFS(int node, int father)
{
    Depth[node] = Lowlink[node] = Depth[father]+1;
    for (const int& next : Graph[node])
    {
        if (next == father)
            continue;

        if (Depth[next] == 0)
        {
            Stk.push({node, next});
            DFS(next, node);
            Lowlink[node] = min(Lowlink[node], Lowlink[next]);
            if (Depth[node] <= Lowlink[next])
                Extract(node, next);
        }
        else
            Lowlink[node] = min(Lowlink[node], Depth[next]);
    }
};

inline void Extract(int node, int next)
{
    int X, Y;
    set <int> S;
    do
    {
        X = Stk.top().first;
        Y = Stk.top().second;
        Stk.pop();
        S.insert(X);
        S.insert(Y);
    }
    while (!Stk.empty() && X != node && Y != next);
    BC.push_back(S);
};
