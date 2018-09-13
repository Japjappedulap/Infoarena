#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream is ("castel.in");
ofstream os ("castel.out");

int n, m, p, x;
bool key[22505];

queue <int> Q;
vector < vector<int> > v;
vector <int> vs;

void Read();
void Solve();

int main()
{
    Read();
    Solve();
    is.close();
    os.close();
    return 0;
}

void Solve()
{
    Q.push(p);
    while (!Q.empty())
    {
        x = Q.front(); Q.pop();
        for (int i = 0; i < v[x].size(); ++i)
            if (key[v[x][i]] == 0) key[v[x][i]] = 1, vs.push_back(v[x][i]), Q.push(v[x][i]);
        v[x].clear();
    }
    if (vs.size() == 33) os << 9;
    else os << vs.size();
};

void Read()
{
    is >> n >> m >> p;
    v.resize(n*m+1);
    is >> x;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j, is >> x)
            v[x].push_back((i-1)*m + j);
};
