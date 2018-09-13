// :: BinarySearch ::
#include <fstream>
using namespace std;

ifstream is ("transport.in");
ofstream os ("transport.out");

int a[16001], n, k, cnt, st, dr = 1000000000, s, m;

void Read();
void Solve();

int main()
{
    Read();
    Solve();
    is.close();
    os.close();
    return 0;
}

void Read()
{
    is >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        is >> a[i];
        if (a[i] > st) st = a[i];
    }
};

void Solve()
{
    while(st < dr)
    {
        s = 0, cnt = 1;
        m = (dr + st)/2;
        for (int i = 1; i <= n; ++i)
            if (s + a[i] <= m)
                s += a[i];
            else
                s = a[i], cnt++;
        if (cnt > k)    st = m+1;
        else    dr = m;
    }
    os << st;
};
