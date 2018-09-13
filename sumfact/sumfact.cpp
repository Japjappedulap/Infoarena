#include <fstream>
#include <vector>
using namespace std;

ifstream is ("sumfact.in");
ofstream os ("sumfact.out");

long long n, v[15], cnt[15];

vector <long long> e;

int main()
{
    is >> n;
    long long i = 1;
    v[i] = 1;
    do
    {
        ++i;
        v[i] = v[i-1]*i;

    }while(v[i]*i <= n);
    os << i << '\n';
    for ( ; i>= 1; --i)
    {
        while (n >= v[i])
        {
            n -= v[i];
            cnt[i] ++;

        }
        e.push_back(cnt[i]);
    }
    for (i = e.size()-1; i >= 0; --i)
        os << e[i] << '\n';



    is.close();
    os.close();
    return 0;
}
