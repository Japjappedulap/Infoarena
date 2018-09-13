#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define mk(x, y, z) make_pair(make_pair(x+y+z, x), make_pair(y, z))
#define sum first.first
#define fi first.second
#define se second.first
#define th second.second

ifstream is("loto.in");
ofstream os("loto.out");

int N, S, x[101], J;
vector <pair <pair <int,int> , pair <int,int> > > V;

void Input();
void Solve();
bool BS(int X);

int main()
{
    Input();
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; ++j)
            for (int k = j; k <= N; ++k)
                V.push_back(mk(x[i], x[j], x[k]));
    sort(V.begin(),V.end());
    Solve();
    is.close();
    os.close();
    return 0;
}

void Solve()
{
    int x;
    for (int i = 0; i < V.size(); ++i)
    {
        x = S - V[i].sum;
        if ( BS(x) == true )
        {
            os << V[i].fi << ' ' << V[i].se << ' ' << V[i].th << ' ' << V[J].fi << ' ' << V[J].se << ' ' << V[J].th << '\n';
            return;
        }
    }
    os << "-1\n";
};

bool BS(int X)
{
    int L = 0, R = V.size(), M;
    while ( L <= R )
    {
        M = (R+L)/2;
        if ( V[M].sum > X )
            R = M-1;
        if ( V[M].sum < X )
            L = M+1;
        if ( V[M].sum == X )
        {
            J = M;
            return true;
        }
    }
    return false;
};

void Input()
{
    is >> N >> S;
    for ( int i = 1; i <= N; ++i )
        is >> x[i];
}
