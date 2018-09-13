#include <fstream>
#include <cmath>

#define IN "geometry.in"
#define OU "geometry.out"
#define EPS 0.01

std::ifstream is (IN);
std::ofstream os (OU);

struct Point{
    int x, y;
};

struct Segment{
    Point A, B;
};

Segment V[505];
int a, b, c, sol;
int N;

void Input();
void Coef(Segment S);
bool Inters(Segment S1, Segment S2);

int main()
{
    Input();
    for (int i = 1; i <= N; ++i)
        for (int j = i+1; j <= N; ++j)
            if (Inters(V[i], V[j]) == true)
                sol++;
    os << sol;
    is.close();
    os.close();
}

void Input()
{
    std::pair <int, int> A, B, R;
    is >> N;
    for (int i = 1; i <= N; ++i)
    {
        is >> A.first >> A.second >> B.first >> B.second;
        R = min(A, B);
        V[i].A.x = R.first, V[i].A.y = R.second;
        R = max(A, B);
        V[i].B.x = R.first, V[i].B.y = R.second;
    }
};

void Coef(Segment S)
{
    a = (S.B.y - S.A.y);
    b = (S.A.x - S.B.x);
    c = (S.B.x * S.A.y - S.A.x * S.B.y);
};

bool Inters(Segment S1, Segment S2)
{
    long long Z1, Z2;
    Coef(S1);
    Z1 = 1LL*(a*S2.A.x + b*S2.A.y + c)*(a*S2.B.x + b*S2.B.y + c);
    if ( Z1 > 0 )
        return false;
    Coef(S2);
    Z2 = 1LL*(a*S1.A.x + b*S1.A.y + c)*(a*S1.B.x + b*S1.B.y + c);
    if ( Z2 > 0 )
        return false;
    if ( Z1 == 0 && Z2 == 0 )
    {
        if (S1.B.x < S2.A.x)
            return false;
        if (S1.B.x == S2.A.x && S1.B.y < S2.A.y)
            return false;

    }
    return true;
};
