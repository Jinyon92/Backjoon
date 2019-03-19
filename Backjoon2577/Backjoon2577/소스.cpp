#include<iostream>

using namespace std;

int ans[10];

int main()
{
	int a, b, c,result;
	cin >> a >> b >> c;
	result = a * b*c;
	while (1)
	{
		ans[result % 10]++;
		result = result / 10;
		if (result < 1)
		{
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}