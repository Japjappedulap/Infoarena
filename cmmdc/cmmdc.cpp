#include <fstream>
using namespace std;

ifstream is ("cmmdc.in");
ofstream os ("cmmdc.out");

int a, b;

int main()
{
    is >> a >> b;
    while (a != b)
    {
        if (a > b) a -= b;
        else    b -= a;
    }
    if (a == 1)
        a = 0;
    os << a;

    is.close();
    os.close();
    return 0;
}
