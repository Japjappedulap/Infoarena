#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#define cost second
#define nod first
#define INF 1<<25

ifstream is ("camionas.in");
ofstream os ("camionas.out");

int N, M, G, D[50004];

struct COMP{
    bool operator ()(int A, int B)
    {     return D[A] > D[B];     }
};

priority_queue < int, vector<int>, COMP > Q;
vector < pair <int, bool> > V[50004];

int main()
{
    is >> N >> M >> G;
    for (int i = 1, x, y, z; i <= M; ++i)
    {
        is >> x >> y >> z;
        if (z >= G) z = 0;
        else        z = 1;
        V[x].push_back({y, z});
        V[y].push_back({x, z});
    }
    for (int i = 2; i <= N; ++i)
        D[i] = INF;
    D[1] = 0;
    Q.push(1);
    pair<int, bool> k;
    for (int i; !Q.empty(); )
    {
        i = Q.top();
        Q.pop();
        for (int j = 0; j < V[i].size(); ++j)
        {
            k = V[i][j];
            if (D[k.nod] > D[i] + k.cost)
            {
                D[k.nod] = D[i] + k.cost;
                Q.push(k.nod);
            }
        }
    }
    os << D[N] << '\n';
    is.close();
    os.close();
}
