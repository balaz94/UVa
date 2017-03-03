#include <iostream> 
#include <string>
#include <stack>
using namespace std;
int n, o, h;
bool b;
int main() {
	string line;
	getline(cin, line);
	n = stoi(line);
	while (n--) {
		string line;
		getline(cin, line);
		o = 0;
		h = 0;
		b = true;
		stack<char> q;
		for (int i = 0; i < line.length(); i++) {
			char c = line.at(i);
			if (c == '(') {
				o++;
				q.push(c);
			}
			else if (c == ')') {
				o--;
				if (o < 0 || q.top() != '(') {
					b = false;
					break;
				}
				q.pop();
			}
			else if (c == '[') {
				h++;
				q.push(c);
			}
			else if (c == ']') {
				h--;
				if (h < 0 || q.top() != '[') {
					b = false;
					break;
				}
				q.pop();
			}
		}
		if (b && h == 0 && o == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}