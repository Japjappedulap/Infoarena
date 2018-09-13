#include <fstream>
#include <queue>
using namespace std;

ifstream is ("rj.in");
ofstream os ("rj.out");

int m, n, iM, jM, tM = 99999;
int a[102][102];
int b[102][102];
char t[102][102], x;

struct Cel{
    int i, j;
};

Cel R, J;

queue <Cel> Q;

void Read();
void LeeR();
void LeeJ();
bool Ok(int i, int j);
const int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[8] = { 0,  1, 1, 1, 0,-1,-1, -1};
void Solve();
void DebugR();
void DebugJ();

int main()
{
    Read();
    LeeR();
    LeeJ();
    Solve();
    is.close();
    os.close();
    return 0;
}

void Solve()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if (a[i][j] == b[i][j] && a[i][j] != 0 && a[i][j] < tM)
                iM = i, jM = j, tM = a[i][j];
        }
    os << tM << ' ' << iM << ' ' << jM;
};

void LeeJ()
{
    int i, j, iv, jv;
    Cel Ac;
    b[J.i][J.j] = 1;
    Ac.i = J.i;
    Ac.j = J.j;
    Q.push(Ac);
    while (Q.empty() == false)
    {
        Ac = Q.front();
        i = Ac.i;
        j = Ac.j;
        Q.pop();
        for ( int d = 0; d < 8; ++d )
        {
            iv = i + di[d];
            jv = j + dj[d];
            if ( Ok(iv, jv) == true && b[iv][jv] < 1)
            {
                b[iv][jv] = b[i][j] + 1;
                Ac.i = iv;
                Ac.j = jv;
                Q.push(Ac);
            }
        }
    }
};

void LeeR()
{
    int i, j, iv, jv;
    Cel Ac;
    a[R.i][R.j] = 1;
    Ac.i = R.i;
    Ac.j = R.j;
    Q.push(Ac);
    while (Q.empty() == false)
    {
        Ac = Q.front();
        i = Ac.i;
        j = Ac.j;
        Q.pop();
        for ( int d = 0; d < 8; ++d )
        {
            iv = i + di[d];
            jv = j + dj[d];
            if ( Ok(iv, jv) == true && a[iv][jv] < 1)
            {
                a[iv][jv] = a[i][j] + 1;
                Ac.i = iv;
                Ac.j = jv;
                Q.push(Ac);
            }
        }
    }
};

bool Ok(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m)
        return false;
    if (t[i][j] == 'X')
        return false;
    return true;
};

void Read()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            x = is.get();
            if (x == '\n') x = is.get();
            if (x == 'X' || x == 'R' || x == 'J' || x == ' ')
                t[i][j] = x;
            if (x == 'R') R.i = i, R.j = j;
            if (x == 'J') J.i = i, J.j = j;
        }
};
