#include <fstream>
using namespace std;

ifstream is ("gradina3.in");
ofstream os ("gradina3.out");

#define BF 1<<17
char Pars[BF], *p;

int GET();
void Check();

int N, K, P;
bool B[1001][1001];
int D[1001][1001], vmax, vs;


int main()
{
    p = Pars;
    N = GET();
    P = GET();
    K = GET();
    for (int x, y, i = 1; i <= P; ++i)
        x = GET(), y = GET(), B[x][y] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            D[i][j] = D[i-1][j] + D[i][j-1] + B[i][j] - D[i-1][j-1];
    for (int i = K; i <= N; ++i)
        for (int j = K; j <= N; ++j)
            if (D[i][j] - D[i][j-K] - D[i-K][j] + D[i-K][j-K] > vmax)
                vmax = D[i][j] - D[i][j-K] - D[i-K][j] + D[i-K][j-K], vs = 1;
            else
                if (D[i][j] - D[i][j-K] - D[i-K][j] + D[i-K][j-K] == vmax) ++vs;
    os << vmax << '\n' << vs;
    is.close();
    os.close();
}

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
