#include <fstream>
using namespace std;

ifstream is ("fact.in");
ofstream os ("fact.out");

int p;

int OK(int x);
int BS(int st, int dr);

int main()
{
    is >> p;
    os << BS(1, 500000000);

    is.close();
    os.close();
    return 0;
}


int OK(int x)
{
    int zeros = 0;
    for (int i = 5; i <= x; i *= 5)
        zeros += (x / i);
    return zeros;
};

int BS(int st, int dr)
{
    int mid, k;
    while (st <= dr)
    {
        mid = st + ((dr-st) / 2);
        k = OK(mid);
        if (k == p && st == dr)
            return mid;
        if (k == p)
            dr = mid;
        else
        {
            if (k < p)
                st = mid+1;
            else
                dr = mid-1;
        }
    }
    return -1;
};
