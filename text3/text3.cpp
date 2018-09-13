#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

ifstream is ("text3.in");
ofstream os ("text3.out");

char ch[25], c[20001][26], aux;
vector <pair<char, char> > v;
vector <int> d;
int N, m[20001][2], cnt[27], Lmax;

void Read();
void Solve();
void debug();

int main()
{
    Read();
    Solve();
    is.close();
    os.close();
    return 0;
}

void Solve()
{
    memset(cnt, 0, sizeof(cnt));
    d.resize(N);
    for (int i = N-1; i >= 0; i--)
    {
        d[i] = cnt[v[i].second-97]+1;
        cnt[v[i].first-97] = max(cnt[v[i].first-97], d[i]);
        if (Lmax < d[i]) Lmax = d[i], aux = v[i].first;
    }
    os << N << '\n' << N-Lmax << '\n';
    for (int i = 0; i < N; ++i)
        if (d[i] == Lmax && v[i].first == aux)
            os << c[i] << '\n', aux = v[i].second, Lmax--;
};

void Read()
{
    while (is >> ch)
    {
        strcpy (c[N], ch);
        v.push_back ( make_pair (ch[0], ch[strlen(ch)-1]) );
        cnt[ch[0]-97]++, N++;
    }
};
