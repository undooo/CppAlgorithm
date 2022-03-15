#include <iostream>
#include <algorithm>
using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int year)
{
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int get_day(int year, int month)
{
	if(month == 2) return 28 + check(year);
	return days[month];
}

int main()
{
	int n;
	cin >> n;
	
	string ans1, ans2;
	bool flag1 = false, flag2 = false;
	for (int i = n / 10000; i <= 9999; i ++)
	{
		string a = to_string(i);
		string b = a;
		reverse(b.begin(), b.end());
		if(a + b <= to_string(n)) continue;
		
		int month = stoi(b.substr(0, 2));
		int day = stoi(b.substr(2, 2));
		if(month < 1 || month > 12) continue;
		if(day < 1 || day > get_day(i, month)) continue;
		
		string s1 = a.substr(0, 2);
		string s2 = a.substr(2, 2);
		if(!flag1) ans1 = a + b, flag1 = true;
		if(!flag2 && s1 == s2 && s1[0] != s1[1]) ans2 = a + b, flag2 = true;

		if(flag1 && flag2) break;
	}
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	system("pause");
	return 0;
}
