#include<iostream>
#include<vector>
using namespace std;

struct Point {
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int ccw(vector<Point> a)
{
	int temp = a[0].x * a[1].y + a[1].x*a[2].y + a[2].x*a[0].y;
	temp = temp - a[1].x*a[0].y - a[2].x*a[1].y - a[0].x*a[2].y;
	if (temp == 0)
	{
		return 0;
	}
	else if (temp > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int x, y;
	vector<Point> spot;
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		spot.push_back(Point(x, y));
	}
	int ans = ccw(spot);
	cout << ans;
	return 0;
}