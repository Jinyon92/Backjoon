#include<iostream>

using namespace std;

int arr[2188][2188];
int ans[3];

bool check(int r, int c, int num)
{
	int key = arr[r][c];
	for (int i = r; i < r + num; i++)
	{
		for (int j = c; j < c + num; j++)
		{
			if (arr[i][j] != key)
			{
				return false;
			}
		}
	}
	return true;
}

void divide(int r, int c, int num)
{
	if (check(r, c, num))
	{
		ans[arr[r][c] + 1]++;
	}
	else
	{
		int newSize = num / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				divide(r + newSize * i, c + newSize * j, newSize);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	divide(0, 0, n);
	for (int i = 0; i < 3; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}