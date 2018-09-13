#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

const int Nmax = 100001;

ifstream is ("arbxyz.in");
ofstream os ("arbxyz.out");

int N, C[3];
int IN[Nmax];

bool Visited[Nmax];
int SubTreeSize[Nmax];
bool Ex[Nmax][8];

vector <int> Tree[Nmax];


void DFS(int node);
bool Solve();
void Clear();

int main()
{
    int Tests;
    for (is >> Tests; Tests; --Tests)
        os << Solve() << '\n', Clear();
    is.close();
    os.close();
}

bool Solve()
{
    is >> N >> C[0] >> C[1] >> C[2];

    for (int i = 1, a, b; i < N; ++i)
    {
        is >> a >> b;
        IN[a]++;
        IN[b]++;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i) Ex[i][0] = 1;

    DFS(1);

    if (Ex[1][7] == 1)
        return 1;

    return 0;
};

void DFS(int Node)
{
    SubTreeSize[Node] = 1;
    Visited[Node] = 1;
    for (const int& Next : Tree[Node])
        if (Visited[Next] == 0)
        {
            DFS(Next);

            SubTreeSize[Node] += SubTreeSize[Next];

            for (int k = 1; k < 8; ++k)
                if (Ex[Next][k] == 1)
                    Ex[Node][k] = 1;

            int msk = 0;
            for (int k = 0; k < 3; ++k)
                if (Ex[Next][1<<k] == 1)
                    msk = msk | (1<<k);
            Ex[Node][msk] = 1;

        }
    for (int mask = 1; mask < 8; ++mask)
    {
        int sz = 0;
        for (int bit = 0; bit < 3; ++bit)
            if (mask & (1<<bit))
                sz += C[bit];
        for (int bit = 0; bit < 3; ++bit)
            if ((mask & (1<<bit)) && Ex[Node][mask - (1<<bit)] == 1 && SubTreeSize[Node] - sz == 0)
                Ex[Node][mask] = 1;
    }
};

void Clear()
{
    for (int i = 1; i <= N; ++i)
        Tree[i].clear();
    memset(Ex, 0, sizeof(Ex));
    memset(IN, 0, sizeof(IN));
    memset(Visited, 0, sizeof(Visited));
    memset(SubTreeSize, 0, sizeof(SubTreeSize));
    N = C[0] = C[1] = C[2] = 0;

};











































