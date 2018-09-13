#include <fstream>
#include <cstring>
#include <set>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

ifstream is("reteta2.in");
ofstream os("reteta2.out");

char s[1010];
int S;
string stringaux;

vector <pair <string,int> > V;

int main()
{
    char v;
    int f = 0;
    while (is.get(v) )
    {
        if(v != ' ')
        {
        s[f] = v;
        ++f;
        }
    }
    for ( int i = 0; s[i]; ++i )
    {
        if ( s[i] == ')')
        {
            int aux = 0;
            while ( isdigit(s[i + 1]))
            {
                ++i;
                aux = aux * 10 + s[i] - 48;
            }
            S = S + aux;
        }
        if ( isalpha(s[i]) )
        {
            stringaux.assign(0,0);
            while ( isalpha(s[i]) )
            {
                stringaux += s[i];
                ++i;
            }

            int aux2 = 0;
            int q = i;
            while ( isdigit(s[q]) )
            {

                aux2 = aux2 * 10 + s[q] - '0';
                ++q;
            }
            V.push_back(make_pair(stringaux,aux2));

        }

    }
    sort(V.begin(),V.end());
    V.push_back(make_pair("NULL",0));
    os << S << '\n';
    int aux3;
    for ( int i = 0; i < V.size()-1; ++i )
    {
        if ( V[i].first == V[i+1].first )
        {
            V[i+1].second += V[i].second;

        }
        else
        {
        os << V[i].first << " ";
        os << V[i].second << '\n';
        }
    }
    is.close();
    os.close();
    return 0;
}
