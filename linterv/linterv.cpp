#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#define TX pair <int,int>
#define f first
#define s second

ifstream is ("linterv.in");
ofstream os ("linterv.out");

int n, T, S;
bool inc;
TX k;
vector <TX> v;

int main()
{
    is >> T;
    for (int t = 0; t < T; ++t)
    {
        v.clear();
        n = 0, S = 0;
        is >> n;
        for (int i = 0; i < n; ++i)
        {
            is >> k.f >> k.s;
            v.push_back(k);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i)
        {
            inc = false;
            k = v[i];
            for (; i < n && k.s >= v[i].f; ++i)
                k.s = max(v[i].s, k.s), inc = true;
            S += k.s - k.f;
            if (inc == true)
                --i;
        }
        os << S << '\n';
    }
    is.close();
    os.close();
    return 0;
}
