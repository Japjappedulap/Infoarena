#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream is ("marmelada.in");
ofstream os ("marmelada.out");

#define x first
#define y second

int N, M, S, D, P[100010];
int F[100010];
int T[100010];  // T[x] = indicele muchiei(din citire) care duce la tatal lui x;
bool B[100010];

pair <int,int> C[100010], E[100010];
int K = 1;

queue <int> Q;
vector <int> G[100010];

void Read();
void BFS();
void Path(int x);

int main()
{
    Read();
    BFS();

    is.close();
    os.close();
}

void Read()
{
    is >> N >> M >> S >> D;
    for (int i = 1, a, b; i <= M; ++i)
    {
        is >> a >> b;
        G[a].push_back(i);
        G[b].push_back(i);
        E[i] = {a, b};
    }
    for (int i = 1; i <= N; ++i)
        F[i] = 99999999;
    for (int i = 1; i <= M; ++i)
        is >> C[i].x, C[i].y = i;
    sort(C+1, C + M + 1);
};

void BFS()
{
    Q.push(S);
    F[S] = 0;
    for (int i, u; !Q.empty();)
    {
        i = Q.front();
        Q.pop();
        if (i == D)
            break;
        for (const int& j : G[i])
        {
            u = E[j].x + E[j].y - i;
            if (F[u] > F[i] + 1)
            {
                F[u] = F[i] + 1;
                T[u] = j;
                Q.push(u);
            }
        }
    }
    Path(D);
    for (int i = 1; i <= M; ++i)
        if (B[i] == 0)
            P[i] = C[K++].y;

    for (int i = 1; i <= M; ++i)
        os << P[i] << '\n';
};

void Path(int x)
{
    if (T[x] == 0) return;

    P[T[x]] = C[K++].y;
    B[T[x]] = 1;

    int u = E[T[x]].x + E[T[x]].y - x;

    Path(u);
};


























