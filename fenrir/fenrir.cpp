#include <fstream>
std::ofstream c("fenrir.out");
int main(){c << "99\n";for(int i=1;i<=9;++i)for(int j=10;j<=20;++j)c<<i<<' '<<j<<'\n';}
