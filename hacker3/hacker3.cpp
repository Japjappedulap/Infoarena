#include <fstream>
#include <cstring>
using namespace std;
#define ll long long
ifstream is ("hacker3.in");
ofstream os ("hacker3.out");

int n, LC = 1, LP;
ll x, y, R = 4611686018427387904;
ll D[3][51];
ll Lpow[51];

int main()
{
    is >> n;
    Lpow[0] = 1;
    for (int i = 1; i <= 50; ++i)
        Lpow[i] = Lpow[i-1]*2;
    for (int i = 1; i <= n; ++i, swap(LC, LP))
    {
        is >> x >> y;
        for (int j = 0; j <= 50 && j <= i; ++j)
            if (j == 0)
                D[LC][j] = D[LP][j] + y * Lpow[j];
            else
                if (j == 50 || j == i)
                    D[LC][j] = D[LP][j-1] + x * Lpow[j-1];
                else
                    D[LC][j] = min((D[LP][j] + y * Lpow[j]), (D[LP][j-1] + x * Lpow[j-1]));
    }
    for (int j = 0; j <= 50 && j < n; ++j)
        if (R > D[LP][j] && D[LP][j] > 0) R = D[LP][j];
    os << R;
    is.close();
    os.close();
    return 0;
}
