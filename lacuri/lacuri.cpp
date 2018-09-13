#include <fstream>
#include <queue>
#include <stack>
using namespace std;

ifstream is ("lacuri.in");
ofstream os ("lacuri.out");

struct Cel{ int i, j;};
queue <Cel> Q;
stack <Cel> S;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

bool a[101][101], c[101][101];
int n, k;
int b[101][101], cnt, cntl;
bool NoLee;

void Read();
void Solve();
void Fill(int i, int j);
void Lee();
bool Ok(int i, int j);
bool PerfectSquare(int kx);
bool FullWater(int i, int j, int kx);


int main()
{
    Read();
    Solve();
    if (NoLee == false)
        Lee();
    is.close();
    os.close();
    return 0;
}


void Lee()
{
    Cel Ac;
    int i, j, iv, jv;
    Ac.i = 1, Ac.j = 1;
    Q.push(Ac);
    while (!Q.empty())
    {
        Ac = Q.front(), Q.pop();
        i = Ac.i, j = Ac.j;
        for (int d = 0; d < 4; ++d)
        {
            iv = i + di[d];
            jv = j + dj[d];
            if (a[iv][jv] == 0 && Ok(iv, jv) == true && b[iv][jv] == 0)
            {
                b[iv][jv] = b[i][j] + 1;
                Ac.i = iv, Ac.j = jv;
                Q.push(Ac);
            }
        }
    }
    b[1][1] = 0;
    i = n, j = n;
    Ac.j = i, Ac.j = j;
    S.push(Ac);
    while(i != 1 || j != 1)
    {
        for (int d = 0; d < 4; ++d)
        {
            iv = i + di[d];
            jv = j + dj[d];
            if (b[iv][jv] + 1 == b[i][j] && a[iv][jv] == 0 && Ok(iv, jv) == true)
            {
                i = iv, j = jv;
                Ac.i = i, Ac.j = j;
                S.push(Ac);
                break;
            }
        }

    }
    while (!S.empty())
    {
        Ac = S.top();
        os << Ac.i << ' ' << Ac.j << '\n';
        S.pop();
    }
};

void Solve()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cnt = 0;
            if (a[i][j] == 1 && c[i][j] == 0)
            {
                k = 0;
                Fill(i, j);
                if (PerfectSquare(cnt) == true)
                {
                    if (FullWater(i, j, k) == true)
                        cntl++;
                    else
                        NoLee = true;
                }
                else
                    NoLee = true;
            }
        }
    os << cntl << '\n';
};

void Fill(int i, int j)
{
    if (Ok(i, j) != true || a[i][j] == false || c[i][j] == true) return;
    c[i][j] = true;
    cnt++;
    Fill(i-1, j);
    Fill(i, j+1);
    Fill(i+1, j);
    Fill(i, j-1);
};

bool FullWater(int i, int j, int kx)
{
    for (int i1 = i; i1 < i+kx; i1++)
        for (int j1 = j; j1 < j+kx; j1++)
            if (a[i1][j1] == 0) return false;
    return true;
};

bool PerfectSquare(int kx)
{
    for (int i = 1; i * i <= kx; ++i)
        if (i*i == kx)
        {
            k = i;
            return true;
        }
    return false;
};

bool Ok(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > n) return false;
    return true;
};

void Read()
{
    is >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            is >> a[i][j];
};

