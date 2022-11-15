#include <iostream>
#include <string>

using namespace std;

int kingR, kingC, rockR, rockC;

void R()
{
	if (kingR + 1 == rockR && kingC == rockC) {
		if (rockR == 8)
		{
			return;
		}
		rockR++;
	}

	if (kingR == 8)
		return;
	kingR++;
}
void L()
{
	if (kingR - 1 == rockR && kingC == rockC) {
		if (rockR == 1)
		{
			return;
		}
		rockR--;
	}

	if (kingR == 1)
		return;
	kingR--;
}
void B()
{
	if (kingC - 1 == rockC && kingR == rockR) {
		if (rockC == 1)
		{
			return;
		}
		rockC--;
	}
	if (kingC == 1)
		return;
	kingC--;
}
void T()
{
	if (kingC + 1 == rockC && kingR == rockR) {
		if (rockC == 8)
		{
			return;
		}
		rockC++;
	}
	if (kingC == 8)
		return;
	kingC++;
}
void RT()
{
	if (kingC + 1 == rockC && kingR + 1 == rockR) {
		if (rockC == 8 || rockR == 8)
		{
			return;
		}
		rockR++;
		rockC++;
	}
	if (kingC == 8 || kingR == 8)
	{
		return;
	}
	kingR++;
	kingC++;
}
void LT()
{
	if (kingC + 1 == rockC && kingR - 1 == rockR) {
		if (rockC == 8 || rockR == 1)
		{
			return;
		}
		rockR--;
		rockC++;
	}
	if (kingC == 8 || kingR == 1)
	{
		return;
	}
	kingR--;
	kingC++;
}
void RB()
{
	if (kingC - 1 == rockC && kingR + 1 == rockR) {
		if (rockC == 1 || rockR == 8)
		{
			return;
		}
		rockR++;
		rockC--;
	}
	if (kingC == 1 || kingR == 8)
	{
		return;
	}
	kingR++;
	kingC--;
}
void LB()
{
	if (kingC - 1 == rockC && kingR - 1 == rockR) {
		if (rockC == 1 || rockR == 1)
		{
			return;
		}
		rockR--;
		rockC--;
	}
	if (kingC == 1 || kingR == 1)
	{
		return;
	}
	kingR--;
	kingC--;
}

int main()
{
	string k, r, input;
	int tc;
	cin >> k >> r >> tc;
	kingR = k[0] - 'A' + 1;
	kingC = k[1] - '1' + 1;
	rockR = r[0] - 'A' + 1;
	rockC = r[1] - '1' + 1;

	while (tc--)
	{
		cin >> input;
		if (!input.compare("R"))
			R();
		else if (!input.compare("L"))
			L();
		else if (!input.compare("B"))
			B();
		else if (!input.compare("T"))
			T();
		else if (!input.compare("RT"))
			RT();
		else if (!input.compare("RB"))
			RB();
		else if (!input.compare("LT"))
			LT();
		else
			LB();
	}
	k[0] = kingR - 1 + 'A';
	k[1] = kingC - 1 + '1';
	r[0] = rockR - 1 + 'A';
	r[1] = rockC - 1 + '1';
	
	cout << k << "\n" << r;

	return 0;
}