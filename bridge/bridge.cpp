#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#define MOD 666013

ifstream is ("bridge.in");
ofstream os ("bridge.out");

#define BF 1<<17
char Pars[BF], *p;

int GET();
void Check();

short N, M;
int D[4002][4002];
short Path[4002], x, y;
bool Banned[4002];
vector <short> TP[4002];

void Read();

int main()
{
    Read();
    D[0][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= 4000; ++j)
        {
            if (Banned[i] == 1)
            {
                D[i][j] = 0;
                continue;
            }
            if (Path[i] == 0)
            {
                if (Path[i-1] != 3) D[i][j] = D[i][j] + D[i-1][j-1];

                if (Path[i-2] != 3 && i-2 >= 0) D[i][j] = D[i][j] + D[i-2][j-1];
                if (D[i][j] >= MOD) D[i][j] = D[i][j] - MOD;

                D[i][j] = D[i][j] + D[i][j-1];
                if (D[i][j] >= MOD) D[i][j] = D[i][j] - MOD;
                for (int k = 0; k < TP[i].size(); ++k)
                {
                    D[i][j] = D[i][j] + D[TP[i][k]][j-1];
                    if (D[i][j] >= MOD) D[i][j] = D[i][j] - MOD;
                }

            }
            if (Path[i] == 1)
            {
                if (Path[i-1] != 3) D[i][j] = D[i][j] + D[i-1][j-1];

                D[i][j] = D[i][j] + D[i][j-1];
                if (D[i][j] >= MOD) D[i][j] = D[i][j] - MOD;
            }
            if (Path[i] == 2)
            {
                D[i][j] = 0;
            }
            if (Path[i] == 3)
            {
                if (Path[i-1] != 3) D[i][j] = D[i][j] + D[i-1][j-1];
                if (Path[i-2] != 3 && i-2 >= 0) D[i][j] = D[i][j] + D[i-2][j-1];
                if (D[i][j] >= MOD) D[i][j] = D[i][j] - MOD;

                for (int k = 0; k < TP[i].size(); ++k)
                {
                    D[i][j] = D[i][j] + D[TP[i][k]][j-1];
                    if (D[i][j] >= MOD) D[i][j] = D[i][j] - MOD;
                }

            }
        }

    for (int i = 0; i < M; ++i)
    {
        x = GET(), y = GET();
        os << D[x][y] << '\n';
    }
    is.close();
    os.close();
}


void Read()
{
    p = Pars;
    N = GET(); M = GET();
    short cnt = 0;
    vector < pair <short, short> > V;
    queue <short> Q;
    for (int i = 1; i <= N; ++i)
    {
        Path[i] = GET();
        if (Path[i] == 2)
            Banned[i] = 1;
        if (Path[i] == 3)
            cnt++, V.push_back(make_pair(i, 0));
    }
    for (int i = 0; i < cnt; ++i)
    {
        V[i].second = GET();
        TP[V[i].second].push_back(V[i].first);
    }
    for (int i = 1; i <= N; ++i)
        if ((Path[i] == 1 || Path[i] == 2) && TP[i].empty() == false)
            for (Q.push(i); !Q.empty(); Q.pop())
                for (int j = 0; j < TP[Q.front()].size(); ++j)
                {
                    Banned[TP[Q.front()][j]] = 1;
                    Q.push(TP[Q.front()][j]);
                }
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
