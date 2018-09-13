#include <fstream>
#include <vector>
using namespace std;

ifstream is ("grarb.in");
ofstream os ("grarb.out");

int N, M;
int Ccnt, Csize, Sol, Edges, T[100001], R[100001];
bool B[100001];

vector <int> G[100001];

int Root(int k);
void Unite(int x, int y);
void DFS(int x, int t);

int main()
{
    is >> N >> M;
    for (int i = 1; i <= N; ++i)
        T[i] = i, R[i] = 1;
    for (int i = 1, a, b, ra, rb; i <= M; ++i)
    {
        is >> a >> b;
        ra = Root(a);
        rb = Root(b);
        if (ra == rb)
            Sol++;
        else
            Unite(ra, rb);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i)
        if (B[i] == 0)
        {
            Csize = 0;
            DFS(i, 0), Ccnt++;
        }
    os << Sol << '\n' << Ccnt-1;
    is.close();
    os.close();
}

void DFS(int x, int t)
{
    Csize++;
    B[x] = 1;
    for (const int& f : G[x])
        if (B[f] == 0)
            DFS(f, x);
};

int Root(int k)
{
    int r = k;
    for (; r != T[r]; r = T[r]);
    for (int x; k != T[k]; x = T[k], T[k] = r, k = x);
    return r;
};

void Unite(int x, int y)
{
    if (R[x] > R[y])
        T[y] = x;
    else
    {
        T[x] = y;
        if (R[x] == R[y])
            R[y]++;
    }
};












