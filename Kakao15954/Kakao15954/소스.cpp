#include<iostream>
#include<algorithm>
#include<cmath>
#include<limits>
#include<cfloat>

using namespace std;

int n, k;

double avg(double a[], int i, int k)
{
	double sum = 0;
	for (int b = i; b < k+i; b++)
	{
		sum += a[b];
	}
	return sum / k;
}

double var(double a[], double m, int i, int k)
{
	double sum = 0;
	for (int b = i; b < k+i; b++)
	{
		sum = sum + pow(a[b] - m, 2);
	}
	return sqrt(sum / k);
}

int main()
{
	double ans;
	cin >> n >> k;
	double *arr = new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	ans = DBL_MAX;
	while (n >= k)
	{
		for (int i = 0; i <= n - k; i++)
		{
			double m = avg(arr, i, k);
			double v = var(arr, m, i, k);
			ans = min(ans, v);
		}
		k++;
	}
	cout << fixed;
	cout.precision(7);
	cout << ans;
	return 0;
}