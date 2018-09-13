#include <algorithm>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

ifstream is ("drumuri5.in");
ofstream os ("drumuri5.out");

const int Nmax = 150001;

int N, M;

int IN[Nmax], OUT[Nmax];    //grad interior, exterior
int D[Nmax];                //distanta maxima pe care o pot parcurge din nodul i
int belong[Nmax];           //nodul i apartine componentei belong[i]

int SCC;
bool GoodSCC[Nmax];

vector <int> G[Nmax], DAG[Nmax], DAGT[Nmax], Border[Nmax];

void Read();
void Write();
void CreateDAG();
inline void Tarjan(int node);
void Solve();

int main()
{
    Read();
    CreateDAG();
    Solve();

    is.close();
    os.close();
}

void Solve()
{
    queue <int> Q;
    for (int i = 1; i <= SCC; ++i)
        if (OUT[i] == 0)
            Q.push(i);
    for (int i; !Q.empty(); Q.pop())
    {
        i = Q.front();
        for (const int& j : DAGT[i])
        {
            OUT[j]--;
            if (OUT[j] == 0)
                Q.push(j);
            D[j] = max(D[j], D[i]+1);
        }
    }
    int MD = -1;
    int Num = 0;
    for (int i = 1; i <= SCC; ++i)
        if (IN[i] == 0)
        {
            ++Num;
            Border[D[i]].push_back(i);
            MD = max(MD, D[i]);
        }

    while (MD >= 0)
    {
        if (Num == 1)
            GoodSCC[Border[MD][0]] = 1;
        for (const int& i : Border[MD])
            for (const int& j : DAG[i])
            {
                --IN[j];
                if (IN[j] == 0)
                {
                    Border[D[j]].push_back(j);
                    ++Num;
                }
            }
        Num -= Border[MD].size();
        Border[MD].clear();
        while(MD >= 0 && Border[MD].size() == 0)
            --MD;
    }
    vector <int> VIP;
    for(int i = 1 ; i <= N ; ++ i)
        if(GoodSCC[belong[i]] == 1)
            VIP.push_back(i);
    os << VIP.size() << '\n';
    for (const int& i : VIP)
        os << i << ' ';
};

void Read()
{
    is >> N >> M;
    int ma, mb;
    for (int i = 1; i <= M; ++i)
    {
        is >> ma >> mb;
        G[ma].push_back(mb);
    }
};

int L[Nmax], index[Nmax], idx;
bool InStk[Nmax];
stack <int> Stk;

void CreateDAG()
{
    for (int i = 1; i <= N; ++i)
        if (index[i] == 0)
            Tarjan(i);
    for (int i = 1; i <= N; ++i)
        for (const int& j : G[i])
            if (belong[i] != belong[j])
            {
                DAG[belong[i]].push_back(belong[j]);
                DAGT[belong[j]].push_back(belong[i]);
            }
    for (int i = 1; i <= SCC; ++i)
    {
        sort(DAG[i].begin(), DAG[i].end());
        DAG[i].erase(unique(DAG[i].begin(), DAG[i].end()), DAG[i].end());
        sort(DAGT[i].begin(), DAGT[i].end());
        DAGT[i].erase(unique(DAGT[i].begin(), DAGT[i].end()), DAGT[i].end());
    }
    for (int i = 1; i <= SCC; ++i)
    {
        OUT[i] = DAG[i].size();
        IN[i] = DAGT[i].size();
    }
};

inline void Tarjan(int node)
{
    L[node] = index[node] = ++idx;
    Stk.push(node), InStk[node] = 1;
    for (const int& next : G[node])
        if (index[next] == 0)
        {
            Tarjan(next);
            L[node] = min(L[node], L[next]);
        }
        else
            if (InStk[next] == 1)
                L[node] = min(L[node], L[next]);
    if (L[node] == index[node])
    {
        int aux = Stk.top();
        do{
            aux = Stk.top();
            belong[aux] = SCC+1;
            Stk.pop();
            InStk[aux] = 0;
        } while (aux != node);
        SCC++;
    }
};










