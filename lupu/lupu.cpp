#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

#define PII pair<int,int>
#define x first
#define y second

ifstream is ("lupu.in");
ofstream os ("lupu.out");

int N, D, L, Pp;
unsigned long long sol;
PII v[100005];

priority_queue <int> Q;

int main()
{
    is >> N >> D >> L;
    for (int i = 1; i <= N; ++i)
        is >> v[i].x >> v[i].y;
    sort(v+1, v+N+1);
    for (int i = 1; i <= N && v[i].x <= D; ++Pp)
    {
        while (i <= N && v[i].x <= Pp*L)
            Q.push(v[i].y), ++i;
        if (!Q.empty())
            sol += Q.top(), Q.pop();
    }
    os << sol;
    is.close();
    os.close();
}
