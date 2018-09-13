#include <fstream>
using namespace std;

ifstream is ("ture.in");
ofstream os ("ture.out");

int N, M, K, P;    // n nr linii, m nr coloane (N < M !!)
bool Ban[16][251];
long long D[(1<<16)][2];

void Read();

int main()
{
    Read();

    int currentLine(0), previousLine(1);

    D[0][1] = 1;
    for (int j = 1; j <= M; ++j)
    {
        for (int mask = 0; mask < (1<<N); ++mask)
        {
            D[mask][currentLine] = D[mask][previousLine];
            for (int bit = 0; bit < N; ++bit)
                if (mask & (1<<bit) && Ban[bit+1][j] == 0)
                    D[mask][currentLine] += D[mask ^ (1<<bit)][previousLine];

        }
        swap(currentLine, previousLine);
    }
    long long Sol = 0;
    for (int mask = 0; mask < (1<<N); ++mask)
    {
        int cnt = 0;
        for (int bit = 0; bit < N; ++bit)
            if (mask & (1<<bit))
                ++cnt;
        if (cnt == K)
            Sol += D[mask][previousLine];
    }
    os << Sol;



    is.close();
    os.close();
}


void Read()
{
    is >> N >> M >> K >> P;
    if (N > M)
    {
        swap(N, M);
        for (int x, y; P; --P)
            is >> x >> y, Ban[y][x] = 1;
    }
    else
    {
        for (int x, y; P; --P)
            is >> x >> y, Ban[x][y] = 1;
    }
};
