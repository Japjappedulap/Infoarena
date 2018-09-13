#include <cstring>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream is("ubuntzei.in");
ofstream os("ubuntzei.out");
const int Nmax=2001,INF=0x3f3f3f3f;
int N,M,K,U[17],C[17][17],D[1<<17][17],P[Nmax];
vector <pair<int,int> > Graph[Nmax];
bool B[Nmax];
priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
void Read();
void Dijkstra(int);
void DP();
int main(){
Read();
for(int i=0;i<=K+1;++i){
Dijkstra(U[i]);
for(int j=0;j<=K+1;++j)
if (P[U[j]] == 0)C[i][j]=INF;
else C[i][j]=P[U[j]];}
DP();
}
void DP()
{memset(D, INF, sizeof(D));
D[1][0]=0;
K+=2;
for(int m=2;m<(1<<K);++m)
for(int i=0;(1<<i)<=m;++i)
if(m&(1<<i))
for(int j=0;(1<<j)<=m;++j)
if(m&(1<<j))
D[m][i]=min(D[m][i],D[m-(1<<i)][j]+C[j][i]);
os<<D[(1<<K)-1][K-1];
};
void Dijkstra(int start)
{memset(P,INF,sizeof(P));
memset(B,0,sizeof(B));
P[start]=0;
Q.push({0,start});
for(int x;!Q.empty();){
x=Q.top().second;
B[x]=1;
for(const auto&Y:Graph[x])
if(P[Y.first]>P[x]+Y.second)P[Y.first]=P[x]+Y.second,Q.push({P[Y.first],Y.first});
while(!Q.empty()&&B[Q.top().second]==1)Q.pop();
}};
void Read()
{
is>>N>>M;
is>>K;
for(int i=1;i<=K;++i)
is>>U[i];
U[0]=1;
U[K+1]=N;
for(int a,b,c;M;--M)
{
is>>a>>b>>c;
Graph[a].push_back({b,c});
Graph[b].push_back({a,c});
}};
