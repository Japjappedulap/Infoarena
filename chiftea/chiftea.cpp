#include <fstream>
#include <cmath>
using namespace std;

ifstream is ("chiftea.in");
ofstream os ("chiftea.out");

int T, n, y;
double x;

int main()
{
    is >> T;
    for (int t = 0; t < T; ++t)
    {
        is >> n;
        x = sqrt(n);
        if (int(x)*int(x) == n)
            os << int(4*x) << '\n';
        else
        {
            y = int(x);
            if ( x-y < 0.5 )
                os << (4*(y)+2) << '\n';
            else
                os << (4*(y+1)) << '\n';
        }
    }
    is.close();
    os.close();
    return 0;
}
