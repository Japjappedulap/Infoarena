#include<fstream>
#include<vector>
#include<bitset>
#include<queue>                 //scriu inghesuit pentru ca asa imi place!
#include<cmath>                 //nu te mai uita pe codu meu!
using namespace std;
#define MOD 104659
#define eps 1e-9
ifstream is("dmin.in");
ofstream os("dmin.out");
double D[1505];
int N,M,Nr[1505];
bitset<1505>B;
vector<pair<int,double>>v[1505];
struct CMP{bool operator()(int a,int b){return D[a]>D[b];}};
priority_queue<int,vector<int>,CMP>Q;
int main(){
is>>N>>M;
for(int i=2;i<=N;++i)
D[i]=(1<<30);
double cost;
for(int i=1,a,b,c;i<=M;++i){
is>>a>>b>>c;
cost=log(c);
v[a].push_back({b,cost});v[b].push_back({a,cost});
}
Q.push(1);
Nr[1]=1;
for(int i,nod;!Q.empty();){
i=Q.top();
Q.pop();
if(B[i])continue;
B[i]=1;
for(int j=0;j<v[i].size();++j){
nod=v[i][j].first;
cost=v[i][j].second;
if(fabs(D[nod]-D[i]-cost)<eps)
Nr[nod]=(Nr[nod]+Nr[i])%MOD;
else if(D[nod]>D[i]+cost){
Nr[nod]=Nr[i];
D[nod]=D[i]+cost;
Q.push(nod);
}}}
for(int i=2;i<=N;++i)os<<Nr[i]<<' ';
is.close();
os.close();
}
