#include <fstream>
#include <queue>
using namespace std;
#define TX pair<int,int>
ifstream is ("taxa.in");
ofstream os ("taxa.out");

TX start, finish, aux, Ac;
queue <TX> Q[40050];

const short di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const short dj[] = {1, 0, -1, 0, 1, -1, 1, -1};

int n, m, iv, jv, xc;
int a[1001][1001], dp[1001][1001];


void Fill(int i, int j, int c);
int Multiplication(int a, int b);
void Solve();
void Read();
bool Ok(int i, int j);

int main()
{
    Read();
    Solve();
    is.close();
    os.close();
    return 0;
}

void Solve()
{
    Q[0].push(start);
    for (int cost = 0; cost <= 40050; cost++)
    {
        while (!Q[cost].empty())
        {
            Ac = Q[cost].front(), Q[cost].pop();
            xc = a[Ac.first][Ac.second];
            if (dp[Ac.first][Ac.second] == -1)
                Fill(Ac.first, Ac.second, cost);
            if (dp[finish.first][finish.second] != -1)
            {
                os << dp[finish.first][finish.second];
                return;
            }
        }
    }
};

void Fill(int i, int j, int c)
{
    if (Ok(i, j) == false || dp[i][j] != -1) return;
    if (a[i][j] == xc)
    {
        dp[i][j] = c;
        for (int dir = 0; dir < 8; dir++)
        {
            iv = i + di[dir];
            jv = j + dj[dir];
            Fill(iv, jv, c);
        }
    }
    else
    {
        aux.first = i, aux.second = j;
        Q[c + Multiplication(a[i][j], xc)].push(aux);
    }
};

int Multiplication(int a, int b)
{
    if (a == b) return 0;
    else
        return a*b;
};

bool Ok(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m) return false;
    return true;
};

void Read()
{
    is >> n >> m >> start.first >> start.second >> finish.first >> finish.second;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            is >> a[i][j];
            dp[i][j] = -1;
        }
};
