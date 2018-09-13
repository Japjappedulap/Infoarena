#include <fstream>
using namespace std;

ifstream is ("flori4.in");
ofstream os ("flori4.out");

int n;
int D[10003];

int main()
{
    is >> n;
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        D[i] = ((D[i-1]*2) - D[i-3]);
        D[i] %= 9001;
        while (D[i] < 0)
            D[i] += 9001;
    }
    os << D[n];
    is.close();
    os.close();
    return 0;
}
