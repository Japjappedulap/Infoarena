#include <fstream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

ifstream is("trilant.in");
ofstream os("trilant.out");

#define DIM 100001
#define ll long long
#define MAX 2*922337203685477580

int  N, M, A, B, C, x, y, z;
int  S[3];
vector <pair<int ,unsigned long long > > G[DIM];
priority_queue < pair<unsigned long long, int> , vector<pair< unsigned long long ,int > > , greater< pair<unsigned long long , int>  > > P;
unsigned long long CD[3][DIM];
int  TT[3][DIM];
int  Ap[DIM], f, ROOT, PP;
unsigned long long Solmin;
vector <int > V[3];

void Input();
void Dijkstra(int x);
void Way2(int x, int root);

int main()
{
    Solmin = MAX;
    Input();
    unsigned long long maxm = MAX;
    for ( int i = 0; i <= 2; ++i )
        Dijkstra(i);

    A = S[0]; B = S[1]; C = S[2];

    for ( int i = 1; i <= N; ++i )
    {
        if ( CD[0][i] != maxm && CD[1][i] != maxm && CD[2][i] != maxm)
        {
            if ( Solmin > CD[0][i]+CD[1][i]+CD[2][i])
            {
                Solmin = CD[0][i]+CD[1][i]+CD[2][i];
                ROOT = i;
            }
        }
    }
    Way2(ROOT,0);
    Way2(ROOT,1);
    Way2(ROOT,2);
    os << Solmin << '\n';
    for ( ll i = 0; i <= 2; ++i )
    {
       os << V[i].size() << " ";
        for ( ll j = V[i].size()-1; j >= 0; --j )
            os << V[i][j] << " ";
        os << '\n';
    }


}

void Input()
{

    is >> N >> M;
    for ( int i = 0; i <= 2; ++i )
       is >> S[i];

    for ( int i = 1; i <= M; ++i )
    {
        is >> x >> y >> z;
        G[x].push_back(make_pair(y,z));
         G[y].push_back(make_pair(x,z));
    }

    for ( int i = 0; i <= 2; ++i )
    {
        for ( int j = 0; j <= N; ++j )
            CD[i][j] = MAX;
    }

}

void Dijkstra(int x)
{
    P.push(make_pair(0,S[x]));
    CD[x][S[x]] = 0;
    unsigned long long  node, cost;
    while ( !P.empty() )
    {
        node = P.top().second;
        cost = P.top().first;
        P.pop();
        for ( const auto& v : G[node] )
        {
            if ( CD[x][v.first] > cost + v.second )
            {
                CD[x][v.first] = cost + v.second;
                TT[x][v.first] = node;
                P.push(make_pair(cost+v.second,v.first));
            }
        }
    }
}



void Way2(int x, int root)
{
    if ( x == S[root] )
    {
        V[root].push_back(x);
        return;
    }
    Way2(TT[root][x],root);
    V[root].push_back(x);
}
