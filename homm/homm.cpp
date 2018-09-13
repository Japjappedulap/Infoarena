#include<fstream>
#define DIM 101
using namespace std;
ifstream is ("homm.in");
ofstream os ("homm.out");
int a[DIM][DIM];
int d[DIM][DIM][DIM];
int n,m,k,i1,j1,i2,j2,s;
void Read();
int main()
{
    Read();
    for(int p=1;p<=k;++p)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(a[i][j]==0)
                    d[i][j][p]=d[i-1][j][p-1]+d[i+1][j][p-1]+d[i][j-1][p-1]+d[i][j+1][p-1];
    for(int p=0;p<=k;++p)
        s+=d[i2][j2][p];
    os<<s;
    is.close();
    os.close();
    return 0;
}


void Read()
{
    is>>n>>m>>k;
    for(int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            is>>a[i][j];
    is>>i1>>j1>>i2>>j2;
    d[i1][j1][0]=1;
};
