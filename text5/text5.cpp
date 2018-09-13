
#include <cstring>
#include <fstream>
using namespace std;

const int Nmax = 1000005;
const int INF = 0x3f3f3f3f;

int N;
char Txt[Nmax];

ifstream is ("text5.in");
ofstream os ("text5.out");

int U2[10][10][2];
int U3[10][10][10][3];      //inceputul ultimei aparitii a cuvantului [i][j][k]

int D[Nmax][2];
int MemRec[Nmax][2];

int Next[Nmax][2];

int GetJump(int i, int step);

int main()
{
    is >> N;
    is >> (Txt+1);


    U2[Txt[N-1]-'0'][Txt[N]-'0'][(N-1)%2] = N;
    U2[Txt[N-2]-'0'][Txt[N-1]-'0'][(N-2)%2] = N-1;
    U3[Txt[N-2]-'0'][Txt[N-1]-'0'][Txt[N]-'0'][(N-2)%3] = N;

    Next[N-1][0] = N-1;
    Next[N-2][0] = N-2;
    Next[N-2][1] = N-2;

    for (int i = N-3; i > 0; --i)
    {
        if (U2[Txt[i]-'0'][Txt[i+1]-'0'][i%2] == 0)
            U2[Txt[i]-'0'][Txt[i+1]-'0'][i%2] = i+1;

        if (U3[Txt[i]-'0'][Txt[i+1]-'0'][Txt[i+2]-'0'][i%3] == 0)
            U3[Txt[i]-'0'][Txt[i+1]-'0'][Txt[i+2]-'0'][i%3] = i+2;

        if (U2[Txt[i]-'0'][Txt[i+1]-'0'][i%2] != 0)
            Next[i][0] = U2[Txt[i]-'0'][Txt[i+1]-'0'][i%2]-1;
        else
            Next[i][0] = i-1;

        if (U3[Txt[i]-'0'][Txt[i+1]-'0'][Txt[i+2]-'0'][i%3] != 0)
            Next[i][1] = U3[Txt[i]-'0'][Txt[i+1]-'0'][Txt[i+2]-'0'][i%3]-2;
        else
            Next[i][1] = i-2;

    }

    for (int i = 0; i <= N+5; ++i)
        D[i][0] = D[i][1] = -INF;
    /*for (int i = 1; i <= N+1; ++i)
    {
        os << i << " : ";
        os << Next[i][0] << ' ' << Next[i][1] << '\n';
    }*/

    D[N+1][0] = D[N+1][1] = 0;



    for (int i = N-1, jump, step; i > 0; --i)
        for (step = 0; step < 2; ++step)
        {
            jump = GetJump(i, step);
            D[i][step] = max(D[jump][0], D[jump][1]) + 1;
        }

    os << max(D[1][0], D[1][1]) << '\n';
    for (int i = 1; i <= N;)
    {
        if (D[i][0] >= D[i][1])
            os << i << ' ' << "2\n", i = GetJump(i, 0);
        else
            os << i << ' ' << "3\n", i = GetJump(i, 1);
    }

    is.close();
    os.close();
}

int GetJump(int i, int step)
{
    if (MemRec[i][step])

        return MemRec[i][step];


    if (i + step + 2 > N)
        return i + step + 2;
    int j = Next[i][step];
    if (j + step + 2 > N || j == i)
    {
        MemRec[i][step] = j + step + 2;
        return MemRec[i][step];
    }

    int pos = i + step + 2;
    while (pos <= j){
        pos = GetJump(pos, step);
    }
    MemRec[i][step] = pos;
    return MemRec[i][step];
};
