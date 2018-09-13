#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream is ("amici2.in");
ofstream os ("amici2.out");

int N, M, T, x, y, D[21005];
vector <int> V[21005];
queue <int> Q;

int BFS();

int main()
{
    for (is >> T; T; --T)
    {
        is >> N >> M;
        for (int i = 1; i <= M; ++i)
        {
            is >> x >> y;
            V[x].push_back(y);
            V[y].push_back(x);
        }
        y = BFS();
        for (x = 0; (1 << x) < y; x++);
        os << x << '\n';
        for (int i = 1; i <= N; ++i)
            V[i].clear(), D[i] = 0;
    }
    is.close();
    os.close();
}

int BFS()
{
    D[1] = 1;
    int i, j, val = 0;
    for (Q.push(1); !Q.empty(); Q.pop())
    {
        i = Q.front();
        for (int j = 0; j < V[i].size(); ++j)
        {
            if (D[V[i][j]] == 0)
            {
                D[V[i][j]] = D[i] + 1;
                Q.push(V[i][j]);
            }
            if (D[V[i][j]] > val)
                val = D[V[i][j]];
        }
    }
    return val;
};











