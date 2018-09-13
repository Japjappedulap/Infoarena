#include <cstdio>
#include <queue>
using namespace std;

FILE * is = fopen("tsunami.in", "r");
FILE * os = fopen("tsunami.out", "w");

struct Cel {short i, j;};
queue <Cel> Q;

const short di[4] = {-1, 0, 1, 0};
const short dj[4] = {0, 1, 0, -1};

short n, m, h;
int cnt;
short a[1006][1006];
bool b[1006][1006];

void Read();
void Lee(int ip, int jp);
bool Water(int i, int j);
bool OK(int i, int j);

int main()
{
    Read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] < h && b[i][j] == 0 && Water(i, j) == 1 && a[i][j] != 0)
                Lee(i, j);
    fprintf(os, "%d", cnt);
    fclose(is);
    fclose(os);
    return 0;
}

void Lee(int ip, int jp)
{
    Cel Ac;
    int i, j, iv, jv;
    Ac.i = ip, Ac.j = jp;
    Q.push(Ac);
    while(!Q.empty())
    {
        Ac = Q.front(), Q.pop();
        i = Ac.i, j = Ac.j;
        b[i][j] = true;
        cnt++;
        for (int d = 0; d < 4; ++d)
        {
            iv = i + di[d];
            jv = j + dj[d];
            if (OK(iv, jv) == true)
            {
                b[iv][jv] = 1;
                Ac.i = iv, Ac.j = jv;
                Q.push(Ac);
            }
        }
    }
};

bool OK(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m) return false;
    if (a[i][j] == 0) return false;
    if (a[i][j] >= h) return false;
    if (b[i][j] == 1) return false;
    return true;
};

void Read()
{
    fscanf(is, "%hd%hd%hd", &n, &m, &h);
    for (int i = 0; i <= n+1; ++i)
        for (int j = 0; j <= m+1; ++j)
            if (i == 0 || j == 0 || i == n+1 || j == m+1) a[i][j] = -1;
            else    fscanf(is, "%d", &a[i][j]);
};

bool Water(int i, int j)
{
    if (a[i-1][j] == 0)  return true;
    if (a[i+1][j] == 0)  return true;
    if (a[i][j-1] == 0)  return true;
    if (a[i][j+1] == 0)  return true;
    return false;
};
