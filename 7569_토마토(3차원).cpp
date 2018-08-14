#include <iostream>
#include <queue>
using namespace std;

int N, M, H, err, result;
int arr[102][102][102];
queue<int> q;

void Fill() {
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			for (int k = 0; k < 102; k++) {
				arr[i][j][k] = 2;
			}
		}
	}
}

void Cheak() {
	int count = q.size();
	while (!q.empty()) {
		int data = q.front();
		int x, y, z;
		x = (data % (M * N)) % M;
		y = (data % (M * N)) / M;
		z = data / (M * N);
		if (arr[z][y][x + 1] == 0) {
			arr[z][y][x + 1] = 1;
			q.push(data + 1);
			err--;
		}
		if (x - 1 >= 0 && arr[z][y][x - 1] == 0) {
			arr[z][y][x - 1] = 1;
			q.push(data - 1);
			err--;
		}
		if (arr[z][y + 1][x] == 0) {
			arr[z][y + 1][x] = 1;
			q.push(data + M);
			err--;
		}
		if (y - 1 >= 0 && arr[z][y - 1][x] == 0) {
			arr[z][y - 1][x] = 1;
			q.push(data - M);
			err--;
		}
		if (arr[z + 1][y][x] == 0) {
			arr[z + 1][y][x] = 1;
			q.push(data + (M * N));
			err--;
		}
		if (z - 1 >= 0 && arr[z - 1][y][x] == 0) {
			arr[z - 1][y][x] = 1;
			q.push(data - (M * N));
			err--;
		}
		q.pop();
		count--;
		if (count == 0) {
			result++;
			count = q.size();
		}
	}
}

int main() {
	Fill();
	scanf("%d %d %d", &M, &N, &H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push((N*M*i) + (M*j) + k);
				}
				else if (arr[i][j][k] == 0) {
					err++;
				}
			}
		}
	}
	Cheak();

	if (err != 0)
		result = -1;
	else
		result--;

	cout << result << endl;
	return 0;
}

//	배열화 -> (N*M*i) + (M*j) + k
//	data / (M*N) = z축
//	( data % ( M * N ) ) / M  =  y축
//	( data % ( M * N ) ) % M  =  x축
