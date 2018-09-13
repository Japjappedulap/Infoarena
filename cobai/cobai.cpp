#include <fstream>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;

#define TEMP pair<int,int>

ifstream is ("cobai.in");
ofstream os ("cobai.out");

const int Di[] = {-1, 0, 1, 0}, Dj[] = {0, 1, 0, -1};

char Coords[1024], aux;
int n, m, Cels, OkCels, DIR;
bool wall[52][52], MASTER[52][52];
TEMP cobai, AC;
double Result;

queue <TEMP> Q, Qx, Qaux;

void Read();
void BFS();
bool Ok(int i, int j);
int Direction(char x);

int main()
{
    Read();
    BFS();
    Result = double(OkCels*100)/Cels;
   // os << Cels << ' ' << OkCels;
    os << setprecision(10) << (double)Result;
    is.close();
    os.close();
    return 0;
}


void Read()
{
    is >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            is >> aux;
            if (aux == '.') Cels++;
            if (aux == '+') MASTER[i][j] = true;
            if (aux == '*') cobai.first = i, cobai.second = j, Q.push(cobai), MASTER[i][j] = true;
        }
    is >> Coords;
};

void BFS()
{
    int i, j, iv, jv;
    for (int iter = 0; iter < strlen(Coords); ++iter)
    {
        memcpy(wall, MASTER, sizeof(wall));
        DIR = Direction(Coords[iter]);
        while(!Q.empty())
        {
            AC = Q.front(), Q.pop();
            i = AC.first + Di[DIR], j = AC.second + Dj[DIR];
            while (Ok(i, j) && wall[i][j] == false)
            {
                wall[i][j] = true;
                Qx.push(make_pair(i, j));
                i += Di[DIR], j += Dj[DIR];
            }
        }
        OkCels = Qx.size();
        swap(Q, Qx);
    }
};

bool Ok(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m) return false;
    return true;
};

int Direction(char x)
{
    if (x == 'N') return 0;
    if (x == 'E') return 1;
    if (x == 'S') return 2;
    if (x == 'V') return 3;
};
