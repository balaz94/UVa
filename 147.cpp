#include <cstdio>
#include <cstring>

using namespace std;

int i, j, index_, p[11] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
long long dp[30001];
float n;

int main() {
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (i = 0; i < 11; i++) {
		for (j = 0; ; j += 5) {
			index_ = j + p[i];
			if (index_ > 30000)
				break;
			dp[index_] += dp[j];
		}
	}

	while (true) {
		scanf("%f", &n);
		if (n < 0.001)
			return 0;
		
		index_ = ((int)(n * 100));
		if (!(index_ % 10 == 5 || index_ % 10 == 0))
			index_++;
		printf("%6.2f%17lld\n", n, dp[index_]);
	}
}