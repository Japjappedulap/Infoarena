#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

const int Nmax = 1000001;

ifstream is ("arbore3.in");
ofstream os ("arbore3.out");

int N, S, V[Nmax], Sol;
vector <int> Tree[Nmax];

unordered_map<int, int> Hash;

void DFS(int x, int Sum);

int main()
{
    is >> N >> S;
    for (int i = 1, t; i <= N; ++i)
    {
        is >> t >> V[i];
        Tree[t].push_back(i);
    }
    Hash[0] = 1;
    DFS(1, V[1]);
    os << Sol;
    is.close();
    os.close();
}

void DFS(int x, int Sum)
{
    if (Hash.find(Sum-S) != Hash.end())
        Sol += Hash[Sum-S];
    ++Hash[Sum];
    for (const int& y : Tree[x])
        DFS(y, Sum+V[y]);

    --Hash[Sum];
    if (Hash[Sum] == 0)
        Hash.erase(Sum);
};






















