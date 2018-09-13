#include <fstream>
using namespace std;
#define l long long
ifstream is ("munte.in");
ofstream os ("munte.out");
l N,L,K,D[52][102][52][2];
l v[52];
int main(){
is>>N>>L>>K;
v[0]=-1;
for(int k=1;k<=K;++k)is>>v[k];
D[0][1][0][0]=1;
for(int j=2;j<=L+1;++j)
for(int i=1;i<=N;++i)
for(int k=0;k<=K;++k)
for(int t=0;t<2;++t)
if (t==1)
if (v[k]==i)
if(i==N)
D[i][j][k][t]=D[i-1][j-1][k-1][1]+D[i-1][j-1][k-1][0]+D[i][j-1][k-1][1];
else
D[i][j][k][t]=D[i-1][j-1][k-1][1]+D[i+1][j-1][k-1][1]+D[i][j-1][k-1][1];
else
if(i==N)
D[i][j][k][t]=D[i-1][j-1][k][1]+D[i-1][j-1][k][0]+D[i][j-1][k][1];
else
D[i][j][k][t]=D[i-1][j-1][k][1]+D[i+1][j-1][k][1]+D[i][j-1][k][1];
else
if (i!=N)
if(v[k]==i)
D[i][j][k][t]=D[i-1][j-1][k-1][0]+D[i][j-1][k-1][0]+D[i+1][j-1][k-1][0];
else
D[i][j][k][t]=D[i-1][j-1][k][0]+D[i][j-1][k][0]+D[i+1][j-1][k][0];
os<<D[1][L][K][1];
is.close();
os.close();
}
