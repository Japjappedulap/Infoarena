#include <fstream>
#include <cstring>
using namespace std;

#define N_SIZE 19
#define S_SIZE 1000001
#define R 2000000

ifstream fin ("triunghi.in");
ofstream fout ("triunghi.out");

int n, S, sum, x, val;
int a[N_SIZE][N_SIZE][N_SIZE];
int v[N_SIZE];
int D[S_SIZE];
int TRI[N_SIZE][N_SIZE];

void Read();
void Solve();

int main()
{
    Read();
    Solve();
    fin.close();
    fout.close();
    return 0;
}

void Solve()
{
    if (sum > S)
    { fout << "imposibil"; return; }
    D[sum] = sum;
    for (int i = 1; i <= n && !D[S]; ++i)
        for (int j = sum; j + v[i] <= S; ++j)
            if (D[j]) D[j+v[i]] = j + R*i;
    if (!D[S])
    { fout << "imposibil"; return; }
    x = S;
    memset(v, 0, sizeof(v));
    while (D[x] != sum)
    {
        v[D[x] / R]++;
        x = D[x] % R;
    }
    for (int i = 1; i <= n; ++i)
    {
        v[i]++;
        TRI[n][i] = v[i];
    }
    for (int i = n-1; i >= 1; --i)
        for (int j = 1; j <= i; ++j)
            TRI[i][j] = TRI[i+1][j] + TRI[i+1][j+1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
            fout << TRI[i][j] << ' ';
        fout << '\n';
    }
};

void Read()
{
    fin >> n >> S;
    for (int i = 1; i <= n; ++i) a[1][i][i] = 1, v[i] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= n+1-i; ++j)
            for (int k = 1; k <= n; ++k)
            {
                a[i][j][k] = a[i-1][j][k]+a[i-1][j+1][k];
                v[k] += a[i][j][k];
            }
    for (int i = 1; i <= n; ++i) sum += v[i];
};
