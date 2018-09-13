#include <fstream>
#include <vector>
using namespace std;

const int Nmax = 300001;
const int Lmax = 17;

ifstream cin ("arbvalmax.in");
ofstream cout ("arbvalmax.out");

#define PII pair<int,int>

int N, M, V[Nmax];
vector <int> Tree[Nmax];

PII BestVal[Nmax][2];
int with[Nmax], without[Nmax];

void Input();
void DFS1(int x);
void DFS2(int x);

int main()
{
    Input();
    DFS1(1);
    DFS2(1);
    for (int X, Y, sol = 0; M; --M, sol = 0)
    {
        cin >> X >> Y;
        sol = max(BestVal[Y][0].first, max(without[Y], with[X]));
        cout << sol << '\n';
    }

    cin.close();
    cout.close();
}

void Input()
{
    cin >> N >> M;
    for (int i = 2, x; i <= N; ++i)
    {
        cin >> x;
        Tree[x].push_back(i);
    }
    for (int i = 1; i <= N; ++i)
        cin >> V[i];
};

void DFS1(int x)
{
    for (const int& y : Tree[x])
        DFS1(y);
    PII Best0(0, 0), Best1(0, 0);
    for (const int& y : Tree[x])
    {
        if ( Best0.first < max(V[y], BestVal[y][0].first) )
        {
            Best1 = Best0;
            Best0 = { max(V[y], BestVal[y][0].first), y};
        }
        else
            if (Best1.first < max( V[y], BestVal[y][0].first))
                Best1 = { max(V[y], BestVal[y][0].first), y};
    }
    BestVal[x][0] = Best0;
    BestVal[x][1] = Best1;
};


void DFS2(int x)
{
    for (const int& y : Tree[x])
    {
        if (BestVal[x][0].second == y)
            without[y] = max(without[x], BestVal[x][1].first);
        else
            without[y] = max(without[x], BestVal[x][0].first);
        if (BestVal[x][0].second == y)
            with[y] = max(with[x], max(V[x], BestVal[x][1].first));
        else
            with[y] = max(with[x], max(V[x], BestVal[x][0].first));

        DFS2(y);
    }
};
