#include <fstream>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

#define MK(i, j) make_pair(i, j)

const int Di[] = {-1, 0, 1, 0}, Dj[] = {0, 1, 0, -1};

int n, m, k, area, z[301][301], result;
bool block[90001], b[301][301];
char c[301][301];

queue < pair < int , int > > Q;
queue < int > Qx;
vector <set < int > > V;
vector <int> VS;

void Read();
void Zone();
void RemoveArea();
bool Ok(int i, int j);

int main()
{
    Read();
    Zone();
    RemoveArea();
    return 0;
}

void RemoveArea()
{
    set < int > :: iterator itx;
    int x, y;
    while (!Qx.empty()){
        x = Qx.front(), Qx.pop();
        for (set < int > :: iterator it = V[x].begin(); it != V[x].end(); ++it){
            y = (*it);
            itx = V[y].find(x);
            if (itx != V[y].end()){
                V[y].erase(itx);
                if (V[y].size() < k) Qx.push(y);
            }
        }
        V[x].clear();
    }
    ofstream os ("zone2.out");
    for (int i = 0; i < VS.size(); ++i)
        if (V[i].size() != 0)
            result += VS[i];
    os << result;
    os.close();
};


void Zone()
{
    int x = 1, ii, jj, iv, jv;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        if (b[i][j] == 0){
            z[i][j] = x;
            b[i][j] = 1;
            Q.push(MK(i, j));
            while (!Q.empty()){
                ii = Q.front().first, jj = Q.front().second;
                Q.pop();
                for (int dir = 0; dir < 4; ++dir){
                    iv = ii + Di[dir];
                    jv = jj + Dj[dir];
                    if (Ok(iv, jv) && c[iv][jv] == c[ii][jj] && b[iv][jv] == 0)
                    {
                        z[iv][jv] = x;
                        b[iv][jv] = 1;
                        Q.push(MK(iv, jv));
                    }
                }
            }
            x++;
        }
    V.resize(x);
    VS.resize(x);
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (b[i][j] == 0){
                area = 0;
                x = 0;
                b[i][j] = 1;
                Q.push(MK(i, j));
                while (!Q.empty()){
                    ii = Q.front().first, jj = Q.front().second;
                    Q.pop();
                    area++;
                    for (int dir = 0; dir < 4; ++dir){
                        iv = ii + Di[dir];
                        jv = jj + Dj[dir];
                        if (Ok(iv, jv) && z[iv][jv] == z[ii][jj] && b[iv][jv] == 0){
                            b[iv][jv] = 1;
                            Q.push(MK(iv, jv));
                        }
                        if (Ok(iv, jv) && z[iv][jv] != z[ii][jj] && block[z[iv][jv]] == 0){
                            block[z[iv][jv]] = 1;
                            V[z[ii][jj]].insert(z[iv][jv]);
                            x++;
                        }
                    }
                }
                VS[z[i][j]] = area;
                if (x < k) Qx.push(z[i][j]);
                memset(block, 0, sizeof(block));
            }
};

void Read()
{
    ifstream is ("zone2.in");
    is >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            is >> c[i][j];
    is.close();
};

bool Ok(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m) return false;
    return true;
};
