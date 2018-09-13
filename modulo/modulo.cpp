#include <fstream>
#include <stack>
using namespace std;

ifstream is ("modulo.in");
ofstream os ("modulo.out");

long long a, b, c;
long long x;
stack <bool> S;


int main()
{
    is >> a >> b >> c;
    x = b;
    while (x != 0)
    {
        S.push(x % 2);
        if (x % 2 == 1)
            x--;
        x /= 2;
    }
    x = a % c;
    S.pop();
    while (!S.empty())
    {
        x *= x;
        if (S.top() == 1)
            x *= a;
        S.pop();
        x %= c;
    }
    os << x;
    is.close();
    os.close();
    return 0;
}
