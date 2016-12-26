#include <iostream>
#include <cstring>
using namespace std;

int r = 0, a, b, i;
int parent[100001];

int find(int p);
void myUnion(int p, int q);

int main() {
	for (i = 0; i < 100001; i++)
		parent[i] = i;
	while (cin >> a) {
		if (a == -1) {
			cout << r << endl;
			r = 0;
			for (i = 0; i < 100001; i++) 
				parent[i] = i;
		}
		else {
			cin >> b;
			a = find(a);
			b = find(b);
			if (a == b) r++;
			else myUnion(b, a);
		}
	}
	return 0;
}

int find(int p) {
	while (p != parent[p]) {
		p = parent[p];
	}
	return p;
}

void myUnion(int p, int q) {
	parent[p] = q;
}