#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

#define TX pair < pair <int,int>, pair<int,int> >
#define f first.first
#define s first.second
#define t second.first
#define ban second.second
#define mk(a,b,c,d) make_pair(make_pair(a, b), make_pair(c, d))

ifstream is ("mission.in");
ofstream os ("mission.out");

int n, x, y, res;
double aux;
TX pivot;

vector <TX> v;
vector <TX> :: iterator itdel;
vector <TX> R;

double Angle(TX point);

struct Crit {
    bool operator()(const std::TX &left, const std::TX &right) {
        return Angle(left) < Angle(right);
    }
};

int main()
{
    pivot.f = 2e9, pivot.s = 2e9;
    is >> n;
    for (int i = 0; i < n; ++i)
    {
        is >> x >> y;
        v.push_back(mk(x, y, i, 0));
        if (pivot.s > v[i].s)
            pivot = v[i];
    }
    itdel = v.begin()+pivot.t;
    v.erase(itdel);
    sort(v.begin(), v.end(), Crit());
    v.push_back(pivot);
    for (int i = 0; i < n; ++i)
        if (v[i].t == 0)
        {
            res = i;
            break;
        }
    for (int i = res; i < n; ++i)
        os << v[i].t << ' ';
    for (int i = 0; i < res; ++i)
        os << v[i].t << ' ';

    is.close();
    os.close();
    return 0;
}

double a, b, r;

double Angle(TX point)
{
    a = point.f - pivot.f;
    b = point.s - pivot.s;
    r = atan(a / b);
    r *= 180;
    r /= M_PI;
    return r;
};
