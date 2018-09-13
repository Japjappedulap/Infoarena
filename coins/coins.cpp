#include <fstream>
using namespace std;

ifstream is ("coins.in");
ofstream os ("coins.out");

const int BUFFER = 1<<17;
char BF[BUFFER], *p;
inline int GET();
inline void Check();

int N;
bool B[1<<22];

void Write(int X)       //writes X in binary
{
    if (X == 0) return;
    Write(X >> 1);
    os << X % 2;
}

void Initialization();

int main()
{
    p = BF;

    Initialization();

    N = GET();
    int Sol = 0;
    for (int i = 1, bit, value, number = 0, count = 0; i <= N; ++i, number = 0, count = 0)
    {
        for (bit = 0; bit < 22; ++bit)
        {
            value = GET();
            count = count + value;
            number |= (value * (1<<bit));
        }
        if (B[number] == 1)
            Sol += count;
    }
    os << Sol;

    is.close();
    os.close();
}

void Initialization()
{
    bool all1, found;
    int posmask, bit;
    B[0] = 1;
    for (int mask = 1; mask < (1<<22); ++mask)
    {
        all1 = 1;
        for (bit = 0; (1<<bit) <= mask; ++bit)
        {
            if ((mask & (1<<bit)) == 0)    //checkbit 0
                all1 = 0;
        }
        if (all1 == 1)
        {
            B[mask] = 1;
            continue;
        }
        all1 = 0;

        for (; bit > 0; --bit)
            if (mask & (1<<bit))           //checkbit 1
            {
                posmask = mask ^ (1<<bit);      //posmask is mask with bit *bit* = 0
                found = 0;
                for (int bit0 = bit-1; bit0 >= 0; --bit0)
                    if ((mask & (1<<bit0)) == 0)        //checkbit 0
                    {
                        posmask = posmask | (1<<bit0);  //posmask has bit bit0 = 1
                        found = 1;
                        break;
                    }
                if (found == 0) continue;

                if (B[posmask] == 0)
                {
                    B[mask] = 1;
                    all1 = 1;
                    break;
                }
            }
        if (all1 == 0)
            B[mask] = 0;
    }
};

















inline int GET()
{
    int X = 0;
    while (*p < '0' || '9' < *p) ++p, Check();
    while ('0' <= *p && *p <= '9') X = X*10 + (*p-'0'), ++p, Check();
    return X;
};

inline void Check()
{
    if (*p == '\0') is.get(BF, BUFFER, '\0'), p = BF;

};
