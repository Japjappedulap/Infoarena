/*
trimit de 100 de ori de ciuda ca puneti limite de kkt MUISTILOR
*/
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

#define Point pair<double, double>
#define x first
#define y second

ifstream is ("seg.in");
ofstream os ("seg.out");

const int Nmax = 17;
const double INF = 12345678.9;

int N;
Point Seg[Nmax][2];

double Dist[Nmax][2][Nmax][2], SOL;
double D[1<<Nmax][Nmax][2];     //D[mask][i][p] lantul hamiltonian de cost minim care incepe de la 0/0 ajunge
                                //in varful p al segmentului i, si sunt parcurse nodurile din masca
inline double Distance(Point A, Point B);
void Solve();

int main()
{
    int T;
    for (is >> T; T--; Solve(), os << '\n');
    is.close();
    os.close();
}

void Solve()
{
    is >> N;
    for (int i = 0; i < N; ++i)
        is >> Seg[i][0].x >> Seg[i][0].y,
        is >> Seg[i][1].x >> Seg[i][1].y;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            Dist[i][0][j][0] = Distance(Seg[i][0], Seg[j][0]),
            Dist[i][0][j][1] = Distance(Seg[i][0], Seg[j][1]),
            Dist[i][1][j][0] = Distance(Seg[i][1], Seg[j][0]),
            Dist[i][1][j][1] = Distance(Seg[i][1], Seg[j][1]);

    os << fixed;
    N--;
    for (int i = 0; i < (1<<N); ++i)
        for (int j = 0; j < N; ++j)
            D[i][j][0] = D[i][j][1] = INF;

    for (int i = 0; i < N; ++i)
        D[1<<i][i][0] = Dist[0][0][0][1] + Dist[0][1][i+1][1] + Dist[i+1][1][i+1][0],
        D[1<<i][i][1] = Dist[0][0][0][1] + Dist[0][1][i+1][0] + Dist[i+1][0][i+1][1];


    for (int mask = 1; mask < (1<<N); mask++)
    {
        for (int i = 0; (1<<i) <= mask; ++i)
            if (mask & (1<<i))
            for (int j = 0; (1<<j) <= mask; ++j)
                if ((mask & (1<<j)) && i != j)
                {

                    D[mask][i][0] = min(D[mask][i][0],
                        min(
                        D[mask - (1<<i)][j][0] + Dist[j+1][0][i+1][1] + Dist[i+1][1][i+1][0],
                        D[mask - (1<<i)][j][1] + Dist[j+1][1][i+1][1] + Dist[i+1][1][i+1][0])),

                    D[mask][i][1] = min(D[mask][i][1],
                        min(
                        D[mask - (1<<i)][j][0] + Dist[j+1][0][i+1][0] + Dist[i+1][0][i+1][1],
                        D[mask - (1<<i)][j][1] + Dist[j+1][1][i+1][0] + Dist[i+1][0][i+1][1]));

                }
    }

    SOL = INF;
    for (int bit = 0; bit < N; ++bit)
        SOL = min(SOL, min(
                    D[(1<<N)-1][bit][0] + Dist[bit+1][0][0][0],
                    D[(1<<N)-1][bit][1] + Dist[bit+1][1][0][0]));
    for (int bit = 0; bit <= N; ++bit)
        SOL -= Dist[bit][0][bit][1];
    os << SOL;
};

inline double Distance(Point A, Point B)
{
    return sqrt( (B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y) );
};
