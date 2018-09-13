#include <fstream>
#include <vector>
using namespace std;

ifstream is ("asmax.in");
ofstream os ("asmax.out");

const int Dim = 16001;
const int INF = 0x3f3f3f3f;


int N, Cost[Dim], Smax[Dim], SMAX = -INF;
vector <int> Graph[Dim];
bool Vis[Dim];


void DFS(int Node);


int main()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
        is >> Cost[i];
    for (int i = 1, x, y; i < N; ++i)
        is >> x >> y, Graph[x].push_back(y), Graph[y].push_back(x);
    DFS(1);
    os << SMAX;
}

void DFS(int Node)
{
    Vis[Node] = 1;
    Smax[Node] = Cost[Node];
    for (const int& Next : Graph[Node])
        if (Vis[Next] == 0)
        {
            DFS(Next);
            Smax[Node] = max(Smax[Node], Smax[Node] + Smax[Next]);
        }
    SMAX = max(SMAX, Smax[Node]);
};






























