#include <cstring>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream is ("adn.in");
ofstream os ("adn.out");

const int Nmax = 18;
const int INF = 0x3f3f3f3f;

int N, LSP[Nmax][Nmax];     //lsp[i][j] = longest prefix of i that is suffix of j
int D[Nmax][1<<Nmax], T[Nmax][1<<Nmax];

vector <string> Txt;
vector <int> BT;


bool Elim[Nmax];

int KMP(string P, string T);      //longest prefix of pattern that is also suffix of text
void RemoveIntern();
void MakeBT(int x, int mask);

int main()
{
    is >> N;
    Txt = vector<string> (N);
    for (int i = 0; i < N; ++i)
        is >> Txt[i];

    RemoveIntern();

    memset(D, -INF, sizeof(D));
    for (int bit = 0; bit < N; ++bit)
        D[bit][1<<bit] = 0;
    for (int mask = 1; mask < (1<<N); ++mask)
        for (int i = 0; i < N; ++i)
        if ((mask & (1<<i)))  //checkbit 1
            for (int j = 0; j < N; ++j)
            if ((i != j ) && (mask & (1<<j)) && (D[j][mask - (1<<i)] >= 0)) //checkbit 1 && check if there is a pos to achieve D[i][mask] (>=0)
                if (D[i][mask] < D[j][mask-(1<<i)] + LSP[j][i])
                    D[i][mask] = D[j][mask-(1<<i)] + LSP[j][i], T[i][mask] = j;

    int best = -INF, ind;
    for (int i = 0; i < N; ++i)
        if (best < D[i][(1<<N)-1])
            best = D[i][(1<<N)-1], ind = i;

    MakeBT(ind, (1<<N)-1);
    os << Txt[BT[0]];
    for (int i = 1; i < N; ++i)
        for (int k = LSP[BT[i]][BT[i-1]]; k < Txt[BT[i]].length(); ++k)
            os << Txt[BT[i]][k];

    is.close();
    os.close();
}

void MakeBT(int x, int mask)
{
    if (mask == 0) return;
    MakeBT(T[x][mask], mask-(1<<x));
    BT.insert(BT.begin(), x);
};

void RemoveIntern()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j && KMP(Txt[i], Txt[j]) == -1)
                Elim[i] = 1;
    for (int i = 0, k = 0; i < Txt.size(); ++i, ++k)
        if (Elim[k] == 1)
            Txt.erase(Txt.begin() + i), --i;

    N = Txt.size();

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j)
                LSP[i][j] = KMP(Txt[i], Txt[j]);
};

int KMP(string P, string T)
{
    int PL = P.length(), TL = T.length(), i, j;
    vector <int> DKMP(PL, 0);
    for (i = 1, j = 0; i < PL; ++i)
    {
        while (P[i] != P[j] && j != 0)
            j = DKMP[j-1];
        if (P[i] == P[j])
            ++j;
        DKMP[i] = j;
    }
    for (i = j = 0; i < TL; ++i)
    {
        while (P[j] != T[i] && j != 0)
            j = DKMP[j-1];
        if (T[i] == P[j])
            ++j;
        if (j == PL)    // pattern found entirely in text
            return -1;
    }
    return j;       //if pattern not found ENTIRELY, return longest prefix of pattern that is also suffix of text
};
