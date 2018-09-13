#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#define nod first
#define cost second
#define INF 1<<30

ifstream is ("catun.in");
ofstream os ("catun.out");

int N, M, K;
int D[36005], AJ[36005];
bool B[36005];

vector < pair<int, int> > V[36005];

struct COMP{
    bool operator ()(int A, int B) {
        return D[A] > D[B];}
};

priority_queue < int , vector<int> , COMP > Q;

int main()
{
    is >> N >> M >> K;
    for (int i = 1; i <= N; ++i) D[i] = INF;
    for (int i = 1, X; i <= K; ++i)
    {
        is >> X;
        D[X] = 0; AJ[X] = X; B[X] = 1;
        Q.push(X);
    }
    for (int i = 1, x, y, z; i <= M; ++i)
    {
        is >> x >> y >> z;
        V[x].push_back({y, z});
        V[y].push_back({x, z});
    }
    int i;
    pair <int,int> k;
    while (!Q.empty())
    {
        i = Q.top();
        Q.pop();
        for (int j = 0; j < V[i].size(); ++j)
        {
            k = V[i][j];
            if (D[k.nod] > D[i] + k.cost)
            {
                D[k.nod] = D[i] + k.cost;
                AJ[k.nod] = AJ[i];
                Q.push(k.nod);
            }
            if (D[k.nod] == D[i] + k.cost && AJ[k.nod] > AJ[i])
                AJ[k.nod] = AJ[i];
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (B[i] == 1)  os << "0 ";
        else            os << AJ[i] << ' ';
    }

    is.close();
    os.close();
}









