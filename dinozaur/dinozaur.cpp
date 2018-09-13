#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("dinozaur.in");
ofstream os ("dinozaur.out");

char s[100001];
bool cnt[26], ex;

int main()
{
    int x;
    is >> s;
    x = strlen(s);
    for (int i = 0; i < x; ++i)
    {
        if (cnt[s[i]-97] == true)
        {
            ex = true;
            break;
        }
        else
            cnt[s[i]-97] = true;
    }
    if (ex == true)
        os << 1;
    else
        os << 0;
    is.close();
    os.close();
    return 0;
}
