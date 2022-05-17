/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int farm[100][100] = { 0 };
int m, n;

int dc(int x, int y) {
	farm[x][y] = 0;
	if (farm[x - 1][y] == 1 && x > 0) dc(x - 1, y);
	if (farm[x + 1][y] == 1 && x < m) dc(x + 1, y);
	if (farm[x][y - 1] == 1 && y > 0) dc(x, y - 1);
	if (farm[x][y + 1] == 1 && y < n) dc(x, y + 1);
	return 0;
}

int main() {

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {

		memset(farm, 0, sizeof(farm));

		int k;
		scanf("%d %d %d", &m, &n, &k);
	
		while (k--) {
			int x, y;
			scanf("%d %d", &x, &y);
			farm[x][y] = 1;
		}

		int worm = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (farm[i][j] == 1) {
					dc(i, j);
					worm++;
				}
			}
		}

		printf("%d\n", worm);
	}
}*/