#include <fstream>
#include <queue>
#include <stack>
using namespace std;
ifstream is ("sudest.in");
ofstream os ("sudest.out");

struct Cel{
    int i, j;
};

queue <Cel> Q[250];
stack <Cel> S;

int a[101][101], b[101][101], n, k, x[200];

void Read();
void Lee();
void Path();
bool OK(int i, int j);
bool Okpath(int i, int j);

int main()
{
    Read();
    Lee();
    Path();
    is.close();
    os.close();
    return 0;
}

void Lee()
{
    int i, j, iv, jv;
    Cel Ac;
    i = 1, j = 1;
    Ac.i = i;
    Ac.j = j;
    Q[1].push(Ac);
    for ( int q = 1; q <= k; q++ )
    {
        is >> x[q];
        while (Q[q].empty() == false)
        {
            Ac = Q[q].front();
            i = Ac.i;
            j = Ac.j;
            Q[q].pop();
            iv = i + x[q];
            jv = j;
            if (OK(iv, jv) == true && b[iv][jv] < b[i][j] + a[iv][jv])
            {
                b[iv][jv] = a[iv][jv] + b[i][j];
                Ac.i = iv;
                Ac.j = jv;
                Q[q+1].push(Ac);
            }
            iv = i;
            jv = j + x[q];
            if (OK(iv, jv) == true && b[iv][jv] < b[i][j] + a[iv][jv])
            {
                b[iv][jv] = a[iv][jv] + b[i][j];
                Ac.i = iv;
                Ac.j = jv;
                Q[q+1].push(Ac);
            }
        }
    }
    os << b[n][n] << '\n';
};

bool OK(int i, int j)
{
    if ( i > n || j > n || i < 1 || j < 1 )return false;
    return true;
};

void Path()
{
    int i, j, iv, jv;
    Cel Ac;
    i = n, j = n;
    int q = k;
    while (Okpath(i, j) == false)
    {
        Ac.i = i;
        Ac.j = j;
        S.push(Ac);
        iv = i - x[q];
        jv = j;
        if (b[i][j] == b[iv][jv] + a[i][j] && OK(iv, jv) == true)
        {
            i = iv;
            j = jv;
            Ac.i = i;
            Ac.j = j;
            S.push(Ac);
        }
        iv = i;
        jv = j - x[q];
        if (b[i][j] == b[iv][jv] + a[i][j] && OK(iv, jv) == true)
        {
            i = iv;
            j = jv;
            Ac.i = i;
            Ac.j = j;
            S.push(Ac);
        }
        q--;
        S.pop();
    }
    Ac.i = 1;
    Ac.j = 1;
    S.push(Ac);
    while (S.empty() == false)
    {
        Ac = S.top();
        i = Ac.i;
        j = Ac.j;
        os << i << ' ' << j << '\n';
        S.pop();

    }
};

bool Okpath(int i, int j)
{
    if (i == 1 && j == 1) return true;
    return false;
};

void Read()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            is >> a[i][j];
    b[1][1] = a[1][1];
    is >> k;
};
