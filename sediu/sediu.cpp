#include <fstream>
#include <vector>
using namespace std;

ifstream is ("sediu.in");
ofstream os ("sediu.out");

#define BF 1<<17
char Ps[BF], *p;

int GET();
void Check();

const int Dim = 16001;

int N, SubTreeSize[Dim], Dp[Dim];       // dp[i] = cel mai mare subarbore a unui fiu a lui i
int Sol = Dim, Ap;
vector <int> Graph[Dim];

void DFS(int, int);

int main()
{
    p = Ps;
    N = GET();
    for (int i = 1, x, y; i < N; ++i)
        x = GET(), y = GET(), Graph[x].push_back(y), Graph[y].push_back(x);
    DFS(1, 0);

    for (int i = 1; i <= N; ++i)
    {
        Dp[i] = max(Dp[i], N - SubTreeSize[i]);
        if (Dp[i] < Sol)
            Sol = Dp[i], Ap = 0;
        if (Dp[i] == Sol)
            Ap++;
    }
    os << Sol << ' ' << Ap << '\n';
    for (int i = 1; i <= N; ++i)
        if (Sol == Dp[i])
            os << i << ' ';

    is.close();
    os.close();
}

void DFS(int Node, int Father)
{
    SubTreeSize[Node] = 1;
    for (const int& Next : Graph[Node])
        if (SubTreeSize[Next] == 0)
        {
            DFS(Next, Node);
            SubTreeSize[Node] += SubTreeSize[Next];
            Dp[Node] = max(Dp[Node], SubTreeSize[Next]);
        }
};

int GET()
{
    int X = 0;
    while (*p <= '0' || *p > '9') ++p, Check();
    while (*p >= '0' && *p <= '9') X = X*10 + (*p-'0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Ps, BF, '\0'), p = Ps;
};





