#include<iostream>

using namespace std;

int main()
{
	int n, kim, lim;
	int counter = 0;
	cin >> n >> kim >> lim;
	while (1)
	{
		if (kim % 2 == 1)
		{
			kim = kim / 2 + 1;
		}
		else
		{
			kim = kim / 2;
		}
		if (lim % 2 == 1)
		{
			lim = lim / 2 + 1;
		}
		else
		{
			lim = lim / 2;
		}
		counter++;
		if (kim == lim)
		{
			break;
		}
	}
	cout << counter;
	return 0;
}