#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int arr[101];

int gcd(int a, int b)
{
	while (b > 0)
	{
		int temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int ans = arr[1] - arr[0];
	for (int i = 1; i < n-1; i++)
	{
		int value = arr[i + 1] - arr[i];
		ans = gcd(ans, value);
	}
	vector<int> answer;
	for (int i = 1; i*i <= ans; i++)
	{
		if (ans % i == 0)
		{
			if (i*i == ans)
			{
				answer.push_back(i);
				break;
			}
			if (i > 1)
			{
				answer.push_back(i);
			}
			answer.push_back(ans / i);
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
	{
		printf("%d ", answer[i]);
	}
	return 0;
}