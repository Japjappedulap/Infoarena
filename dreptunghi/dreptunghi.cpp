#include <fstream>
using namespace std;

ifstream is ("dreptunghi.in");
ofstream os ("dreptunghi.out");

int n, m, x;
int sol1, sol2;

int main()
{
    is >> n >> m;
    sol1 = n + m;
    while (m)
    {
        x = n % m;
        n = m;
        m = x;
        sol2 = n;
    }
    os << sol1-sol2;


    is.close();
    os.close();
    return 0;
}
