#include <fstream>
#include <queue>
using namespace std;

ifstream is ("teatru.in");
ofstream os ("teatru.out");

queue <char> Q;
int n, c, Lmax, ITL;
char a[55003];
int cnt[27]; // A = 65, Z = 90 cnt[A] = 0, cnt[Z] = 25

void Read();
void Insertion();

int main()
{
    Read();
    Insertion();
    for (int i = c+1; i <= n; ++i)
    {
        if (Q.size() > Lmax) Lmax = Q.size(), ITL = i;
        if (cnt[a[i]-65] > 0)
            Q.push(a[i]), cnt[a[i]-65]++;
        else
        {
            do
            {
                cnt[Q.front()-65]--;
                if (cnt[Q.front()-65] == 0)
                {
                    Q.pop();
                    break;
                }
                Q.pop();
            }while(cnt[Q.front()-65] != 0);
            Q.push(a[i]), cnt[a[i]-65]++;
        }
    }
    os << Lmax << '\n';
    for (int i = ITL-Lmax; i <= ITL-1; i++)
        os << a[i];
    is.close();
    os.close();
    return 0;
}

void Insertion()
{
    int aux[27];
    for (int i = 1; i <= c; ++i)
    {
        Q.push(a[i]);
        if (cnt[a[i]-65] > 0)
            c++;
        cnt[a[i]-65]++;
    }
};

void Read()
{
    is >> n >> c;
    for (int i = 1; i <= n; ++i)
        is >> a[i];
};
