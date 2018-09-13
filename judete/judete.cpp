#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream is ("judete.in");
ofstream os ("judete.out");

const int NMAX = 1<<7;
const int oo = 0x3f3f3f3f;

int N, K;
int STS[NMAX];

int D[NMAX][NMAX];
int TR[NMAX<<1];

bool B[NMAX];
vector <int> Graph[NMAX];


inline void DFS(int x);


int main()
{
    is >> N >> K;
    for (int i = 1, x, y; i < N; ++i)
    {
        is >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    DFS(1);
    int T = oo;
    for (int i = K; i <= N; ++i)
        T = min(T, max(i, D[1][i]));
    os << T;

    is.close();
    os.close();
}

inline void DFS(int x)
{
    STS[x] = 1;
    B[x] = 1;

    memset(D[x], oo, sizeof(D[x]));
    D[x][1] = 0;

    for (const int& f : Graph[x])
        if (B[f] == 0)
        {
            DFS(f);
            STS[x] += STS[f];

            memset(TR, oo, sizeof(TR));
            for (int i = 0; i <= STS[x]; i++)
                for (int j = 0; j <= STS[f]; ++j)
                {
                    TR[i+j] = min(TR[i+j], max(D[x][i], D[f][j]));

                    if (j >= K)
                        TR[i] = min(TR[i], max(D[x][i], max(D[f][j], j)));
                }

            memcpy(D[x], TR, sizeof(TR));
        }

}
