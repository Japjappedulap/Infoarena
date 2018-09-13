#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream is ("sate.in");
ofstream os ("sate.out");

int N, M, X, Y;
vector <pair<int,int> > V[30003];
queue <int> Q;
bool B[30003];
int C[30003];

void Read();
void BFS();

int main()
{
    Read();
    BFS();
    os << C[Y];
    is.close();
    os.close();
}

void Read()
{
    is >> N >> M >> X >> Y; B[X] = 1;
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        is >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }
};

void BFS()
{
    for (Q.push(X); !Q.empty(); Q.pop())
    {
        for (int j = 0; j < V[Q.front()].size(); ++j)
        {
            if (B[V[Q.front()][j].first] == 0)
            {
                B[V[Q.front()][j].first] = 1;
                if (Q.front() < V[Q.front()][j].first)
                    C[V[Q.front()][j].first] = C[Q.front()] + V[Q.front()][j].second;
                else
                    C[V[Q.front()][j].first] = C[Q.front()] - V[Q.front()][j].second;
                Q.push(V[Q.front()][j].first);
            }
        }
    }
};












