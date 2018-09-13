#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

const int Nmax = 100 + 5;
const int INF = 0x3f3f3f3f;
const int Di[] = {-1, 0, 1, 0}, Dj[] = {0, 1, 0, -1};

ifstream cin ("taxe2.in");
ofstream cout ("taxe2.out");

int N, S;
int A[Nmax][Nmax];
int DP[Nmax][Nmax];
queue < pair <int, int> >  Q;

void Input();
bool Ok(int i, int j);
void BFS();

int main()
{
    Input();
    BFS();
    cout << max(S - DP[N][N], -1);
}

void BFS()
{
    Q.push({1, 1});
    DP[1][1] = A[1][1];

    for (int i, j; !Q.empty(); )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for (int iv, jv, dir = 0; dir < 4; ++dir)
        {
            iv = i + Di[dir];
            jv = j + Dj[dir];
            if (Ok(iv, jv) && DP[iv][jv] > DP[i][j] + A[iv][jv])
            {
                DP[iv][jv] = DP[i][j] + A[iv][jv];
                Q.push({iv, jv});
            }
        }
    }
};

void Input()
{
    cin >> S >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> A[i][j], DP[i][j] = INF;
};

bool Ok(int i, int j)
{
    return 1 <= i && i <= N && 1 <= j && j <= N;
};
