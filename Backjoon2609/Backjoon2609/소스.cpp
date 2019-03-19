#include<iostream>

using namespace std;

int gcd(int x, int y)
{
	int r;
	while (y != 0)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main()
{
	int a, b, ans;
	cin >> a >> b;
	if (a < b)
	{
		int temp;
		temp = b;
		b = a;
		a = temp;
	}
	ans = gcd(a, b);
	cout << ans << endl;
	cout << a * b / ans;
	return 0;
}