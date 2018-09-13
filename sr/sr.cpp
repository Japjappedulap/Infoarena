#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("sr.in");
ofstream os ("sr.out");

char a[100002];
char b[100001];
int n;

int main()
{
    is >> a;
    is >> b;
    n = strlen(b);
    int i = 0, j = 0;
    while (j < n)
    {
        while (a[i] != b[j])
            ++i;
        os << i+1 << ' ';
        i++, j++;
    }
    is.close();
    os.close();
    return 0;
}
