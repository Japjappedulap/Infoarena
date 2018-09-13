#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("subsecvente2.in");
ofstream os ("subsecvente2.out");

struct Node{
    int mask;
    Node *Son[2];
    Node()
    {
        mask = 0;
        Son[0] = Son[1] = 0;
    }
};

Node *Root = new Node;
Node *X, *Ax;
int N;
char S[50002], *p;
int Sl, L, sol, ALL;


int main()
{
    is >> N;
    ALL = (1 << N) - 1;
    for (int k = 0; k < N; ++k)
    {
        is >> S;
        Sl = strlen(S);
        for (int i = 0; i < Sl; ++i)
        {
            p = S+i;
            X = Root;
            for (int j = 0; j <= 60 && *p; ++j, ++p)
            {
                if (X->Son[*p - 'a'] == 0)
                {
                    Ax = new Node;
                    Ax->mask |= (1<<k);
                    X->Son[*p - 'a'] = Ax;
                }
                X = X->Son[*p - 'a'];
                X->mask |= (1<<k);
                if (X->mask == ALL && j >= sol)
                    sol = j+1;
            }
        }
    }
    os << sol;
    is.close();
    os.close();
}

