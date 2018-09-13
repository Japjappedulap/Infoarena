#include <fstream>
using namespace std;

int n, k, x, s[50001], MIN = 2000000000, MAX = -2000000000, lf, rg;

void Read();
void Write();

int main()
{
    Read();
    Write();
    return 0;
}

void Write()
{
    for (int i = k; i <= n; ++i)
    {
        if (MIN > s[i-k])
            MIN = s[i-k], x = i-k;
        if (s[i]-MIN > MAX)
            MAX = s[i]-MIN, lf = x+1, rg = i;
    }
    ofstream os ("secv2.out");
    os << lf << ' ' << rg << ' ' << MAX;
    os.close();
};

void Read()
{
    ifstream is ("secv2.in");

    is >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        is >> x;
        s[i] = s[i-1]+x;
    }
    is.close();
};
