#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int INF = 0x3f3f3f3f;
int c[252][252],n;
ofstream fout("muzeu.out");
queue <pair <int,int> > paz;
queue <pair <int,int> > q;
const int di[] = { -1, 0, 1, 0 },
          dj[] = { 0, 1, 0, -1 };
void input();
void Lee();
void output();
bool ok(int i, int j);
int main()
{
input();
Lee();
output();

    return 0;
}
void input()
{
    ifstream fin("muzeu.in");
    char x;
    int i=1,j=1;
    fin>>n;
    while(fin.get(x))
    {
        if(x == '.' )
         c[i][j] = INF;
        else if(x == '#')
            c[i][j] = -2;
        else if(x == 'P')
        {
            paz.push({i,j});
            c[i][j] = 0;
        }
        else
         continue;
    if(j == n)
    {
        i++;
        j=1;
    }
    else j++;

    }
fin.close();
}
bool ok(int i, int j)
{
    if(c[i][j] == -2) return false;
    else if(i < 1 || j < 1 || i > n || j > n) return false;
    return true;
}
void output()
{
    for(int i=1;i<=n;++i, fout<<'\n')
        for(int j=1;j<=n;++j)
        {
            if(c[i][j] == INF)
                fout<< -1<<" ";
            else fout<<c[i][j]<<" ";
        }
}
void Lee()
{
    int ip,jp;
    while(!paz.empty())
    {
        ip = paz.front().first;
        jp = paz.front().second;
        paz.pop();
        q.push({ip,jp});
    }

    for(int i,j,iv,jv; !q.empty();)
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(int d = 0; d < 4; ++d)
        {
            iv = i + di[d];
            jv = j + dj[d];
            if( ok(iv,jv) && c[iv][jv] > c[i][j] + 1)
            {
                c[iv][jv] = c[i][j] + 1;
                q.push({iv,jv});
            }
        }
    }
}
