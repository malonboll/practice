#include <iostream>
#include <queue>

using namespace std;

int N, M, temp, err;
int x, y;
int arr[1005][1005];

queue<int> q;

void Fill() {
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++) {
			arr[i][j] = 2;
		}
	}
}

int main() {
	Fill();
	int result = 0;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp);

			if (temp == 1)
				q.push(i*M + j); //i*j + j <= 1,000,000
			else if (temp == 0) // event
				err++;

			arr[i][j] = temp;
		}
	}

	int a = q.size();
	int count = 0;

	while (!q.empty()) {

		x = q.front() / M;
		y = q.front() % M;

		if (arr[x + 1][y] == 0) {
			arr[x + 1][y] = 1;
			q.push(q.front() + M);
			err--;
		}
		if (arr[x][y + 1] == 0) {
			arr[x][y + 1] = 1;
			q.push(q.front() + 1);
			err--;
		}
		if (x - 1 >= 0 && arr[x - 1][y] == 0) {
			arr[x - 1][y] = 1;
			q.push(q.front() - M);
			err--;
		}
		if (y - 1 >= 0 && arr[x][y - 1] == 0) {
			arr[x][y - 1] = 1;
			q.push(q.front() - 1);
			err--;
		}
		q.pop();
		count++;
		if (a == count) {
			result++;
			a = q.size();
			count = 0;
		}
	}

	if (err != 0) {
		result = -1;
		cout << result << endl;
	}
	else {
		cout << result - 1 << endl;
	}

	return 0;
}
