#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(const string &s1, const string &s2)
{
	if (s1.size() == s2.size())
	{
		return s1 < s2;
	}
	return s1.size() < s2.size();
}

int main()
{
	int n;
	cin >> n;
	vector<string> v;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << "\n";
	}
	return 0;
}