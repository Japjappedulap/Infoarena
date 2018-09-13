#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("culori3.in");
ofstream os ("culori3.out");

int n;
int a1[1200], a2[1200], a3[1200], b1[1200], b2[1200], b3[1200];

void add(int A[], int B[], int C[]);

int main()
{
    is >> n;
    a1[0] = 1;
    a2[0] = 1;
    a3[0] = 1;
    a1[1] = 1;
    a2[1] = 1;
    a3[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        memcpy(b1, a2, sizeof(a2));
        add(a1, a3, b2);
        add(a2, a2, b3);
        memcpy(a1, b1, sizeof(a1));
        memcpy(a2, b2, sizeof(a2));
        memcpy(a3, b3, sizeof(a3));
        memset(b1, 0, sizeof(b1));
        memset(b2, 0, sizeof(b2));
        memset(b3, 0, sizeof(b3));
    }
    add(a1, a2, b1);
    add(b1, b1, b3);
    add(b3, a3, b2);
    for (int i = b2[0]; i > 0; --i)
        os << b2[i];
    is.close();
    os.close();
    return 0;
}

void add(int A[], int B[], int C[])
{
    int i, t = 0;
    for (i = 1; i <= A[0] || i <= B[0] || t; i++, t/=10)
        C[i] = (t += A[i] + B[i]) % 10;
    C[0] = i - 1;
}






