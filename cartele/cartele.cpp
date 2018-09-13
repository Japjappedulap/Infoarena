#include <fstream>
using namespace std;

ifstream is ("cartele.in");
ofstream os ("cartele.out");

short n, c;
short sablon[51][51];
short cartela[51][51];
bool pus;

bool Turn();
void Check();
void Mirror();

int main()
{
    is >> n >> c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            is >> sablon[i][j];
    for (int k = 0; k < c; k++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                is >> cartela[i][j];
        pus = false;
        for (int g = 0; g < 8 && pus == false; g++)
        {
            pus = false;
            Check();
            if (pus == true)
                os << true << '\n';
            else
            {
                if (g != 3)
                    Turn();
                else
                    Mirror();
            }
        }
        if (pus == false)
            os << false << '\n';
    }
    is.close();
    os.close();
    return 0;
}

bool Turn()
{
    bool aux[51][51];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            aux[j][n-i-1] = cartela[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cartela[i][j] = aux[i][j];
}

void Check()
{
    pus = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cartela[i][j] != sablon[i][j])
            {
                pus = false;
                break;
            }
}

void Mirror()
{
    bool aux;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n/2; j++)
            {
                aux = cartela[i][j];
                cartela[i][j] = cartela[i][n-j-1];
                cartela[i][n-j-1] = aux;
            }
    }
    else
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < (n-1)/2; j++)
            {
                aux = cartela[i][j];
                cartela[i][j] = cartela[i][n-j-1];
                cartela[i][n-j-1] = aux;
            }
    }
}







