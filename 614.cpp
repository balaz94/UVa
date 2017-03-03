#include <iostream>
#include <stdio.h>
using namespace std;

int k, R, C, rS, cS, rF, cF, matrix[13][13], search[13][13];
bool bruteForce(int r, int c, int step);

int main() {
	k = 1;
	while (true) {
		cin >> R >> C >> rS >> cS >> rF >> cF;
		if (R == 0) return 0;
		
		for (int r = 1; r <= R; r++) {
			for (int c = 1; c <= C; c++) {
				cin >> matrix[r][c];
				search[r][c] = 0;
			}
		}

		bruteForce(rS, cS, 1);

		printf("Maze %d\n\n", k++);
		printf("+");
		for (int c = 1; c <= C; c++) {
			printf("---+");
		}
		printf("\n");
		for (int r = 1; r <= R; r++) {
			printf("|");
			for (int c = 1; c <= C; c++) {
				if (search[r][c] == -1) {
					printf("???");
				}
				else if (search[r][c] == 0) {
					printf("   ");
				}
				else {
					printf("%3d", search[r][c]);
				}

				if (c == C) {
					printf("|");
				}
				else {
					if (matrix[r][c] % 2 == 0)
						printf(" ");
					else
						printf("|");
				}
			}
			printf("\n+");
			if (r == R) {
				for (int c = 1; c <= C; c++) {
					printf("---+");
				}
			}
			else {
				for (int c = 1; c <= C; c++) {
					if (matrix[r][c] < 2)
						printf("   +");
					else
						printf("---+");
				}
			}
			printf("\n");
		}
		printf("\n\n");
	}
}

bool bruteForce(int r, int c, int step) {
	search[r][c] = step;
	if (r == rF && c == cF)
		return true;
	if (c - 1 > 0 && matrix[r][c-1] %2 == 0 && search[r][c - 1] == 0 && bruteForce(r, c - 1, step + 1)) {
		return true;
	} 
	if (r - 1 > 0 && matrix[r - 1][c] < 2 && search[r - 1][c] == 0 && bruteForce(r - 1, c, step + 1)) {
		return true;
	}
	if (c + 1 <= C && matrix[r][c] % 2 == 0 && search[r][c + 1] == 0 && bruteForce(r, c + 1, step + 1)) {
		return true;
	}
	if (r + 1 <= R && matrix[r][c] < 2 && search[r + 1][c] == 0 && bruteForce(r + 1, c, step + 1)) {
		return true;
	}

	search[r][c] = -1;
	return false;
}