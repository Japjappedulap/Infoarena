#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("magicmatrix.in");
ofstream os ("magicmatrix.out");

int T, n;
int a[501][501];
bool CM;

bool CheckMagic();

int main()
{
    is >> T;
    for (int t = 0; t < T; t++)
    {
        is >> n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                is >> a[i][j];
        if (CheckMagic() == true)
            os << "YES" << '\n';
        else
            os << "NO" << '\n';
        memset(a, 0, sizeof(a));
    }
    is.close();
    os.close();
    return 0;
}

bool CheckMagic()
{
    int x;
    for (int i = 2; i <= n; ++i)
    {
        x = a[i][1] - a[i-1][1];
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] - a[i-1][j] != x)
                return false;
        }
    }
    return true;
};
