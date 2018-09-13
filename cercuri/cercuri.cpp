#include <fstream>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

ifstream is ("cercuri.in");
ofstream os ("cercuri.out");

#define x first
#define y second
#define eps 0.0001

typedef pair<double, double> Point;

int T;
Point c1, c2;
double R1, R2;

void Solve();

int main()
{
    os << fixed;
    for (is >> T; T; --T) Solve();
    is.close();
    os.close();
}

void Solve()
{
    double R, X, D;
    is >> c1.x >> c1.y >> R1 >> c2.x >> c2.y >> R2;
    if (c1 == c2 && R1 == R2) { os << "-1\n"; return; }
    if (c1 == c2 ) { os << "-2\n"; return; }
    D = sqrt( (c2.x-c1.x)*(c2.x-c1.x) + (c2.y-c1.y)*(c2.y-c1.y) );
    R = R2*R2 - R1*R1;
    if (fabs(R1+R2-D) < eps) { os << "-3\n"; return; }
    if (R1+R2-D < -eps) { os << "-2\n"; return; }
    X = (D - R/D ) / 2;
    if (X < -min(R2 - D, R1) - eps || X > max(R2 + D, R1) + eps){ os << "-2\n"; return; }
    R =  sqrt(abs((R1*R1) - (X*X)));
    if (abs(R) < eps) { os << "-3\n"; return; }
    os << setprecision(3) << 2*R << '\n';
};
