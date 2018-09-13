#include <cstdio>
#include <algorithm>
using namespace std;

#define NMAX 5005

int N, x[NMAX], poz[NMAX], last[NMAX], L[NMAX];

void read_data()
{
    scanf("%d",&N);
    for(int i=0; i<N; ++i)
        scanf("%d",&x[i]);
}

inline bool cmp(int a, int b)
{
    return x[a]<x[b];
}

void init()
{
    for(int i=0; i<N; ++i)
        poz[i]=i;
    sort(poz,poz+N,cmp);
    int ind=0, prec;
    prec=x[poz[0]];
    x[poz[0]]=ind;
    for(int i=1; i<N; i++)
    {
        if(x[poz[i]]!=prec)
            ind++;
        prec=x[poz[i]];
        x[poz[i]]=ind;
    }
}

void solve()
{
    for(int i=0; i<N; i++)
        last[i]=-1;
    for(int i=0; i<N; i++)
    {
        if(x[i]==0)
            L[i]=1;
        else
            if(last[x[i]-1]!=-1 && L[last[x[i]-1]]!=-1)
                L[i]=L[last[x[i]-1]]+(i-last[x[i]-1]);
            else
                L[i]=-1;
        last[x[i]]=i;
    }
}

void write_sol()
{
    int max=-1, sol=-1;
    for(int i=0; i<N; i++)
        if(max<x[i])
        {
            max=x[i];
            sol=L[i];
        }
        else
            if(max==x[i])
                if(sol==-1 || sol>L[i])
                    sol=L[i];
    printf("%d\n",sol);
}


int main()
{
    freopen("secv.in","r",stdin);
    freopen("secv.out","w",stdout);
    read_data();
    init();
    solve();
    write_sol();
    return 0;
}
