#include <fstream>
#include <deque>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
ifstream is ("dir.in");
ofstream os ("dir.out");
char S[1620];
int n;
bool lo;
string V, sol;
deque <string> Dq;
deque <string> Daux;
vector <string> dv;
int main()
{
is>>S;
n=strlen(S);
for(int i=0;i<n;++i)
{
if(S[i]==',')continue;
lo=false;
V="";
if(isupper(S[i]))
{
while(isupper(S[i])||isdigit(S[i]))
{
V+=S[i];
++i;
}
}
if(islower(S[i]))
{
while(islower(S[i])||isdigit(S[i]))
{
V+=S[i];
++i;
}
lo=true;
}
if(lo==true)
{
Dq.push_back(V);
Daux=Dq;
sol="";
while(Daux.size()!=1)
{sol+=Daux.front();sol+=(char)92;
Daux.pop_front();}
sol+=Daux.front();
dv.push_back(sol);
Dq.pop_back();
}
if (S[i]=='(')Dq.push_back(V);
if (S[i]==')')Dq.pop_back();
}
os<<dv.size()<<'\n';
sort(dv.begin(),dv.end());
for(int i=0; i<dv.size();++i) os<<dv[i]<<'\n';
is.close();os.close();
return 0;
}
