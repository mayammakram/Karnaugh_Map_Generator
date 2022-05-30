/*
Name: Maya Hussein
UID: 900201198
Course: Digital Design I
Instructor: Dr. Mona Farouk
*/

#include <iostream>
#include <cstdlib>
#include <Bits.h>
#include <vector>
#include <algorithm>
using namespace std;

struct minterm
{
	int bit = 0;
	int position;

};
void displayKMap(vector<vector<minterm>> & kmap)
{
	cout << "K-Map:\n";
	for (int i = 0; i < kmap.size(); i++)
	{
		for (int j = 0; j < kmap[i].size(); j++)
			cout << '\t' << kmap[i][j].bit;
		cout << endl;
	}
}


void displayKMap2(vector<vector<minterm>>& kmap)
{
	cout << "K-Map:\n";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << '\t' << kmap[i][j].bit;
		cout << endl;
	}
}

void mintermAssignment1var(vector<vector<minterm>>& minterms)
{


	vector<int> values(2);
	cout << "How many minterms will you input?\n";
	int numMinterms;
	cin >> numMinterms;

	cout << "Enter Minterms:\n";
	for (int i = 0; i < numMinterms; i++)
	{
		cin >> values[i];
		for (int j = 0; j < i; j++)
		{
			if (values[i] == values[j])
			{
				cout << "Error: Please remove duplicates.\n";
				cin >> values[i];
			}
		}
	}

	//Minterms Error Handling
	if (*max_element(values.begin(), values.end()) > 2)
	{
		cout << "Error: Please Enter Valid Minterms.\n";
		cout << "Enter Minterms:\n";
		for (int i = 0; i < numMinterms; i++)
			cin >> values[i];
	}

	if (numMinterms == 2)
		cout << "F(A) = 1";
	else 
	{
		if (values[0] == 0)
			cout << "F(A) = A'";
		else
			cout << "F(A) = A";
	}
}

vector<vector<minterm>> mintermAssignment2var(vector<vector<minterm>>& minterms, int var)
{


	vector<int> values(4);
	cout << "How many minterms will you input?\n";
	int numMinterms;
	cin >> numMinterms;

	cout << "Enter Minterms:\n";
	for (int i = 0; i < numMinterms; i++)
	{
		cin >> values[i];
		for (int j = 0; j < i; j++)
		{
			if (values[i] == values[j])
			{
				cout << "Error: Please remove duplicates.\n";
				cin >> values[i];
			}
		}
	}

	//Minterms Error Handling
	if (*max_element(values.begin(), values.end()) > 4)
	{
		cout << "Error: Please Enter Valid Minterms.\n";
		cout << "Enter Minterms:\n";
		for (int i = 0; i < numMinterms; i++)
			cin >> values[i];
	}



	/*for (int i = 0; i < numMinterms; i++)
		cout << values[i] << " ";*/
		//Position Assignment
	minterms[0][0].position = 0;
	minterms[0][1].position = 1;

	minterms[1][0].position = 2;
	minterms[1][1].position = 3;


	//Minterm Assignment
	for (int n = 0; n < numMinterms; n++)
	{
		for (int i = 0; i < var; i++)
		{
			if (values[n] == minterms[0][i].position)
				minterms[0][i].bit = 1;

			if (values[n] == minterms[1][i].position)
				minterms[1][i].bit = 1;
		}

	}

	return minterms;
}
vector<vector<minterm>> mintermAssignment3var(vector<vector<minterm>>& minterms, int& varNum)
{

	//minterm m0, m1, m2, m3, m4, m5, m6, m7;

	vector<int> values(8);
	cout << "How many minterms will you input?\n";
	int numMinterms;
	cin >> numMinterms;

	cout << "Enter Minterms:\n";
	for (int i = 0; i < numMinterms; i++)
	{
		cin >> values[i];
		for (int j= 0; j < i; j++)
		{
			if (values[i] == values[j])
			{
				cout << "Error: Please remove duplicates.\n";
				cin >> values[i];
			}
		}
	}

	//Minterms Error Handling
	if (*max_element(values.begin(), values.end()) > 8)
	{
		cout << "Error: Please Enter Valid Minterms.\n";
		cout << "Enter Minterms:\n";
		for (int i = 0; i < numMinterms; i++)
			cin >> values[i];
	}

	

	/*for (int i = 0; i < numMinterms; i++)
		cout << values[i] << " ";*/
	//Position Assignment
	minterms[0][0].position = 0;
	minterms[0][1].position = 1;
	minterms[0][2].position = 3;
	minterms[0][3].position = 2;

	minterms[1][0].position = 4;
	minterms[1][1].position = 5;
	minterms[1][2].position = 7;
	minterms[1][3].position = 6;

	//Minterm Assignment
	for (int n = 0; n < numMinterms; n++)
	{
		for (int i = 0; i < varNum; i++)
		{
			if (values[n] == minterms[0][i].position)
				minterms[0][i].bit = 1;

			if (values[n] == minterms[1][i].position)
				minterms[1][i].bit = 1;
		}

	}

	return minterms;
}

