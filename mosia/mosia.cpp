#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

#define x first
#define y second.first
#define d second.second
#define TP pair <double, pair<double,int> >
ifstream is ("mosia.in");
ofstream os ("mosia.out");

int N, pos;
TP v[1005], pol;
double Aria, Moved[1005], D[1005], sol;

inline double CMP(const TP A, const TP B);
inline double CMP2(const double A, const double B);
double Dist(TP A, TP B);

int main()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
    {
        is >> v[i].x >> v[i].y >> v[i].d;
        pol.x += v[i].x;
        pol.y += v[i].y;
    }
    pol.x /= N;
    pol.y /= N;
    sort(v+1, v+N+1, CMP);
    v[N+1] = v[1]; v[0] = v[N];
    for (int i = 2; i < N; ++i)
        Moved[i] = v[i].d * Dist(v[i+1], v[i-1]) / 2.0;
    Moved[1] = v[1].d * Dist(v[2], v[N]) / 2.0;
    Moved[N] = v[N].d * Dist(v[1], v[N-1]) / 2.0;

    D[1] = Moved[1];
    for (int i = 1; i < N; ++i)
        D[i] = max(D[i-2]+Moved[i], D[i-1], CMP2);
    sol = D[N-1];

    memset(D, 0, sizeof(D));

    for (int i = 2; i <= N; ++i)
        D[i] = max(D[i-2]+Moved[i], D[i-1], CMP2);

    sol = max(sol, D[N], CMP2);
    os << fixed;
    os << setprecision(4) << sol;

    is.close();
    os.close();
}

double Dist(TP A, TP B)
{
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
};

inline double CMP(const TP A, const TP B)
{
    return atan2(A.y - pol.y , A.x - pol.x) < atan2(B.y - pol.y,B.x - pol.x);
};

inline double CMP2(const double A, const double B)
{
    return 1LL * A * 1000000 < 1LL * B * 1000000;
};
