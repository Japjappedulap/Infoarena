#include <fstream>
#include <iomanip>
using namespace std;

ifstream is ("flip.in");
ofstream os ("flip.out");

int n, m, res = - 1<<31;
int C[17][20], S[20];

void BACKTRACK(int i);

int main()
{
    is >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            is >> C[i][j];
    BACKTRACK(1);
    os << res;
    is.close();
    os.close();
    return 0;
}

void BACKTRACK(int k)
{
    if (k == m+1)
    {
        int lsum;
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            lsum = 0;
            for (int j = 1; j <= m; ++j)
                lsum += C[i][j] * S[j];
            if (lsum < 0) sum -= lsum;
            else         sum += lsum;
        }
        if (sum > res) res = sum;
    }
    else
    {
        S[k] = 1;
        BACKTRACK(k+1);
        S[k] = -1;
        BACKTRACK(k+1);
    }
};

