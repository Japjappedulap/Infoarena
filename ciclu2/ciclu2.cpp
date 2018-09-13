#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream is ("ciclu2.in");
ofstream os ("ciclu2.out");

int N, M, Q, L, X;
bool found, B[201][201];
vector <int> G[201];

void Path(int x, int l);

int main()
{
    is >> N >> M;
    for (int i = 1, a, b; i <= M; ++i)
        is >> a >> b, G[a].push_back(b), G[b].push_back(a);
    is >> Q;
    for (int i = 1; i <= Q; ++i)
    {
        is >> X >> L;
        found = 0;
        memset(B, 0, sizeof(B));
        Path(X, 0);
        os << found << '\n';
    }

    is.close();
    os.close();
}

void Path(int x, int l)
{
    if (l == L && x == X)
    {
        found = 1;
        return;
    }
    if (l >= L)
        return;
    for (const auto& y : G[x])
    {
        if (found == 1)
            return;
        if (B[x][y] == 0)
            B[x][y] = 1, B[y][x] = 1, Path(y, l+1), B[x][y] = 0, B[y][x] = 0;
    }
};
