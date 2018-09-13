#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream is ("cai.in");
ofstream os ("cai.out");

#define INF 1002
#define SIZE 1002

int T;
int N, A[2][SIZE];
short DP[SIZE][SIZE];

void Solve();

int main()
{
	for (is >> T; T; --T) Solve();
	is.close();
	os.close();
}

void Solve()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
        is >> A[0][i];
    for (int i = 1; i <= N; ++i)
        is >> A[1][i];
    sort(A[0] + 1, A[0] + N + 1);
    sort(A[1] + 1, A[1] + N + 1);
    for (int i = 0; i <= N + 1; ++i)
        for (int j = 0; j <= N + 1; ++j)
            DP[i][j] = -INF;
    memset(DP[0], 0, sizeof(DP[0]));
    short result = -INF;
    for (int i = 1; i < N; ++i)
        for (int j = 1; j <= i + 1; ++j)
        {
            int k = j + N - i - 1;
            if (j - 1 != 0)
            {
                if (A[0][i] < A[1][j - 1])      DP[i][j] = DP[i - 1][j - 1] - 1;
                else if (A[0][i] > A[1][j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
                else                            DP[i][j] = DP[i - 1][j - 1];
            }
            if (k + 1 != N + 1)
            {
                if (A[0][i] < A[1][k + 1] && DP[i - 1][j] - 1 > DP[i][j])      DP[i][j] = DP[i - 1][j] - 1;
                else if (A[0][i] > A[1][k + 1] && DP[i - 1][j] + 1 > DP[i][j]) DP[i][j] = DP[i - 1][j] + 1;
                else if (A[0][i] == A[1][k + 1] && DP[i - 1][j] > DP[i][j])    DP[i][j] = DP[i - 1][j];
            }
        }
    for (int i = 1; i <= N; ++i)
        if (A[0][N] < A[1][i] && DP[N - 1][i] - 1 > result)      result = DP[N - 1][i] - 1;
        else if (A[0][N] > A[1][i] && DP[N - 1][i] + 1 > result) result = DP[N - 1][i] + 1;
        else if (A[0][N] == A[1][i] && DP[N - 1][i] > result)    result = DP[N - 1][i];
    os << result * 200 << '\n';
};
