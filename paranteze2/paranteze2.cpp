#include <fstream>
#include <cstring>
#include <stack>
using namespace std;

ifstream is ("paranteze2.in");
ofstream os ("paranteze2.out");

char s[1000001];
int n;
int nex[1000001];
int D[1000001];
unsigned long long rez;

stack <int> S;

int main()
{
    int i;
    is >> s;
    n = strlen(s);
    for (i = 0; s[i] != 0 ; ++i)
        if (S.size() != 0 && s[S.top()] == '(' && s[i] == ')')
        {
            nex[S.top()] = i + 1;
            S.pop();
        }
        else
            S.push(i);
    for (--i ; i >= 0 ;--i)
        if (nex[i])
        {
            D[i]= 1 + D[nex[i]];
            rez += D[i];
        }
    os << rez;
    is.close();
    os.close();
    return 0;
}

