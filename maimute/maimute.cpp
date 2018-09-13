#include <fstream>
#include <vector>
using namespace std;

const int Nmax = 100001;

const int BUFFER = 1<<17;
char BF[BUFFER], *p;
inline int GET();
inline void Check();

ifstream is ("maimute.in");
ofstream os ("maimute.out");

int N, M;
vector <int> Tree[Nmax];
bool Vis[Nmax];

int First[Nmax];
int Last[Nmax];
int Depth[Nmax];

inline void DFS(int x);

int main()
{
    p = BF;
    N = GET();
    for (int i = 1, x, y; i < N; ++i)
    {
        x = GET();
        y = GET();
        Tree[x].push_back(y);
        Tree[y].push_back(x);
    }
    DFS(1);

    M = GET();
    for (int x, y, dif; M; --M)
    {
        x = GET();
        y = GET();
        if (Depth[x] < Depth[y])
            swap(x, y), dif = Depth[y] - Depth[x];
        else
            dif = Depth[x] - Depth[y];

        if (dif == 0) {os << "NU\n"; continue;}
        if (First[y] < First[x] && Last[x] < Last[y]) {os << "DA\n"; continue;}
        os << "NU\n";

    }
    is.close();
    os.close();
}

int steps = 0;

inline void DFS(int x)
{
    Vis[x] = 1;
    First[x] = Last[x] = ++steps;
    for (const int& y : Tree[x])
        if (Vis[y] == 0)
        {
            Depth[y] = Depth[x]+1;
            DFS(y);
            Last[x] = ++steps;
        }

};

inline int GET()
{
    int X = 0;
    while (*p < '0' || '9' < *p) ++p, Check();
    while ('0' <= *p && *p <= '9') X = X*10 + (*p-'0'), ++p, Check();
    return X;
};

inline void Check()
{
    if (*p == '\0') is.get(BF, BUFFER, '\0'), p = BF;

};
