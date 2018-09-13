#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int Nmax = 100001;

ifstream is ("dominouri.in");
ofstream os ("dominouri.out");

int N;
int F[Nmax], Best[Nmax];
vector <int> Tree[Nmax];

priority_queue <int, vector<int>, greater<int> > Q;

void Input();
void DFS(int x);

int main()
{
    Input();

    DFS(1);

    os << Best[1];

    is.close();
    os.close();
}

void Input()
{
    is >> N;
    for (int i = 1, k; i <= N; ++i)
    {
        is >> k;
        for (int j = 1, x; j <= k; ++j)
        {
            is >> x;
            Tree[i].push_back(x);
        }
    }
    for (int i = 1; i <= N; ++i)
        is >> F[i];
};

void DFS(int x)
{
    if (Tree[x].empty() == 1)
    {
        Best[x] = 1;
        return;
    }
    for (const int& y : Tree[x])
        DFS(y);

    while (!Q.empty()) Q.pop();

    for (const int& y : Tree[x])
        Q.push(Best[y]);

    for (; F[x]; --F[x])
    {
        Best[x] += Q.top();
        Q.pop();
    }
};














