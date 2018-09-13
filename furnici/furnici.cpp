#include <fstream>
using namespace std;
ifstream is ("furnici.in");ofstream os ("furnici.out");
int l,n,a,r,m;
char b;
int main()
{
    is>>l>>n;
    for (int i=0;i<n;i++)
    {   is>>a>>b;
        if(b=='D')r=l-a;
        if(b=='S')r=a;
        if(r>m)m=r;
    }
    os<<m;
    return 0;
}
