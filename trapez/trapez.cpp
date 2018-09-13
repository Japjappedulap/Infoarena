#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#define TX pair<int,int>
#define x first
#define y second
#define INF 0x3f3f3f3f
#define EPS 0.00000000001

ifstream is ("trapez.in");
ofstream os ("trapez.out");

int n, aux;
TX e;

vector <TX> v;
vector <double> D;

double Slope(TX A, TX B);

int main()
{
    is >> n;
    aux = ((1LL * n * (n-1)) / 2 ) + 1;
    v.resize(n+1);
    for (int i = 1; i <= n; ++i)
    {
        is >> v[i].x >> v[i].y;
        for (int j = i-1; j >= 1; --j)
            D.push_back(Slope(v[i], v[j]));
    }
    sort(D.begin(), D.end());
    int eq = 0, sol = 0, j;
    for (int i = 0; i < D.size(); ++i)
    {
        j = i;
        if (abs(D[i+1]-D[i]) < EPS) eq++;
        else
        {
            sol += (eq*(eq+1)) / 2;
            eq = 0;
        }
    }
    sol += (eq*(eq+1)) / 2;
    if (j != D.size()-1)
    {
        eq = D.size() - j - 1;
        sol += (eq * (eq+1)) / 2;
    }
    os << sol;
    is.close();
    os.close();
    return 0;
}

double Slope(TX A, TX B)
{
    if (B.x == A.x) return INF;
    if (B.y == A.y) return 0;
    return 1. * (B.y - A.y) / (B.x - A.x);
};
