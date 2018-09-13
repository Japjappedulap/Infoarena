#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("text.in");
ofstream os ("text.out");

char v[10000001];
int w, l, n;

int main()
{
    is.getline(v, 10000000, EOF);
    n = strlen(v);
    for (int i = 0; i < n; ++i)
        if (isupper(v[i]) || islower(v[i]))
        {
            w++;
            while (isupper(v[i]) || islower(v[i]))
            {
                i++;
                l++;
            }
        }
    os << l/w;
    is.close();
    os.close();
    return 0;
}
