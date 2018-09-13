#include <fstream>
#include <iomanip>
using namespace std;

ifstream is ("dezastru.in");
ofstream os ("dezastru.out");

int N, K, C[26][26];
double D[26][26], v[26];

int main()
{
    is >> N >> K;
    for (int i = 1; i <= N; ++i)
        is >> v[i];
    for (int i = 1; i <= N; ++i)
        D[i][0] = C[i][i] = C[i][0] = 1;
    D[0][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            D[i][j] = D[i-1][j-1]*v[i] + D[i-1][j];
    os << setprecision(6) << D[N][K]/C[N][K];
    is.close();
    os.close();
}
