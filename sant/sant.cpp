#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

#define S 102
#define INF 2e7

ifstream is ("sant.in");
ofstream os ("sant.out");

int n, L, c, LC, LP;
int l[S], p[S];
int DP[2][1006], T[S][1006];

vector <int> sol;

int main()
{
    is >> L >> n >> c;
    for (int i = 1; i <= c; ++i)
        is >> l[i] >> p[i];
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= L; ++j)
            DP[i][j] = INF;
    DP[0][0] = 0, LC = 1, LP = 0;
    for (int i = 1; i <= n; ++i, swap(LC, LP))
        for (int j = L; j >= 0; --j)
        {
            for (int k = 1; k <= c; ++k)
                if (j + l[k] <= L && DP[LP][j] + p[k] < DP[LC][j+l[k]])
                {
                    DP[LC][j+l[k]] = DP[LP][j] + p[k];
                    T[i][j+l[k]] = k;
                }
            DP[LP][j] = INF;
        }

    if (DP[n%2][L] != INF)
    {
        for (int i = n, j = L; T[i][j] != 0; --i)
            sol.push_back(T[i][j]), j -= l[T[i][j]];
        os << DP[n%2][L] << '\n';
        sort(sol.begin(), sol.end());
        for (int i = 0; i < sol.size(); ++i)
            os << sol[i] << ' ';
    }
    else os << 0;
    is.close();
    os.close();
    return 0;
}

