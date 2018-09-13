#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream is ("insule.in");
ofstream os ("insule.out");

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

struct Cel{
    int i, j;
};

vector <int> vi;
vector <int> vj;

queue <Cel> Q;

int x;
bool b[102][102];
short int t[102][102], n, m, cntR, cntG, cntB, l[102][102], Sw = 30999, pw;
char y;

void Read();
void Islands();
void Fill(int i, int j, int x);
void ShortestBridge();
bool OKf(int i, int j, int x);
bool OKl(int i, int j);
bool OKr(int i, int j);

int main()
{
    Read();
    Islands();
    os << cntR << ' ' << cntG << ' ' << cntB << ' ';
    ShortestBridge();
    os << Sw-1;
    is.close();
    os.close();
    return 0;
}

void ShortestBridge()
{
    int i, j, iv, jv;
    Cel Ac;
    for (int oo = 0; oo < vi.size(); ++oo)
    {
        Ac.i = vi[oo];
        Ac.j = vj[oo];
        l[Ac.i][Ac.j] = 1;
        Q.push(Ac);
        while ( Q.empty() == false )
        {
            Ac = Q.front();
            if ( t[Ac.i][Ac.j] == 1 )
            {
                pw = l[Ac.i][Ac.j];
                break;
            }
            i = Ac.i;
            j = Ac.j;
            Q.pop();
            for ( int d = 0; d < 4; ++d )
            {
                iv = i + di[d];
                jv = j + dj[d];
                if ( OKl(iv, jv) == true && (l[iv][jv] == 0 || l[i][j] + 1 < l[iv][jv] ) )
                {
                    l[iv][jv] = l[i][j] + 1;
                    Ac.i = iv;
                    Ac.j = jv;
                    Q.push(Ac);
                }
            }
        }
        while (Q.empty() == false)
            Q.pop();
        if (pw < Sw && pw > 1)
            Sw = pw;
    }
};

bool OKl(int i, int j)
{
    if ( i < 1 || i > n ) return false;
    if ( j < 1 || j > m ) return false;

    if ( b[i][j] == false ) return true;
    if ( b[i][j] == true )
    {
        if (t[i][j] == 1) return true;
        else
            return false;
    }
    return true;
};

void Islands()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if (t[i][j] != 0 && b[i][j] == false)
            {
                x = t[i][j];
                Fill(i, j, x);
                if (x == 1) cntR++;
                if (x == 2) cntG++;
                if (x == 3) cntB++;
            }
        }
};

void Fill(int i, int j, int x)
{
    if ( OKf(i, j, x) == false )
        return;
    b[i][j] = true;
    Fill(i-1, j, x);
    Fill(i, j+1, x);
    Fill(i+1, j, x);
    Fill(i, j-1, x);

};

bool OKf(int i, int j, int x)
{
    if ( i < 1 || i > n ) return false;
    if ( j < 1 || j > m ) return false;
    if ( t[i][j] != x || b[i][j] == true) return false;
    return true;
};

void Read()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            is >> y;
            t[i][j] = y-48;
        }
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if (t[i][j] == 2)
            {
                if (OKr(i-1, j) == true)    vi.push_back(i-1), vj.push_back(j);
                if (OKr(i, j+1) == true)    vi.push_back(i), vj.push_back(j+1);
                if (OKr(i+1, j) == true)    vi.push_back(i+1), vj.push_back(j);
                if (OKr(i, j-1) == true)    vi.push_back(i), vj.push_back(j-1);
            }

};

bool OKr(int i, int j)
{
    if ( i < 1 || i > n ) return false;
    if ( j < 1 || j > m ) return false;
    if (t[i][j] != 0) return false;
    return true;
};
