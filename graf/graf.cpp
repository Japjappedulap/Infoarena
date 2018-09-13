#include <fstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

ifstream is ("graf.in");
ofstream os ("graf.out");

int N, M, X, Y, LG;
int DX[7502], DY[7502];

vector <int> V[7502];
queue  <int> Q;
bool B[7502], uq;

void Read();
void BFS();

int main()
{
    Read();
    BFS();
    int sol = N;
    for (int i = 1; i <= N; ++i)
    {
        if (DX[i]+DY[i] != LG+1)
            B[i] = 1, --sol;
        else if (B[i] == 0)
        {
            uq = false;
            for (int j = i+1; j <= N; ++j)
                if (DX[j] == DX[i] && DY[j] == DY[i])
                    B[i] = B[j] = 1, uq = true, --sol;
            if (uq == true) --sol;
        }
    }
    os << sol << '\n';
    for (int i = 1; i <= N; ++i)
        if (B[i] == 0)
            os << i << ' ';
    is.close();
    os.close();
}

void Read()
{
    is >> N >> M >> X >> Y;
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        is >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
};

void BFS()
{
    DX[X] = DY[Y] = 1;
    for (Q.push(X); !Q.empty(); Q.pop())
    {
        for (int j = 0; j < V[Q.front()].size(); ++j)
        {
            if (DX[V[Q.front()][j]] == 0)
            {
                DX[V[Q.front()][j]] = DX[Q.front()]+1;
                Q.push(V[Q.front()][j]);
            }
        }
    }
    for (Q.push(Y); !Q.empty(); Q.pop())
    {
        for (int j = 0; j < V[Q.front()].size(); ++j)
        {
            if (DY[V[Q.front()][j]] == 0)
            {
                DY[V[Q.front()][j]] = DY[Q.front()]+1;
                Q.push(V[Q.front()][j]);
            }
        }
    }
    LG = DX[Y];
};
