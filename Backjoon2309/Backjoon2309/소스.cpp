#include<iostream>
#include<algorithm>
using namespace std;

int height[9];

int main()
{
	int h;
	int sum = 0;
	bool stop = false;
	for (int i = 0; i < 9; i++)
	{
		cin >> h;
		height[i] = h;
		sum = sum + h;
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - height[i] - height[j] == 100)
			{
				height[i] = 0;
				height[j] = 0;
				stop = true;
				break;
			}
		}
		if (stop)
		{
			break;
		}
	}
	sort(height, height + 9);
	for (int i = 2; i < 9; i++)
	{
		cout << height[i] << endl;
	}
	return 0;
}