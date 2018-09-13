#include <bits/stdc++.h>
using namespace std;

const int Nmax = 200001;

int N;
int V[Nmax];
int L[Nmax], R[Nmax];
int Stk[Nmax], top;

#define DIM 1<<17
char buff[DIM];
int poz = 0;

void citeste(int &numar)
{
    numar = 0;
    //cat timp caracterul din buffer nu e cifra ignor
    while (buff[poz] < '0' || buff[poz] > '9')
        //daca am "golit" bufferul atunci il umplu
        if (++poz == DIM)
            fread(buff, 1, DIM, stdin), poz = 0;
    //cat timp dau de o cifra recalculez numarul
    while ('0' <= buff[poz] && buff[poz] <= '9')
    {
        numar = numar * 10 + buff[poz] - '0';
        if (++poz == DIM)
            fread(buff, 1, DIM, stdin), poz = 0;
    }
}

int main()
{

    freopen("strabunica.in", "r", stdin);
    freopen("strabunica.out", "w", stdout);

    citeste(N);

    for (int i = 1; i <= N; ++i)
        citeste(V[i]);

    Stk[++top] = 1;

    for (int i = 2; i <= N; ++i)
    {
        while (top > 0 && V[Stk[top]] >= V[i])
            top--;
        if (top == 0)
            L[i] = i-1;
        else
            L[i] = i - Stk[top]- 1;
        Stk[++top] = i;
    }

    top = 0;
    Stk[++top] = N;
    for (int i = N-1; i > 0; --i)
    {
        while (top > 0&& V[Stk[top]] >= V[i])
            top--;
        if (top == 0)
            R[i] = N-i;
        else
            R[i] = Stk[top] - i - 1;
        Stk[++top] = i;
    }

    long long m = 0;
    for (int i = 1; i <= N; ++i)
        if (m < 1LL * V[i] * (L[i] + R[i] + 1))
            m = 1LL * V[i] * (L[i] + R[i] + 1);
    cout << m;
}
