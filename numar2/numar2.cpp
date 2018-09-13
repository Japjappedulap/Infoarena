#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int N, M;

struct CMP
{
    CMP(const int& x) : x(x) {}
    bool operator()(const pair<int, int>& val)
    {
        return val.first == x;
    }
    const int& x;
};

set <pair<int,int> > S;
set <pair<int,int> > :: iterator it;

int main()
{
    freopen("numar2.in", "r", stdin);
    freopen("numar2.out", "w", stdout);
    scanf("%i%i", &N, &M);
    for (int i = 1, x; i <= N; ++i)
        scanf("%i", &x), S.insert({x, x});
    pair<int,int> x;
    for (int i = 1; i < M;)
    {

        it = S.begin();
        S.erase(S.begin());
        x = *it;
        it = find_if(S.begin(), S.end(), CMP(x.first+x.second));
        if (x.first != (*S.begin()).first)
            ++i;
        S.insert({x.first+x.second, x.second});
    }
    x = *S.begin();
    printf("%i", x.first);
}
