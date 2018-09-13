#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is ("inv.in");
ofstream os ("inv.out");

int x, N, aib[100005];
long long sol;
vector <pair <int,int> > v;
void Update(int pos);
int Sum(int pos);

int main()
{
    is >> N;
    for (int i = 1, x; i <= N; ++i)
        is >> x, v.push_back({x, i});
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    for (int i = 0, x; i < N; ++i)
    {
        x = v[i].second;
        sol += 1LL * Sum(x);
        Update(x);
    }
    os << sol % 9917;
    is.close();
    os.close();
}

void Update(int pos)
{
    for (int i = pos; i <= N; i += (i & (-i)))
        ++aib[i];
};

int Sum(int pos)
{
    int r = 0;
    for (int i = pos; i > 0; i -= (i & (-i)))
        r += aib[i];
    return r;
};
