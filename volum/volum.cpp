#include <fstream>
#include <queue>
using namespace std;

ifstream is ("volum.in");
ofstream os ("volum.out");

#define TEMP pair<int,pair<int,int>>

const int Di[] = {-1, 0, 1, 0};
const int Dj[] = {0, 1, 0, -1};

int N, M;
long long sol;
int v[777][777];
bool b[777][777];

priority_queue<TEMP, vector <TEMP>, greater<TEMP> > Q;

int main()
{
    is >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            is >> v[i][j];
            if (i == 1 || i == N || j == 1 || j == M)
                Q.push({v[i][j], {i, j}}), b[i][j] = 1;
        }
    for (int i, j, iv, jv, h, hv; !Q.empty();)
    {
        h = Q.top().first;
        i = Q.top().second.first;
        j = Q.top().second.second;
        Q.pop();
        for (int d = 0; d < 4; ++d)
        {
            hv = h;
            iv = i + Di[d];
            jv = j + Dj[d];
            if (iv < 1 || jv < 1 || iv > N || jv > M || b[iv][jv] == 1) continue;
            b[iv][jv] = 1;
            if (hv < v[iv][jv])
                hv = v[iv][jv];
            sol += (hv-v[iv][jv]);
            Q.push({hv, {iv, jv}});
        }
    }
    os << sol;
    is.close();
    os.close();
}




