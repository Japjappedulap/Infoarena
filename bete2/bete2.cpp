#include <fstream>
#include <algorithm>
using namespace std;
ifstream is ("bete2.in");
ofstream os ("bete2.out");
short n, st, dr;
int a[3001];
short cnt;
int main()
{
    is >> n;
    for (int i = 1; i <= n; i++) is >> a[i];
    sort (a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {   st = 1; dr = i;
        while (st < dr)
        {
            if (a[st] + a[dr] == a[i])
            {
                cnt++;
                st++; dr--;
                if (st > dr)
                    break;
            }
            else
            {
                if (a[st] + a[dr] > a[i]) dr--;
                if (a[st] + a[dr] < a[i]) st++;
            }}}
    os << cnt;
    is.close();
    os.close();
    return 0;
}
