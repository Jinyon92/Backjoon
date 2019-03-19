#include<iostream>

using namespace std;

int main()
{
	int n;
	int counter = 0;
	cin >> n;
	while (n % 5 != 0)
	{
		counter += 1;
		n = n - 3;
		if (n < 0)
		{
			counter = -1;
			break;
		}
	}
	int num = n / 5;
	counter = counter + num;
	cout << counter;
	return 0;
}