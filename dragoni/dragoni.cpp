#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

#define tip long long
#define mp make_pair
#define IN first
#define DR second
using namespace std;

ifstream f("dragoni.in");
ofstream g("dragoni.out");

int t,n,m,P[1005][1005],D[1005],Q1[1005],q1[1005],b,LH,T[1005][1005];
vector<int> V[1005];
vector<pair<int,int> > v[1005];
pair<int,int> H[1000005];

void cerinta1(),cerinta2(),Hd(int),Hu(int);
int main()
{
    f>>t>>n>>m;
    for(int i=1;i<=n;i++)f>>D[i];
    if(t==1)cerinta1();else cerinta2();
    return 0;
}
void cerinta1()
{
    int x,y,d,sol;
    for(;m;m--){f>>x>>y>>d;if(d<=D[1]){V[x].push_back(y);V[y].push_back(x);}}
    Q1[1]=1;q1[1]=1;t=b=1;
    for(;b<=t;){x=Q1[b++];for(vector<int>::iterator it=V[x].begin();it!=V[x].end();it++)if(!q1[*it]){Q1[++t]=*it;q1[*it]=1;}}
    sol=D[1];for(int i=1;i<=n;i++)if(q1[i])sol=max(sol,D[i]);g<<sol;
}
void cerinta2()
{
    int x,y,d,ins,dra,oo=2000000000;
    pair<int,int> Per;
    for(int i=1;i<=m;i++){f>>x>>y>>d;v[x].push_back(make_pair(d,y));v[y].push_back(make_pair(d,x));}
    for(ins=1;ins<=n;ins++)sort(v[ins].begin(),v[ins].end());
    for(ins=1;ins<=n;ins++)for(dra=1;dra<=n;dra++)
        {LH++;H[LH].IN=ins;H[LH].DR=dra;P[ins][dra]=LH;T[ins][dra]=oo;}
    T[1][1]=0;
    for(;;)
    {
        Per=H[1];
        if(Per.IN==n){g<<T[Per.IN][Per.DR];return;}
        P[Per.IN][Per.DR]=n+1;
        H[1]=H[LH--];P[H[1].IN][H[1].DR]=1;Hd(1);
        for(int i=0; i<v[Per.IN].size(); ++i)
        {
            pair<int, int> it = v[Per.IN][i];
            if(D[Per.DR]<it.first)break;
            ins=it.second;dra=D[Per.DR]>D[ins]?Per.DR:ins;
            if(P[ins][dra]>LH||(T[ins][dra]<=T[Per.IN][Per.DR]+it.first))continue;
            T[ins][dra]=T[Per.IN][Per.DR]+it.first;
            Hu(P[ins][dra]);
        }
    }
}
void Hu(int son)
{
    int dad=son/2;
    if(!dad)return;
    if(T[H[dad].IN][H[dad].DR]>T[H[son].IN][H[son].DR])
    {pair<int,int>PerAux=H[son];H[son]=H[dad];H[dad]=PerAux;P[H[son].IN][H[son].DR]=son;P[H[dad].IN][H[dad].DR]=dad;Hu(dad);}
}
void Hd(int dad)
{
    int son=2*dad;
    if(son>LH)return;
    if(son<LH)if(T[H[son].IN][H[son].DR]>T[H[son+1].IN][H[son+1].DR])son++;
    if(T[H[dad].IN][H[dad].DR]>T[H[son].IN][H[son].DR])
    {pair<int,int>PerAux=H[son];H[son]=H[dad];H[dad]=PerAux;P[H[son].IN][H[son].DR]=son;P[H[dad].IN][H[dad].DR]=dad;Hd(son);}
}
