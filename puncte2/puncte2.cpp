#include <fstream>
using namespace std;

ifstream is ("puncte2.in");
ofstream os ("puncte2.out");

int N, LC = 1, LP;
long long DP[2][6];

int main()
{
    is >> N;
    DP[0][1] = DP[0][0] = 1;
    for (int i = 1; i <= N; ++i, swap(LC, LP))
        for (int j = 0; j < 5; ++j)
        {
            if (j == 0) DP[LC][j] = 1;
            else        DP[LC][j] = DP[LP][j-1]+DP[LP][j];
        }

    os << DP[LC][4];
    is.close();
    os.close();
}
