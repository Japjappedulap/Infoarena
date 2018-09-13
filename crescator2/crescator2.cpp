// 100 puncte
#include <cstdio>
#define MOD 700001
#define NMAX 50005
using namespace std;
int C1[2][NMAX], C2[2][NMAX];

int main() {
	int s, sq, c1 = 0, p1 = 1, c2 = 0, p2 = 1;
	freopen("crescator2.in", "r", stdin);
	freopen("crescator2.out", "w", stdout);
	scanf("%d", &s);
	for (sq = 2; sq * sq <= s; ++sq);

	C1[0][0] = 1;
	for (int i = 1; i < sq; ++i) {
		c1 = 1 - c1; p1 = 1 - p1;
		for (int j = 0; j <= s; ++j) {
			C1[c1][j] = C1[p1][j];
			if (j >= i)
				C1[c1][j] = (C1[c1][j] + C1[c1][j - i]) % MOD;
		}
	}

	for (int j = 1; j <= s; ++j)
		C1[c1][j] = (C1[c1][j] + C1[c1][j - 1]) % MOD;
	int ans = C1[c1][s] - 1;
	if (ans < 0)
		ans += MOD;

	C2[0][0] = 1;
	for (int i = 1; i < sq; ++i) {
		c2 = 1 - c2; p2 = 1 - p2;
		for (int j = 0; j <= s; ++j) {
			C2[c2][j] = C2[p2][j - 1];
			if (j >= i)
				C2[c2][j] = (C2[c2][j] + C2[c2][j - i]) % MOD;
			int r = s - j - i * (sq - 1);
			if (r >= 0)
				ans = (ans + (long long) C2[c2][j] * C1[c1][r]) % MOD;
		}
	}
	printf("%d\n", ans);
	return 0;
}
