#include <fstream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

ifstream is ("ciclu.in");
ofstream os ("ciclu.out");

const int S = 0;
int N, M;
vector <pair<int,int> > G[1003];
vector <bool> InQ;
vector <long long> D;
vector <int> Ap;
queue <int> Q;

void Read();
bool NegCyc(long long v);

int main()
{
    Read();
    long long L = 0, R = 10000000, mid;
    while (L <= R)
    {
        mid = (L+R) / 2;
        if (NegCyc(mid) == 0) L = mid+1;
        else R = mid-1;
    }
    os << fixed;
    os << setprecision(2) << double(L) / 100;
    is.close();
    os.close();
}

#define y j.first
#define w j.second

bool NegCyc(long long v)
{
    Ap = vector <int> (1003, 0);
    D = vector <long long> (1003, 0x3f3f3f3f);
    InQ = vector <bool> (1003, 0);
    while (!Q.empty()) Q.pop();
    Q.push(S);
    D[S] = 0;
    for (int x; !Q.empty();)
    {
        x = Q.front();
        Q.pop();
        InQ[x] = 0;
        for (const auto& j : G[x])
            if (D[y] > D[x] + w - v)
            {
                D[y] = D[x] + w - v;
                if (InQ[y] == 0)
                {
                    Ap[y]++;
                    if (Ap[y] == N)
                        return true;
                    Q.push(y);
                    InQ[y] = 1;
                }
            }
    }
    return false;
};

void Read()
{
    is >> N >> M;
    for (int i = 1, a, b, c; i <= M; ++i)
    {
        is >> a >> b >> c;
        G[a].push_back({b, c * 100});
    }
    for (int i = 1; i <= N; ++i)
        G[S].push_back({i, 0});
};
