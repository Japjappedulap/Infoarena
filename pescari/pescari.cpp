#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define N 1002

FILE * is = fopen("pescari.in", "r");
FILE * os = fopen("pescari.out", "w");

const int di[] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m, p, i, j, iv, jv;
int a[N][N], DP[N][N];
bool b[N][N];
pair <int,int> Ac;

vector <pair<int,int> > v;
queue <pair<int,int> > Q;

void Read();
void BFS();
bool OK(int i, int j);

int main()
{
    Read();
    BFS();
    for (vector <pair<int,int> > :: iterator it = v.begin(); it != v.end(); ++it)
        fprintf(os, "%i\n", DP[(*it).first][(*it).second]);
    fclose(is);
    fclose(os);
    return 0;
}

void BFS()
{
    while (!Q.empty())
    {
        Ac = Q.front(), Q.pop();
        i = Ac.first, j = Ac.second;
        for (int dir = 0; dir < 8; ++dir)
        {
            iv = i + di[dir], jv = j + dj[dir];
            if (OK(iv, jv))
                if (DP[iv][jv] > DP[i][j]+1 || DP[iv][jv] == 0)
                {
                    DP[iv][jv] = DP[i][j] + 1;
                    Ac.first = iv, Ac.second = jv;
                    Q.push(Ac);
                }
        }
    }
};

bool OK(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m || b[i][j] == 1) return false;
    return true;
};

void Read()
{
    fscanf(is, "%i%i%i", &n, &m, &p);
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
        {
            fscanf(is, "%i", &a[i][j]);
            if (a[i][j] == 2) Q.push(make_pair(i, j)), b[i][j] = 1;
            if (a[i][j] == 1) v.push_back(make_pair(i, j));
        }
};
