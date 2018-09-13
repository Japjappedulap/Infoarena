#include <fstream>
using namespace std;

ifstream is ("maxsecv.in");
ofstream os ("maxsecv.out");

int n, max1, max2, L;
char x;

int main()
{
    is >> n;
    for (int i = 0; i <= n; ++i)
    {
        x = '0';
        if (i != n) is >> x;
        if (x == '1') L++;
        else{
            if (L >= max1) max2 = max1, max1 = L;
            else if (L > max2) max2 = L;
            L = 0;
        }
    }
    os << max1 + max2;
    is.close();
    os.close();
    return 0;
}
