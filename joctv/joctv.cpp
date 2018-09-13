#include <fstream>
using namespace std;

ifstream is ("joctv.in");
ofstream os ("joctv.out");

int N;
int S[101][101], res = -1<<30, aux;

int main()
{
    is >> N;
    for (int i = 1, x; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            is >> x, S[i][j] = S[i-1][j] + x;
    for (int x = 0; x < N; ++x)
        for (int y = x+1; y <= N; ++y, aux = 0)
            for (int i = 1; i <= N; ++i)
            {
                if (aux < 0) aux = 0;
                aux = aux + S[y][i] - S[x][i];
                if (res < aux) res = aux;
            }
    os << res;
    is.close();
    os.close();
}
