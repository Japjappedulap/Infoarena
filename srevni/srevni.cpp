#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define DIM 100005

ifstream is ("srevni.in");
ofstream os ("srevni.out");

#define BF 1<<17
char Pars[BF], *p;

int GET();
void Check();

int N, M, F[DIM];
bool b[DIM];
pair<int, int> C[DIM];

vector <int> v[DIM];
queue <int> Q;

void Read();

int main()
{
    p = Pars;
    Read();
    for (int i = 1; i <= N; ++i) F[i] = C[i].first;
    sort(C+1, C+N+1);
    for (int i = 1; i <= N; ++i)
        if (b[C[i].second] == false)
            for (Q.push(C[i].second), b[C[i].second] = true; !Q.empty(); Q.pop())
                for (int j = 0; j < v[Q.front()].size(); ++j)
                    if (F[v[Q.front()][j]] > C[i].first && b[v[Q.front()][j]] == false)
                    {
                        F[v[Q.front()][j]] = C[i].first;
                        b[v[Q.front()][j]] = true;
                        Q.push(v[Q.front()][j]);
                    }
    for (int i = 1; i <= N; ++i)
        os << F[i] << ' ';
    is.close();
    os.close();
}

void Read()
{
    N = GET();
    M = GET();
    for (int i = 1; i <= N; ++i)
        C[i].first = GET(), C[i].second = i;
    for (int i = 1, x, y; i <= M; ++i)
        x = GET(), y = GET(), v[y].push_back(x);
};

int GET()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while (*p >= '0' && *p <= '9') X = X * 10 + (*p - '0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BF, '\0'), p = Pars;
};
