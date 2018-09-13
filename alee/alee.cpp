#include <fstream>
#include <queue>
using namespace std;

ifstream is ("alee.in");
ofstream os ("alee.out");

int n, m;
int b[176][176];
bool a[176][176];

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

struct Cel{
    int i, j;
};

queue <Cel> Q;

void Read();
void Lee();
bool Ok(int i, int j);

int main()
{
    Read();
    Lee();
    is.close();
    os.close();
    return 0;
}

void Lee()
{
    int i, j, iv, jv;
    Cel Ac, Fin;
    is >> Ac.i >> Ac.j >> Fin.i >> Fin.j;
    b[Ac.i][Ac.j] = 1;
    Q.push(Ac);
    while( Q.empty() == false && b[Fin.i][Fin.j] == 0)
    {
        Ac = Q.front();
        i = Ac.i;
        j = Ac.j;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i + di[d];
            jv = j + dj[d];
            if ( Ok(iv, jv) == true && b[iv][jv] == 0)
            {
                b[iv][jv] = b[i][j] + 1;
                Ac.i = iv;
                Ac.j = jv;
                Q.push(Ac);
            }
        }
    }
    os << b[Fin.i][Fin.j];
};

bool Ok(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > n) return false;
    if (a[i][j] == true)    return false;
    return true;
}

void Read()
{
    int i, j;
    is >> n >> m;
    for ( int k = 0; k < m; ++k )
    {
        is >> i >> j;
        a[i][j] = true;
    }
};
