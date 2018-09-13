#include <fstream>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;

ifstream is ("telecab.in");
ofstream os ("telecab.out");

const int Nmax = 100001, Kmax = 1051, Smax = 1001;
const short INF = 0x3f3f3f3f;

int N, K, S;
int H[Nmax];
int Path[Nmax];
short D[Kmax][Smax];

int Sol1;
short Sol2 = INF;

stack <pair<int,int> > Stk;
short Dist(int i, int j) {return sqrt( (H[i]-H[j])*(H[i]-H[j]) + (i-j)*(i-j) );};
short min(short a, short b)
{
    if (a > b) return b;
    return a;
}

int main()
{
    is >> N >> K >> S;
    for (int i = 1; i <= N; ++i)
        is >> H[i], Path[i] = i+1;
    for (int i = N; i > 0; --i)
    {
        while (!Stk.empty() && H[i] >= Stk.top().first)
            Stk.pop();
        if (!Stk.empty() && H[i] < Stk.top().first)
            Path[i] = Stk.top().second;
        Stk.push({H[i], i});
    }

    for (int i = 1; i < N; i = Path[i])
        Sol1 += Dist(i, Path[i]);

    memset(D, INF, sizeof(D));
    D[1][0] = 0;
    int i = 1;
    for (int nex; i < K; i = Path[i])
        for (int j = 0; j <= S; ++j)
        {
            nex = Path[i];
            if (H[i] < H[nex])  //in sus
                D[nex][j + H[nex]-H[i]] = min(D[nex][j + H[nex]-H[i]], D[i][j] + Dist(i, nex));

            else            //in jos sau in orizontala
            {
                if (H[i] == H[nex]) //orizontala
                    D[nex][j] = min(D[nex][j], D[i][j] + 1);
                else    //in jos
                    D[nex][j] = min(D[nex][j], D[i][j] + Dist(i, nex)),
                    D[nex][j + H[i] - H[nex]] = min(D[nex][j + H[i] - H[nex]], D[i][j] + 1);

            }

        }
    for (int j = 0; j <= S; ++j)
        Sol2 = min(Sol2, D[i][j]);
    os << Sol1 << '\n' << Sol2 << '\n';
    is.close();
    os.close();
}











