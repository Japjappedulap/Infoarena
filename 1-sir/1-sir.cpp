#include<fstream>
using namespace std;
#define X 35000
#define Y 194767
ifstream i("1-sir.in");
ofstream o("1-sir.out");
int n,S,G;
int D[2][2*X],C=1,P;
int main()
{
i>>n>>G;
D[0][X]=1;
for(int i=1;i<n;++i,swap(C,P))
{
S+=i;
for(int j=X-S;j<=X+S;++j)
{
D[C][j]=D[P][j-i]+D[P][j+i];
if(D[C][j]>=Y)D[C][j]-=Y;
}
}
o<<D[P][X+G];
}
