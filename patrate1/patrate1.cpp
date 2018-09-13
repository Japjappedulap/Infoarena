#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define DIM 1000
ifstream is("patrate1.in");
ofstream os("patrate1.out");

struct Capat { // capat de interval (stanga sau dreapta
    int x;
    int sgn;  // -1 capat stanga, +1 capat dreapta
};

int n, H, L, Lmax, S;
Capat c[2*DIM];
void Sort();

int main()
{
    is >> n >> H;
    int x, p;
    for (int i = 0; i < n; i++)
    {
        is >> c[i].x >> p;
        c[i+n].x = c[i].x + p;
        c[i].sgn = 1;
        c[i + n].sgn = -1;
    }
    //sort(c.begin(), c.end());
    Sort();
    int cnt = 0, Lmax = 0, lf = -1;
    for (int i = 0; i < 2 * n; i++)
    {
        if (cnt == H - 1 && c[i].sgn == 1)
            lf = c[i].x;
        else
            if (cnt == H && c[i].sgn == -1)
            {
                L = c[i].x - lf;
                if (L > Lmax)
                    Lmax = L, S = lf;
            }
        cnt += c[i].sgn;
    }
    os << S << ' ' << Lmax << '\n';
    is.close();
    os.close();
    return 0;
}

void Sort()
{
    Capat aux;
    for ( int i = 0; i < 2*n - 1; ++i )
        for ( int j = i + 1; j < 2*n; ++j )
            if ( c[i].x > c[j].x || c[i].x == c[j].x && c[i].sgn < c[j].sgn)
            {
                aux = c[i]; c[i] = c[j]; c[j] = aux;
            }
}
