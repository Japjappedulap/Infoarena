#include <fstream>
#include <stack>
#include <vector>
using namespace std;

ifstream is ("editor.in");
ofstream os ("editor.out");

int T, n;
char c;

vector <char> V;
stack <char> S;

void Paranth();

int main()
{
    is >> T;
    for (int t = 0; t < T; t++)
    {
        c = 0;
        V.clear();
        while(!S.empty())
            S.pop();
        while (c != 'E')
        {
            is >> c;
            if (c == '*' && V.empty() == false) V.erase(V.end()-1);
            else if (c != '*') V.push_back(c);
        }
        if (V.size() % 2 == 0)
            os << ":(";
        else
            Paranth();
        os << '\n';
    }
    is.close();
    os.close();
    return 0;
}

void Paranth()
{
    for (int i = 0; i < V.size()-1; i++)
    {
        if ((V[i] == ')' || V[i] == ']' )&& S.empty() == true)
        {
            os << ":(";
            return;
        }
        if (V[i] == '[' || V[i] == '(') S.push(V[i]);
        else
        {
            if ((V[i] == ']' && S.top() == '(') || (V[i] == ')' && S.top() == '['))
            {
                os << ":(";
                return;
            }
            if ((V[i] == ']' && S.top() == '[') || (V[i] == ')' && S.top() == '(')) S.pop();
        }
    }
    if (S.empty())
        os << ":)";
    else
        os << ":(";
};
