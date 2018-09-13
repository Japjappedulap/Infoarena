#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is ("granita.in");
ofstream os ("granita.out");

vector < pair <int, int> > v;
int n, a, b, cnt, x;

void Read();

int main()
{
    Read();
    sort(v.begin(), v.end());
    for (int i = 1; i < n; ++i)
    {
        if (v[x].second > v[i].second)
            cnt++;
        else
            x = i;
    }
    os << cnt;
    is.close();
    os.close();
    return 0;
}

void Read()
{
    is >> n;
    for (int i = 0; i < n; ++i)
    {
        is >> a >> b;
        v.push_back(make_pair(a, b));
    }
};
