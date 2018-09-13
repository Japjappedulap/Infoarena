#include <fstream>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
#define TX pair<int,int>
#define eps 0.01
ifstream is ("excursie.in");
ofstream os ("excursie.out");

const int Di[] = {-1, 0, 1, 0}, Dj[] = {0, 1, 0, -1};

int n, m, a[51][51];
TX S, F;
double Ln;
queue <TX> Q;
double D[51][51], Ef[51][51];

void Read();
void Lee();
double Strofoacate(int i, int j, int iv, int jv);
bool Ok(int i, int j);

int main()
{
    Read();
    Lee();
    int x, cnt = 0;
    x = Ef[F.first][F.second];
    while (x != 0) cnt++, x /= 10;
    os << setprecision(cnt+3) << Ef[F.first][F.second] << ' ';
    x = D[F.first][F.second]; cnt = 0;
    while (x != 0) cnt++, x /= 10;
    os << setprecision(cnt+3) << D[F.first][F.second] << ' ';

    is.close();
    os.close();
    return 0;
}

void Read()
{
    is >> n >> m;
    is >> Ln;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            is >> a[i][j], Ef[i][j] = 0x3f3f3f3f, D[i][j] = 0x3f3f3f3f;
    is >> S.first >> S.second >> F.first >> F.second;
};

void Lee()
{
    int i, j, iv, jv;
    double ef, d, alpha;
    Q.push(S);
    Ef[S.first][S.second] = 0;
    D[S.first][S.second] = 0;
    for ( ; !Q.empty() ; Q.pop())
    {
        i = Q.front().first;
        j = Q.front().second;
        for (int Dir = 0; Dir < 4; ++Dir)
        {
            iv = i + Di[Dir];
            jv = j + Dj[Dir];
            if (Ok(iv, jv))
            {
                d = sqrt(((a[iv][jv]-a[i][j])*(a[iv][jv]-a[i][j])) + 1);
                d = abs(d);
                if (d + D[i][j] < Ln)
                {
                    ef = Strofoacate(i, j, iv, jv) + Ef[i][j];
                    if (ef < Ef[iv][jv] || (abs(Ef[iv][jv] - ef) < eps && D[iv][jv] > D[i][j] + d))
                    {
                        Ef[iv][jv] = ef;
                        D[iv][jv] = D[i][j] + d;
                        Q.push(make_pair(iv, jv));
                    }
                }
            }
        }
    }
};

double Strofoacate(int i, int j, int iv, int jv)
{
    if ( a[i][j] == a[iv][jv] )
        return 1;
    double f = a[iv][jv] - a[i][j];
    double e = f * sqrt(f * f + 1);
    return e > 0 ? e : -(e / 2);
};

bool Ok(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m) return false;
    return true;
};
