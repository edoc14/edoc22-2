#include <iostream>

using namespace std;

bool f(int n)
{
	int tmp = -1;
	while (n != 0)
	{
		if (n % 10 > tmp)
		{
			tmp = n % 10;
			n = n / 10;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int rr = 0;
	cin >> rr;
	if (rr == 0)
	{
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= 1000000000; i++)
	{
		if (f(i) == 1)
		{
			cnt++;

		}
		if (cnt == rr)
		{
			cout << i;
			return 0;
		}

	}
	cout << -1;
	return 0;
}