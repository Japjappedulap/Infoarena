#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

ifstream is ("capitala.in");
ofstream os ("capitala.out");

int N, Nr[200004], D[200004], sol(1<<30), node;
vector <int> G[200004];
bitset <200004> B, B2;

void DF1(int x);
void DF2(int x);

int main()
{
    is >> N;
    for (int i = 1, a, b; i < N; ++i)
    {
        is >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i)
        Nr[i] = 1;
    DF1(1);
    DF2(1);
    for (int i = 1; i <= N; ++i)
        if (sol > D[i]) sol = D[i], node = i;
    os << node << ' ' << sol;
    is.close();
    os.close();
}

void DF2(int x)
{
    B2[x] = 1;
    for (const auto& f : G[x])
        if (!B2[f])
        {
            D[f] = D[x] + Nr[x] - 2*Nr[f];
            Nr[f] = N;
            DF2(f);
        }
};

void DF1(int x)
{
    B[x] = 1;
    for (const auto& f : G[x])
        if (!B[f])
        {
            DF1(f);
            Nr[x] += Nr[f];
            D[x] += Nr[f] + D[f];
        }
};
