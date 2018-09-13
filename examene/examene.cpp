#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

ifstream is ("examene.in");
ofstream os ("examene.out");

int N, M, P;
bool U[303], Cy[303];

bool InS[303];
int ind, Idx[303], L[303];

vector <int> G[303], Gt[303], Comp;
stack <int> S;

void Read();
void DFS(int x);
void Tarjan(int x);


int main()
{
    Read();
    for (int i = 1, x; i <= P; ++i)
    {
        is >> x;
        DFS(x);
    }
    bool Ax = 0;
    for (int i = 1; i <= N; ++i)
        if (U[i] == 0)
        {
            os << i << ' ';
            Ax = 1;
        }
    if (Ax == 0)
        os << '0';
    os << '\n';
    Ax = 0;
    for (int i = 1; i <= N; ++i)
        if (Idx[i] == 0)
            Tarjan(i);
    for (int i = 1; i <= N; ++i)
        if (Cy[i] == 1)
        {
            os << i << ' ';
            Ax = 1;
        }
    if (Ax == 0)
        os << '0';
    is.close();
    os.close();
}

void Tarjan(int x)
{
    L[x] = Idx[x] = ++ind;
    InS[x] = 1;
    S.push(x);
    for (const int& y : G[x])
        if (Idx[y] == 0)
        {
            Tarjan(y);
            L[x] = min(L[x], L[y]);
        }
        else
            if (InS[y] == 1)
                L[x] = min(L[y], L[x]);
    if (L[x] == Idx[x])
    {
        Comp.clear();
        int ax;
        do
        {
            ax = S.top();
            S.pop();
            InS[ax] = 0;
            Comp.push_back(ax);
        }
        while (!S.empty() && ax != x);

        if (Comp.size() > 1)
            for (const int& i : Comp)
                Cy[i] = 1;
    }
};

void DFS(int x)
{
    U[x] = 1;
    for (const int& y : Gt[x])
        if (U[y] == 0)
            DFS(y);
};

void Read()
{
    is >> N >> M >> P;
    for (int i = 1, a, b; i <= M; ++i)
    {
        is >> a >> b;
        G[a].push_back(b);
        Gt[b].push_back(a);
        if (a == b)
            Cy[a] = 1;
    }
};































