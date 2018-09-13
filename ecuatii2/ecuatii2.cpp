#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

ifstream is ("ecuatii2.in");
ofstream os ("ecuatii2.out");

char s[300];
char s1[300], s2[300];
int n, aux, Digits;
double Numar, Numit;
int coefst, coefdr, coefXst, coefXdr;

void Solve(char *, int &, int &);

int main()
{
    char *p;
    is >> n;
    for (int i = 0; i < n; i++)
    {
        is >> s1;
        p = strchr(s1, '=');
        strcpy (s2, p + 1);
        *p = NULL;
        Solve( s1, coefst, coefXst );
        Solve( s2, coefdr, coefXdr );
        if ( coefXst == coefXdr )
            if ( coefst == coefdr )
                os << "infinit" << '\n';
            else
                os << "imposibil" << '\n';
        else
        {
            Numar = (coefdr - coefst);
            Numit = (coefXst - coefXdr);
            aux = Numar/Numit;
            Digits = 0;
            while (aux)
            {
                Digits++;
                aux /= 10;
            }
            os << setprecision(4+Digits) << Numar/Numit << '\n';
        }

    }
    is.close();
    os.close();
    return 0;
}

void Solve(char *s, int &nr, int &nrx)
{
    char *k;
    char ss[300];
    int v;
    int semn = 1;
    int len;
    strcpy (ss, s);
    k = strtok (ss, "+-");
    nr = 0;
    nrx = 0;
    while (k)
    {
        len = strlen(k);
        if (k[0] == 'x')
            nrx += semn;
        else
            if (k[len - 1] == 'x')
            {
                k[len - 1] = NULL;
                v = atol(k);
                nrx = nrx + semn * v;
            }
            else
            {
                v = atol(k);
                nr = nr + semn * v;
            }
        if (s[k + len - ss] == '+')
            semn = 1;
        else
            semn = -1;
        k = strtok (NULL, "+-");
    }
}
