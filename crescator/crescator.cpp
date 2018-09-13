#include <fstream>
using namespace std;

ifstream is ("crescator.in");
ofstream os ("crescator.out");

int n, Lmax, s;
int v[100001], l[100001];

int main()
{
    is >> n;
    for (int i = 1; i <= n; ++i)
    {
        l[i] = 1;
        is >> v[i];
        if (v[i] > v[i-1])
            l[i] = l[i-1]+1;
        else
            l[i] = 1;
        s += l[i];
        if (Lmax < l[i])
            Lmax = l[i];
    }
    os << s << ' ' << Lmax;
    is.close();
    os.close();
    return 0;
}
