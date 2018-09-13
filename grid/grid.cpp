#include <fstream>
#include <list>
using namespace std;

ifstream is ("grid.in");
ofstream os ("grid.out");

int N, Q, i1, j1, i2, j2, val;
list <int> L[3];
list <int> :: iterator it;

void Solve1();
void Solve2();

int main()
{
    is >> N >> Q;
    if (Q < 20000)
        Solve1();
    else
        Solve2();



    is.close();
    os.close();
}

void Solve1()
{
    for (int l = 0; l < 3; ++l)
        for (int i = 0; i < N; ++i)
            L[l].push_back(l*N+i+1);

    for (int q = 0; q < Q; ++q)
    {
        is >> i1 >> j1 >> i2 >> j2;
        for (it = L[i1].begin(); it != L[i1].end(); ++it)
        {
            if (j1 == 0)
            {
                val = *it, L[i1].erase(it);
                break;
            }
            --j1;
        }
        if (j2 == L[i2].size())
            L[i2].push_back(val);
        else
            for (it = L[i2].begin(); it != L[i2].end(); ++it)
            {
                if (j2 == 0)
                {
                    L[i2].insert(it, val);
                    break;
                }
                --j2;
            }
    }
    for (int l = 0; l < 3; ++l)
    {
        for (const auto& x : L[l])
            os << x << ' ';
        os << '\n';
    }
};

void Solve2()
{
    for (int l = 0; l < 3; ++l)
        for (int i = 0; i < N; ++i)
            L[l].push_back(l*N+i+1);

    for (int q = 0; q < Q; ++q)
    {
        is >> i1 >> j1 >> i2 >> j2;
        for (it = L[i1].begin(); it != L[i1].end(); ++it)
        {
            if (j1 == 0)
            {
                val = *it, L[i1].erase(it);
                break;
            }
            --j1;
        }
        for (it = L[i2].begin(); it != L[i2].end(); ++it)
        {
            if (j2 == 0)
            {
                L[i1].insert(it, val);
                break;
            }
            --j2;
        }
    }
    for (int l = 0; l < 3; ++l)
    {
        for (const auto& x : L[l])
            os << x << ' ';
        os << '\n';
    }
};
