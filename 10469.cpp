#include <stdio.h>
using namespace std;
unsigned long a, b;

int main() {
	while (scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", (a | b) - (a & b));
	}
	return 0;
}