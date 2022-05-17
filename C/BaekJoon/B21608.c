#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int number[20][5] = { 0 };
int filed[20][20] = { 0 };
int near, n, like = 0;

int includeOf(int x, int y, int index) {
	for (int i = 1; i < 5; i++) {
		if (filed[x][y] == number[index][i]) return 1;
	}
	return 0;
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n * n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &number[i][j]);
		}
	}

	for (int i = 0; i < n*n; i++) {
		int mx = 0, my = 0, max = 0, maxNo = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (filed[k][j] == 0) {
					int point = 0;
					int no = 0;

					if (j < n-1) {
						if (includeOf(k, j+1, i)) point++;
						else if (filed[k][j + 1] == 0) no++;
					}

					if (j > 0) {
						if (includeOf(k, j - 1, i)) point++;
						else if (filed[k][j - 1] == 0) no++;
					}

					if (k < n-1) {
						if (includeOf(k + 1, j, i)) point++;
						else if (filed[k + 1][j] == 0) no++;
					}

					if (k > 0) {
						if (includeOf(k - 1, j, i)) point++;
						else if (filed[k - 1][j] == 0) no++;
					}
					if (point > max) {
						max = point;
						maxNo = no;
						my = j;
						mx = k;
					}
					else if (point == max && no > maxNo) {
						maxNo = no;
						my = j;
						mx = k;
					}
				}
			}
		}
		filed[mx][my] = number[i][0];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int f = 0;
			int index = 0;
			for (int k = 0; k < n*n; k++) {
				if (filed[j][i] == number[k][0]) index = k;
			}
			if (includeOf(j+1, i, index)) f++;
			if (includeOf(j-1, i, index)) f++;
			if (includeOf(j, i+1, index)) f++;
			if (includeOf(j, i-1, index)) f++;

			if (f == 1)
				like += 1;
			else if(f > 1){
				int l = 10;
				for (int i = 0; i < f-2; i++) {
					l *= 10;
				}
				like += l;
			}
		}
	}
	printf("%d", like);
}