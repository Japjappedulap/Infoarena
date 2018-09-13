#include <fstream>
using namespace std;

ifstream is("suma.in");
ofstream os("suma.out");

int main()
{
    unsigned long long n,p;
    is>>n>>p;
    if((n-1)%3==0){os<<(((n-1)/3%p)*(n%p)*((n+1)%p)%p);}
    else
        if(n%3==0){os<<((n/3%p)*((n-1)%p)*((n+1)%p)%p);}
        else
            if((n+1)%3==0){os<<(((n+1)/3%p)*(n%p)*((n-1)%p)%p);}
    return 0;
}
