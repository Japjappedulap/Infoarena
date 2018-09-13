// 100P - Vlad Potra
#include <fstream>
#include <vector>
#include <set>
using namespace std;

using VI = vector<int>;

ifstream is ("biperm.in");
ofstream os ("biperm.out");

int N, Sol2, Sol = 1, revedge, cyc, Size, Root, RootNext;
VI G[10001], GU[10001], A[2];
bool Explored[10001], Already;

set<pair<int,int> > Swaps;

void DFS(int x);

int main()
{
    is >> N;
    A[0] = A[1] = VI(N+1);
    for (int k = 0; k <= 1; ++k)
        for (int i = 1; i <= N; ++i)
            is >> A[k][i];
    for (int i = 1; i <= N; ++i)
    {
        Already = 0;
        G[A[0][i]].push_back(A[1][i]);
        for (const int& x : GU[A[0][i]])
            if (x == A[1][i])
                Already = 1;
        if (Already != 1)
            GU[A[0][i]].push_back(A[1][i]),
            GU[A[1][i]].push_back(A[0][i]);
    }
    for (int i = 1; i <= N; ++i)
        if (Explored[i] == 0)
        {
            if (G[i].empty()) continue;
            Size = revedge = RootNext = 0;
            Root = i;
            DFS(i);
            if (Size > 1)
                Sol <<= 1;
            else
                continue;
            bool Edge = 0;
            for (const int& j : G[Root])
                if (j == RootNext)
                    {Edge = 1; break;}
            if (Edge == 0)
                Swaps.insert({RootNext, Root}), revedge++;
            revedge = min(revedge, Size-revedge);
            Sol2 += revedge;
        }
    os << Sol << ' ' << Sol2 << '\n';
    for (int i = 1; i <= N; ++i)
    {
        auto it = Swaps.find({A[0][i], A[1][i]});
        if (it != Swaps.end())
            swap(A[0][i], A[1][i]), Swaps.erase(it);
    }
    for (int k = 0; k < 2; ++k, os << '\n')
        for (int i = 1; i <= N; ++i)
            os << A[k][i] << ' ';
    is.close();
    os.close();
}

void DFS(int x)
{
    Explored[x] = 1;
    Size++;
    RootNext = x;
    for (const int& y : GU[x])
    {
        if (y == x)
            return;
        if (Explored[y] == 0)
        {
            bool Edge = 0;
            for (const int& j : G[y])
                if (j == x)
                    {Edge = 1; break;}
            if (Edge == 0)
                Swaps.insert({x, y}), revedge++;

            DFS(y);
            continue;
        }
    }
};
