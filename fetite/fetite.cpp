#include <fstream>
using namespace std;

ifstream is ("fetite.in");
ofstream os ("fetite.out");

long long n;
long long Solve(long long x);

int main()
{
    is >> n;
    os << Solve(n);
    is.close();
    os.close();
    return 0;
}

long long Solve(long long x)
{
    if (x == 1) return 1;
    if (x % 2 == 0) return 2*Solve(x/2)-1;
    if (x % 2 == 1) return 2*Solve(x/2)+1;
};
