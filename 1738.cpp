#include <iostream>
#include <set>

using namespace std;

class Cell {
public:
	Cell(int number) : value(number), left(nullptr), right(nullptr) { }
	int value;
	Cell *left, *right;
};

int k, n;

int main() {
	while (cin >> n) {
		cin >> k;
		set<set<int>> treeSet;
		for (int i = 0; i < n; i++) {
			set<int> mySet;
			int pom, tree;
			cin >> pom;
			Cell *root = new Cell(pom);
			for (int j = 1; j < k; j++) {
				cin >> pom;
				Cell *cell = new Cell(pom);
				Cell *actual = root;

				tree = 0;
				int k = 0;
				while (true) {
					if (actual->value > cell->value) {
						tree |= (1 << k);
						if (actual->left == nullptr) {
							actual->left = cell;
							tree |= (1 << (k+1));
							mySet.insert(tree);
							break;
						}
						else {
							actual = actual->left;
						}
					}
					else {
						if (actual->right == nullptr) {
							actual->right = cell;
							tree |= (1 << (k+1));
							mySet.insert(tree);
							break;
						}
						else {
							actual = actual->right;
						}
					}
					k++;
				}
			}
			treeSet.insert(mySet);
		}
		cout << treeSet.size() << endl;
	}
}