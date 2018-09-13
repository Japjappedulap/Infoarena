#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("compress.in");
ofstream os ("compress.out");

char a[100625];
int cnt, n;

int main()
{
    is.getline(a, 100500, EOF);
    n = strlen(a);
    for (int i = 0; i <= n; i += cnt)
    {
        if (isalpha(a[i]) == false) continue;
        cnt = 1;
        while (a[i] == a[i+cnt])
            cnt++;
        os << a[i] << cnt;
    }

    is.close();
    os.close();
    return 0;
}
