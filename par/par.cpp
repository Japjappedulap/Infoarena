#include <fstream>
#include <stack>
using namespace std;
ifstream is ("par.in");
ofstream os ("par.out");
stack<char> Q;
int n, k;
char s[5001];
int main()
{
    is>>n;
    if (n % 2 == 1)
    {os << -1;return 0;}
    for (int i = 0; i < n; ++i)
        is >> s[i];
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')Q.push('(');
        if (s[i] == ')')
            if (Q.empty() == true){k++;Q.push('(');}
            else Q.pop();
    }
    k+=(Q.size()/2);
    os<<k;
    is.close();os.close();
    return 0;
}
