#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(&arr[0], &arr[n]);
	cout << arr[k - 1];
	delete[]arr;
	return 0;
}