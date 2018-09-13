#include <fstream>
using namespace std;
#define TX pair<int,int>
#define f first
#define s second
ifstream is ("reactii.in");
ofstream os ("reactii.out");

int n, m, k;
TX x, v[15000];

bool Unite();

int main()
{
    is >> n >> m;
    for (int t = 0; t < m; ++t)
    {
        k = 0;
        for (int i = 0; i < n; ++i)
        {
            is >> x.f;
            x.s = x.f;
            ++k;
            v[k].f = x.f, v[k].s = x.s;
            for ( ; k > 1 && Unite() == true; );
        }
        if (k == 1)
            os << 1 << '\n';
        else
            os << 0 << '\n';
    }



    is.close();
    os.close();
    return 0;
}

bool Unite()
{
    if (v[k-1].s == v[k].f + 1)
    {
        v[k-1].s = v[k].s;
        v[k].f = 0; v[k].s = 0;
        k--;
        return true;
    }
    else if (v[k-1].f == v[k].s - 1)
    {
        v[k-1].f = v[k].f;
        v[k].f = 0; v[k].s = 0;
        k--;
        return true;
    }
    return false;
};