string kMap2Var(vector<vector<minterm>>& minterms)
{
	string boolExp = "F(A, B, C) = ";

	string m0 = " + A'B'";
	string m1 = " + A'B";
	string m2 = " + AB'";
	string m3 = " + AB";

	if (minterms[0][0].bit == 1 && minterms[0][1].bit == 1 && minterms[1][0].bit == 1 && minterms[1][1].bit == 1)
		return " F(A, B, C) = 1";
	else
	{
		if ((minterms[0][0].bit == 1 && minterms[0][1].bit == 1) || (minterms[1][0].bit == 1 && minterms[1][1].bit == 1) || (minterms[0][0].bit == 1 && minterms[1][0].bit == 1) || (minterms[0][1].bit == 1 && minterms[1][1].bit == 1))
		{
			if (minterms[0][0].bit == 1 && minterms[0][1].bit == 1)
				boolExp += " + A'";

			if (minterms[1][0].bit == 1 && minterms[1][1].bit == 1)
				boolExp += " + A";

			if (minterms[0][0].bit == 1 && minterms[1][0].bit == 1)
				boolExp += " + B'";

			if (minterms[0][1].bit == 1 && minterms[1][1].bit == 1)
				boolExp += " + B";
		}
		else 
		{
			if (minterms[0][0].bit == 1)
				boolExp += " + A'B'";

			if (minterms[1][0].bit == 1)
				boolExp += " + AB'";

			if (minterms[1][1].bit == 1)
				boolExp += "  + AB";

			if (minterms[0][1].bit == 1)
				boolExp += " + A'B";
		}
	}

	boolExp.erase(13, 2);
	return boolExp;
}

