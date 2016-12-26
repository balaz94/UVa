#include <iostream>
#include <cmath>
using namespace std;
long long int divide(long long int number, long long int start);

int main()
{
	long long int number;
	cin >> number;
	while (number > -1)
	{
		long long start = 2;
		while (number > 1) 
		{
			start = divide(number, start);
			number /= start;
			cout << "    " << start << endl;
		}
		cout << endl;
		cin >> number;
	}
	return 0;
}
long long int divide(long long int number, long long int start) 
{
	if (start == 2) {
		if (number % 2 == 0) 
			return 2;
		start++;
	}
	int n = sqrt(number) + 1;
	for (int i = start; i <= n; i += 2) {
		if (number % i == 0)
			return i;
	}
	return number;
}