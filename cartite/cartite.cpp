#include <fstream>
#include <queue>
#include <vector>
using namespace std;

#define x first
#define y second
#define PII pair<int,int>

ifstream is ("cartite.in");
ofstream os ("cartite.out");

const int Di[] = {-1, 0, 1, 0}, Dj[] = {0, 1, 0, -1};

PII Cartita;
int N, Task, M, NrFox, Gropi, Root;
int D[204][204];
bool B[204][204], Key[204][204], viz[40004];
vector <int> G[40004], Circuit;
PII E[10400];


int Encode(int i, int j);
PII Decode(int v);

void Read();
void Task1();
void Task2();
inline void DFS(int i);
bool Ok(int i, int j);

int main()
{
    Read();
    if (Task == 1)
        Task1();
    else
        Task2();

    is.close();
    os.close();
}

void Task1()
{
    queue<PII> Q;
    Q.push(Cartita);

    D[Cartita.x][Cartita.y] = 1;
    if (Key[Cartita.x][Cartita.y] == 1)
    {
        os << Cartita.x << ' ' << Cartita.y << ' ' << 0;
        return;
    }
    for (int i, j, iv, jv; !Q.empty(); Q.pop())
    {
        i = Q.front().x;
        j = Q.front().y;
        for (int d = 0; d < 4; ++d)
        {
            iv = i + Di[d];
            jv = j + Dj[d];
            if (Ok(iv, jv) && B[iv][jv] == 0 && Key[iv][jv] == 0 && D[iv][jv] == 0)
            {
                D[iv][jv] = D[i][j]+1;
                Q.push({iv, jv});
            }
            if (Ok(iv, jv) && B[iv][jv] == 0 && Key[iv][jv] == 1)
            {
                os << iv << ' ' << jv << ' ' << D[i][j] << '\n';
                return;
            }
        }
    }
};

void Task2()
{
    DFS(Root);
    for (int i = 0; i < Circuit.size(); ++i)
        os << Decode(Circuit[i]).x << ' ' << Decode(Circuit[i]).y << '\n';
};

#define e G[i].back()

inline void DFS(int i)
{
    while (!G[i].empty())
        if (!viz[e])
            viz[e] = 1, DFS(E[e].x + E[e].y - i);
        else
            G[i].pop_back();
    Circuit.push_back(i);
};

void Read()
{
    is >> Task;
    is >> N >> M;
    is >> Cartita.x >> Cartita.y;
    is >> NrFox;
    for (int k = 1, i, j, r; k <= NrFox; ++k)
    {
        is >> i >> j >> r;
        B[i][j] = 1;
        if (r > 0)
            for (int d = 0; d < 4; ++d)
                if (Ok(i+Di[d], j+Dj[d]))
                    B[i+Di[d]][j+Dj[d]] = 1;
        if (r > 1)
        {
            for (int d = 0; d < 4; ++d)
                if (Ok(i+2*Di[d], j+2*Dj[d]))
                    B[i+2*Di[d]][j+2*Dj[d]] = 1;
            B[i-1][j-1] = B[i-1][j+1] = B[i+1][j-1] = B[i+1][j+1] = 1;
        }
    }
    is >> Gropi;
    Root = 900000;
    for (int k = 1, i, j, i2, j2; k <= Gropi; ++k)
    {
        is >> i >> j >> i2 >> j2;

        Key[i][j] = Key[i2][j2] = 1;
        if (B[i][j] == 0 && Root == 900000)
            Root = Encode(i, j);
        G[Encode(i, j)].push_back(k);
        G[Encode(i2, j2)].push_back(k);
        E[k] = {Encode(i, j), Encode(i2, j2)};
    }
};

int Encode(int i, int j)
{
    return (i-1)*M+j;
};

PII Decode(int v)
{
    int i, j;
    if (v % M == 0)
        i = (v / M), j = M;
    else
        j = v % M, i = (v / M)+1;
    return {i, j};
};

bool Ok(int i, int j)
{
    if (i < 1 || i > N || j < 1 || j > M) return false;
    return true;
};
