#include <fstream>
using namespace std;

ifstream is ("mere.in");
ofstream os ("mere.out");

long long N, K, T, x, y;

int main()
{
    is >> T;
    for (int t = 0; t < T; ++t)
    {
        is >> N >> K;
        x = N/K;
        y = N%K;
        if (x == 0)
            os << "Remiza\n";
        else
        {
            if (x % 2 == 1)
                os << "Santa Klaus\n";
            else
                if (y == 0)
                    os << "Remiza\n";
                else
                    os << "Santa Klaus\n";
        }
    }
    is.close();
    os.close();
}
