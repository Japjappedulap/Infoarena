#include <fstream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

ifstream is ("pamant.in");
ofstream os ("pamant.out");

const int Nmax = 100001;
const int INF = 0x3f3f3f3f;

const int Buff = 1<<18;
char Pars[Buff], *p;
int GET();
void Check();

int N, M;
int Ap[Nmax];  //nr de aparitii in comp biconexe
int Depth[Nmax], Lowlink[Nmax], Leader;

vector <int> Graph[Nmax], Art;
stack <pair<int,int> > Stk;
set <int> Teams;

void Read();
void DFS(int node, int father, int level);
void Extract(int node, int next);

int main()
{
    Read();
    for (int i = 1; i <= N; ++i)
        if (Depth[i] == 0)
        {
            Leader = INF;
            DFS(i, 0, 1);
            Teams.insert(Leader);
        }
    for (int i = 1; i <= N; ++i)
        if (Ap[i] > 1)
            Art.push_back(i);
    os << Teams.size() << '\n';
    for (const int& i : Teams)
        os << i << ' ';
    os << '\n' << Art.size() << '\n';
    for (const int& i : Art)
        os << i << ' ';

    is.close();
    os.close();
}

void Read()
{
    p = Pars;
    N = GET();
    M = GET();
    for (int x, y; M; --M)
    {
        x = GET();
        y = GET();
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
};

int GET()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while ('0' <= *p && *p <= '9') X = X*10 + (*p - '0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, Buff, '\0'), p = Pars;
};

void DFS(int node, int father, int level)
{
    Leader = min(Leader, node);
    Depth[node] = Lowlink[node] = level;
    for (const int& next : Graph[node])
    {
        if (next == father) continue;
        if (Depth[next] == 0)
        {
            Stk.push({node, next});
            DFS(next, node, level + 1);
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
    int X, Y;
    set <int> S;
    do{
        X = Stk.top().first;
        Y = Stk.top().second;
        Stk.pop();
        S.insert(X);
        S.insert(Y);
    } while ( !Stk.empty() && X != node && Y != next);
    for (const int& i : S)
        Ap[i]++;
};




















