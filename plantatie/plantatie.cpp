#include <fstream>
using namespace std;

ifstream is ("plantatie.in");
ofstream os ("plantatie.out");

int N, Q;
int R[11][501][501], Log[501];

int main()
{
    is >> N >> Q;

    for (int i = 2; i <= N; ++i)
        Log[i] = Log[i/2] + 1;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            is >> R[0][i][j];

    for (int L = 1; (1 << L) <= N; ++L)
        for (int i = 1; i + (1 << L) - 1 <= N; ++i)
            for (int j = 1; j + (1 << L) - 1 <= N; ++j)
                R[L][i][j] = max(R[L - 1][i][j], R[L - 1][i + (1 << (L-1))][j]),

                R[L][i][j] = max(R[L][i][j], R[L - 1][i][j + (1 << (L-1))]),

                R[L][i][j] = max(R[L][i][j], R[L - 1][i + (1 << (L-1))][j + (1 << (L-1))]);

    for (int q = 1, i, j, k, L; q <= Q; ++q)
    {
        is >> i >> j >> k;
        L = Log[k];
        os << max(max(R[L][i][j], R[L][i][j + k - (1 << L)]), max(R[L][i + k - (1 << L)][j], R[L][i + k - (1 << L)][j + k - (1 << L)])) << '\n';
    }

    is.close();
    os.close();
}
