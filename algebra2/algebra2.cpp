#include <fstream>
using namespace std;

ifstream is("algebra2.in");
ofstream os("algebra2.out");

#define MOD 1000000009

unsigned long long N, P, R;
unsigned long long LgExp(unsigned long long x,unsigned long long y);

int main()
{
    is >> N;
    if ( N%2 == 1)
        os << LgExp(LgExp(N%MOD,N)%MOD,(N+1)/2);
    else
        os << LgExp(LgExp(N%MOD,N+1)%MOD,(N)/2);
}

unsigned long long LgExp(unsigned long long x, unsigned long long y)
{
    if ( y == 0 )
        return 1;
    if ( y == 1 )
        return x%MOD;
    if ( y % 2 == 0 )
       return (LgExp(x,y/2)%MOD * LgExp(x,y/2)%MOD)%MOD;
    else
       return ((LgExp(x,y/2)%MOD * LgExp(x,y/2)%MOD)%MOD * (x%MOD))%MOD;
}
