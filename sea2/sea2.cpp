#include <fstream>
#include <set>
using namespace std;

ifstream is ("sea2.in");
ofstream os ("sea2.out");

int N;
using PII = pair<int,int>;

set <PII> S;
set <PII> :: iterator it, it2, j;


int main()
{
    is >> N;
    for (int i = 1, x, y; i <= N; ++i)
    {
        is >> x >> y;
        it = S.upper_bound({x, y});
        if (it->second > y && it != S.end()){
            os << "-1\n"; continue; }
        if (!S.empty())
        {
            for (it2 = it; it2 != S.begin() && (--(j = it2))->second < y; it2 = j);
            S.erase(it2, it);
        }
        S.insert({x, y});
        os << S.size() << '\n';
    }

}
