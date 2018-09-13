#include <fstream>
#include <cmath>
using namespace std;

ifstream is ("copaci.in");
ofstream os ("copaci.out");

#define PII pair<long long,long long>
#define x first
#define y second

long long N;
PII P[100001], Origin;

long long Area(PII A, PII B)  //returns 2x area, with origin
{
    return ((A.x*B.y) - (A.y*B.x));
}

long long GCD(long long A, long long B)
{
    if (!B) return A;
    return GCD(B, A % B);
}

int main()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
        is >> P[i].x >> P[i].y;
    P[0] = P[N];
    long long A = 0;
    long long B = 0;
    long long I;
    for (int i = 1; i <= N; ++i)
        A += Area(P[i-1], P[i]), B += GCD(abs(P[i-1].x - P[i].x), abs(P[i-1].y - P[i].y));

    I = (A - B) / 2 + 1;

    os << I;
    is.close();
    os.close();
}
