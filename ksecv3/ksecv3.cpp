#include<fstream>
using namespace std;
int n,k,x;
long long st,s;
void Read();
void Solve();
int main()
{
Read();
Solve();
return 0;
}
void Read()
{
ifstream is("ksecv3.in");
is>>n>>k;
for(int i=0;i<n;++i)
{
is>>x;
st+=x;
}
is.close();
}
void Solve()
{
ofstream os("ksecv3.out");
ifstream is("ksecv3.in");
is>>n>>k;
s=0;
for(int i=0;i<n;++i)
{
is>>x;
s+=x;
if(s==st/k)
{
s=0;
os<<i+1<<' ';
continue;
}
if(s>st/k)
{
os.close();
ofstream os("ksecv3.out");
os<<"-1";
is.close();
return;
}
}
is.close();
};
