#include <fstream>
using namespace std;

ifstream is ("matrix.in");
ofstream os ("matrix.out");

int N, M, C[26], x, sol;
unsigned short D[26][1001][1001];
char A[1001][1001], ch;

bool OK(int i, int j);

int main()
{
    is >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            is >> A[i][j], D[A[i][j]-97][i][j] = 1;
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= M; ++j)
            is >> ch, C[ch-'a']++;
    for (int k = 0; k < 26; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                D[k][i][j] = D[k][i-1][j] + D[k][i][j-1] -
                             D[k][i-1][j-1] + D[k][i][j];
    for (int i = M; i <= N; ++i)
        for (int j = M; j <= N; ++j)
            if (OK(i, j) == 1)
                sol++;
    os << sol << '\n';
    is.close();
    os.close();
}

bool OK(int i, int j)
{
    for (int k = 0; k < 26; ++k)
        if (C[k] != (D[k][i][j]-D[k][i-M][j]-D[k][i][j-M]+D[k][i-M][j-M]))
            return false;
    return true;
};
