#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> ans;

int main()
{
	int n, key, number;
	cin >> n >> key;

	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> number;
		arr[i] = number;
		if (arr[i] < key)
		{
			ans.push_back(arr[i]);
		}
	}
	
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}