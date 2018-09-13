#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int Nmax = 1024 + 2;
const int Di[] = {-1, 0, 1, 0},
          Dj[] = {0, 1, 0, -1};

ifstream cin ("alpin.in");
ofstream cout ("alpin.out");

int N, A[Nmax][Nmax], DP[Nmax][Nmax];
int FatherI[Nmax][Nmax], FatherJ[Nmax][Nmax], SourceI, SourceJ, Lmax;

void Input();
int DFS(int i, int j);
bool Ok(int i, int j);
void Path(int i, int j);

int main()
{
    Input();
    for (int i = 1, D; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            D = DFS(i, j);
            if (D > Lmax)
                Lmax = D, SourceI = i, SourceJ = j;
        }
  //  for (int i = 1; i <= N; ++i, cout << '\n')
  //      for (int j = 1; j <= N; ++j)
  //          cout << DP[i][j] << ' ';

    cout << Lmax << '\n';
    Path(SourceI, SourceJ);
}

int DFS(int i, int j)
{
    if (!Ok(i, j)) return 0;
    if (DP[i][j]) return DP[i][j];

    //cout << i << ' ' << j << '\n';

    for (int dir = 0, iv, jv, D; dir < 4; ++dir)
    {
        iv = i + Di[dir];
        jv = j + Dj[dir];
        if (A[iv][jv] > A[i][j])
        {
            D = DFS(iv, jv);
            if (D > DP[i][j])
                DP[i][j] = D, FatherI[i][j] = iv, FatherJ[i][j] = jv;
        }
    }
    DP[i][j]++;
    return DP[i][j];
};

void Path(int i, int j)
{
    if (i == 0 || j == 0) return;
    cout << i << ' ' << j << '\n';
    Path(FatherI[i][j], FatherJ[i][j]);
};

bool Ok(int i, int j)
{
    if (i < 1 || j < 1 || i > N || j > N) return 0;
    return 1;
};

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> A[i][j];
};
