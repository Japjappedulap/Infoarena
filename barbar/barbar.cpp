#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
#define DIM 1001

ifstream fin("barbar.in");
ofstream fout("barbar.out");

struct Cel{int i,j;}Start,Finish;

const int di[]={-1,0,1,0};
const int dj[]={0,1,0,-1};

int n,m,b[DIM][DIM];
char a[DIM][DIM];
bool Ex[DIM][DIM];

queue <Cel> Q;

void Read();
void BFS();
bool BFSCheck(int x);
void Solve();
bool Ok(int i,int j);

int main()
{
Read();
BFS();
Solve();
fin.close();
fout.close();
return 0;
}
void Read()
{
fin>>n>>m;
fin.get();
Cel Dragon;
for(int i=1;i<=n;++i)
for(int j=1;j<=m;++j)
{
fin>>a[i][j];
if(a[i][j]=='I')Start.i=i,Start.j=j;
if(a[i][j]=='D')Dragon.i=i,Dragon.j=j,Q.push(Dragon);
if(a[i][j]=='O')Finish.i=i,Finish.j=j;
}
};

void Solve()
{
for(int i=b[Start.i][Start.j];i>=1;i--)
if(BFSCheck(i)==true)
{
fout<<i;
return;
}
fout<<-1;
};
bool BFSCheck(int x)
{
memset(Ex,0,sizeof(Ex));
Cel Ac;
int i,j,iv,jv;
Q.push(Start);
while (!Q.empty())
{
Ac=Q.front(),Q.pop();
i=Ac.i,j=Ac.j;
for(int dir=0;dir<4;dir++)
{
iv=i+di[dir];jv=j+dj[dir];
if (b[iv][jv]>=x&&Ex[iv][jv]==false&& Ok(iv, jv))
{
Ex[iv][jv]=true;
Ac.i=iv,Ac.j=jv;
Q.push(Ac);
if(iv==Finish.i&&jv==Finish.j)
return true;
}
}
}
return false;
};
void BFS()
{
Cel Ac;
int i,j,iv,jv;
while(!Q.empty())
{
Ac=Q.front(),Q.pop();
i=Ac.i,j=Ac.j;
for(int dir=0;dir<4;dir++)
{
iv=i+di[dir],jv=j+dj[dir];
if(Ok(iv,jv)&&b[iv][jv]==0)
{
b[iv][jv]=b[i][j]+1;
Ac.i=iv,Ac.j=jv;
Q.push(Ac);
}
}
}
};
bool Ok(int i,int j)
{
if (i<1||j<1||i>n||j>m||a[i][j]=='D'||a[i][j]=='*')return false;
return true;
};
