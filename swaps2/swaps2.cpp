#include <fstream>
#include <vector>
using namespace std;

ifstream is ("swaps2.in");
ofstream os ("swaps2.out");

char s[1001];
int n;

vector <pair <int, int> > v;

int main()
{
    is >> n;
    is >> s;
    int i = 0, j = n-1;
    while (i < j)
    {
        while (i < j && s[i] != '1')
            i++;
        while (i < j && s[j] != '0')
            j--;
        if (i < j)
        {
            v.push_back(make_pair(i, j));
            i++, j--;
        }
    }
    os << v.size() << '\n';
    for (int x = 0; x < v.size(); x++)
        os << v[x].first+1 << ' ' << v[x].second+1 << '\n';

    is.close();
    os.close();
    return 0;
}
