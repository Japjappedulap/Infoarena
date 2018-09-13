#include <fstream>
#include <algorithm>
using namespace std;

ifstream is ("permut.in");
ofstream os ("permut.out");

int n, a[100001], b[100001];
long long s[100001], val;

int main()
{
    is >> n;
    for (int i = 0; i < n; ++i)
        is >> a[i];
    for (int i = 0; i < n; ++i)
        is >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    for (int i = 0; i < n; ++i)
    {
        s[i] = a[i];
        s[i] *= b[i];
    }
    for (int i = 0; i < n; ++i)
        val += s[i];
    os << val;
    is.close();
    os.close();
    return 0;
}
