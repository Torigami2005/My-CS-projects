#include <iostream>
using namespace std;
int main()
{
	
	int n;
	int k = 1;
	cout << endl;

	cout << "Input a number: ";
	cin >> n;
	while (k <= n) {

		int c = 1;
		while (c <= n) {
			cout << k * c << "\t";
			c++;
		}
		cout << endl;
		k++;
	}

	cout << endl;
}