string kMap3Var(vector<vector<minterm>>& minterms, int& varNum)
{
	string boolExp = "F(A, B, C) = ";

	string m0 = " + A'B'C'";
	string m1 = " + A'B'C";
	string m3 = " + A'BC";
	string m2 = " + A'BC'";

	string m4 = " + AB'C'";
	string m5 = " + AB'C";
	string m7 = " + ABC";
	string m6 = " + ABC'";



	//iterates over cubes and columns
	int even(0), odd(0);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < varNum; j++)
		{
			if (minterms[i][j].bit == 1 && minterms[i][j].position % 2 == 0)
				even++;

			if (minterms[i][j].bit == 1 && minterms[i][j].position % 2 == 1)
				odd++;
		}

	}

	//iterates over rows and pairs
	int r0(0), r1(0);
	for (int i = 0; i < varNum; i++)
	{
		if (minterms[0][i].bit == 1)
			r0++;

		if (minterms[1][i].bit == 1)
			r1++;
	}


	int total = odd + even;
	//cout << "Even:" << even << endl;
	//cout << "Odd:" << odd << endl;
	//cout << "Total:" << total << endl;
	//cout << endl;


	if (total == 8)
	{
		boolExp = boolExp + "1";
		return boolExp;
	}


	if (boolExp == "F(A, B, C) = ")
	{
		if (minterms[0][0].bit == 1 && minterms[1][0].bit == 1)
		{
			if (minterms[0][1].bit == 1 && minterms[0][2].bit == 1)
				return "F(A, B, C) = B'C' + A'C";

			if (minterms[1][1].bit == 1 && minterms[1][2].bit == 1)
				return "F(A, B, C) = B'C' + AC";
		}

		if (minterms[1][1].bit == 1 && minterms[0][1].bit == 1)
		{
			if (minterms[0][2].bit == 1 && minterms[0][3].bit == 1)
				return "F(A, B, C) = B'C + A'B";

			if (minterms[1][2].bit == 1 && minterms[1][3].bit == 1)
				return "F(A, B, C) = B'C + AB";
		}

		if (minterms[0][2].bit == 1 && minterms[1][2].bit == 1)
		{
			if (minterms[0][3].bit == 1 && minterms[0][0].bit == 1)
				return "F(A, B, C) = BC + A'C'";

			if (minterms[1][3].bit == 1 && minterms[1][0].bit == 1)
				return "F(A, B, C) = BC + AC'";
		}

		if (minterms[0][3].bit == 1 && minterms[1][3].bit == 1)
		{
			if (minterms[0][1].bit == 1 && minterms[0][2].bit == 1)
				return "F(A, B, C) = BC' + A'C";

			if (minterms[1][1].bit == 1 && minterms[1][2].bit == 1)
				return "F(A, B, C) = BC' + AC";
		}
	}


	if (minterms[0][0].bit == 1 && minterms[1][1].bit == 1 && minterms[0][2].bit == 1 && minterms[1][3].bit == 1)
	{
		boolExp = boolExp + m0 + m5 + m3 + m2;
		boolExp.erase(13, 2);
		return boolExp;
	}
	else if (minterms[1][0].bit == 1 && minterms[0][1].bit == 1 && minterms[1][2].bit == 1 && minterms[0][3].bit == 1)
	{
		boolExp = boolExp + m4 + m1 + m7 + m6;
		boolExp.erase(13, 2);
		return boolExp;
	}



	else
	{
		if (r0 == 4)
			boolExp = boolExp + " + A'";
		else if (r1 == 4)
			boolExp = boolExp + " + A";

		if (even == 4)
			boolExp = boolExp + " + C'";
		else if (odd == 4)
			boolExp = boolExp + " + C";

		if (even >= 2 && odd >= 2 && r0 > 1 && r1 > 1)
		{
			if (minterms[0][0].bit == 1 && minterms[1][1].bit == 1)
				boolExp = boolExp + " + B'";

			else if (minterms[0][2].bit == 1 && minterms[0][3].bit == 1)
				boolExp = boolExp + " + B";
		}

		if (even != 4 || odd != 4)
		{
			if (even >= 2 && even != 4)
			{
				if (r0 > 1 && r0 < 4 && (minterms[1][0].bit == 0 || minterms[1][3].bit == 0) && (minterms[0][0].bit == 1 && minterms[0][3].bit == 1))
					boolExp = boolExp + " + A'C'";
				else if (r1 > 1 && r1 < 4 && (minterms[0][0].bit == 0 || minterms[0][3].bit == 0) && (minterms[1][0].bit == 1 && minterms[1][3].bit == 1))
					boolExp = boolExp + " + AC'";


				if (minterms[0][0].bit == 1 && minterms[1][0].bit == 1 && (minterms[0][1].bit == 0 || minterms[1][1].bit == 0))
					boolExp = boolExp + " + B'C'";
				else if (minterms[0][3].bit == 1 && minterms[1][3].bit == 1 && (minterms[0][2].bit == 0 || minterms[1][2].bit == 0))
					boolExp = boolExp + " + BC'";
			}


			if (odd > 1 && odd != 4)
			{
				if (r0 > 1 && r0 < 4 && (minterms[1][1].bit == 0 || minterms[1][2].bit == 0) && (minterms[0][1].bit == 1 && minterms[0][2].bit == 1))
					boolExp = boolExp + " + A'C";
				else if (r1 > 1 && r1 < 4 && (minterms[0][1].bit == 0 || minterms[0][2].bit == 0) && (minterms[1][1].bit == 1 && minterms[1][2].bit == 1))
					boolExp = boolExp + " + AC";

				if (minterms[0][1].bit == 1 && minterms[1][1].bit == 1 && (minterms[0][0].bit == 0 || minterms[1][0].bit == 0))
					boolExp = boolExp + " + B'C";
				else if (minterms[0][2].bit == 1 && minterms[1][2].bit == 1 && (minterms[0][3].bit == 0 || minterms[1][3].bit == 0))
					boolExp = boolExp + " + BC";
			}

			if (even != 0 && odd != 0)
			{
				if (r0 > 1 && r0 < 4 && (minterms[1][0].bit == 0 || minterms[1][1].bit == 0) && (minterms[0][0].bit == 1 && minterms[0][1].bit == 1))
					boolExp = boolExp + " + A'B'";
				else if (r0 > 1 && r0 < 4 && (minterms[1][2].bit == 0 || minterms[1][3].bit == 0) && (minterms[0][2].bit == 1 && minterms[0][3].bit == 1))
					boolExp = boolExp + " + A'B";

				if (r1 > 1 && r1 < 4 && (minterms[0][0].bit == 0 || minterms[0][1].bit == 0) && (minterms[1][0].bit == 1 && minterms[1][1].bit == 1))
					boolExp = boolExp + " + AB'";
				else if (r1 > 1 && r1 < 4 && (minterms[0][2].bit == 0 || minterms[0][3].bit == 0) && (minterms[1][2].bit == 1 && minterms[1][3].bit == 1))
					boolExp = boolExp + " + AB";
			}
		}
	}


	if (minterms[0][0].bit==1 && minterms[0][1].bit == 0 && minterms[0][3].bit == 0 && minterms[1][0].bit == 0)
		boolExp = boolExp + m0;

	if (minterms[0][1].bit == 1 && minterms[0][0].bit == 0 && minterms[1][1].bit == 0 && minterms[0][3].bit == 0)
		boolExp = boolExp + m1;

	if (minterms[0][2].bit == 1 && minterms[0][1].bit == 0 && minterms[1][2].bit == 0 && minterms[0][3].bit == 0)
		boolExp = boolExp + m3;

	if (minterms[0][3].bit == 1 && minterms[0][2].bit == 0 && minterms[1][3].bit == 0 && minterms[0][0].bit == 0)
		boolExp = boolExp + m2;

	if (minterms[1][0].bit == 1 && minterms[0][0].bit == 0 && minterms[1][3].bit == 0 && minterms[1][1].bit == 0)
		boolExp = boolExp + m4;

	if (minterms[1][1].bit == 1 && minterms[1][2].bit == 0 && minterms[0][1].bit == 0 && minterms[1][0].bit == 0)
		boolExp = boolExp + m5;

	if (minterms[1][2].bit == 1 && minterms[1][1].bit == 0 && minterms[1][3].bit == 0 && minterms[0][2].bit == 0)
		boolExp = boolExp + m7;

	if (minterms[1][3].bit == 1 && minterms[0][3].bit == 0 && minterms[1][2].bit == 0 && minterms[1][0].bit == 0)
		boolExp = boolExp + m6;

	
	boolExp.erase(13,2);
	return boolExp;

}
int main()
{
	//Variable Assignment
	int var;
	cout << "How many variables are using?\n";
	cin >> var;
	if (var > 3) //Variable Error Handling
	{
		cout << "Error! Please choose from 1-3 variables\n";
		exit(0);
	}

	int varNum = var + 1;
	vector<vector<minterm>> minterms(2, vector<minterm> (varNum));

	if (var == 3) {


		mintermAssignment3var(minterms, varNum);
		displayKMap(minterms);
		cout << endl;
		cout << kMap3Var(minterms, varNum);

	}

	
	if (var == 2) {
		mintermAssignment2var(minterms, 2);
		displayKMap2(minterms);
		cout << endl;
		cout << kMap2Var(minterms);
	}

	if (var == 1)
	{
		mintermAssignment1var(minterms);
	}
	cout << endl;
	cout << "Thank you";
	return 0;
}
