#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

ifstream is ("color2.in");
ofstream os ("color2.out");

int N, DH[16006], cnt;
bool DL[16006];
int Bro[16006];
vector <int> G[16006];
bitset <16006> B, B2;

void DF1(int t);
void DF2(int t);

int main()
{
    is >> N;
    for (int i = 1, a, b; i < N; ++i)
    {
        is >> a >> b;
        if (G[a].size() != 0)
            Bro[G[a][0]] = b, Bro[b] = G[a][0];
        G[a].push_back(b);
    }
    DF1(1);
    DH[1] = 1;
    DF2(1);
    for (int i = 1; i <= N; ++i)
        if (DH[i] == 1 && DL[i] == 1)
            cnt++;
    os << cnt << '\n';
    for (int i = 1; i <= N; ++i)
        if (DH[i] == 1 && DL[i] == 1)
            os << i << ' ';

    is.close();
    os.close();
}

void DF2(int t)
{
    B2[t] = 1;
    for (const auto& f : G[t])
        if (B2[f] == 0)
        {
            if (DH[t] == 0 || DL[Bro[f]] == 1)
                DH[f] = 1;
            DF2(f);
        }
};

void DF1(int t)
{
    B[t] = 1;
    DL[t] = 1;
    for (const auto& f : G[t])
        if (B[f] == 0)
        {
            DF1(f);
            if (DL[f] == 1 || DL[Bro[f]] == 1)
                DL[t] = 0;
        }
};




















