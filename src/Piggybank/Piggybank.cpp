/*
The MIT License (MIT)

Copyright (c) 2013 rajendrauppal

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>

#include "Piggybank.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Piggybank::Piggybank() : MAX_RAND(10000)
{
	int d[4] = {1, 2, 5, 10};
	denominations.assign(d, d + 4);
	srand((unsigned int)time(NULL));
	SetCoinCount(rand() % MAX_RAND);
	SetCoins();
}

Piggybank::~Piggybank()
{
	
}

inline 
int Piggybank::GetCoinCount() 
{ 
	return ncoins; 
}

inline
void Piggybank::SetCoinCount(int n) 
{
	ncoins = n; 
}

inline
void Piggybank::SetCoinDenominations(vector<int> d) 
{
	denominations.clear();
	denominations = d; 
}

inline
vector<int> Piggybank::GetCoinDenominations() 
{ 
	return denominations; 
}

inline
vector<int> Piggybank::GetCoins() 
{ 
	return coins; 
}

void Piggybank::SetCoins()
{
	coins.clear();
	for ( int i = 0; i < ncoins; ++i ) {
		int rand_denom = denominations[rand() % denominations.size()];
		coins.push_back(rand_denom);
	}
}

// Algorithm 1:
// 1. Count number of coins of each denomination
// 2. Find denomination sum and keep updating global sum
// TC: O(n * d), d = #denominations, n = #coins
// SC: O(1)
int Piggybank::GetTotalAmount_A()
{
	int total = 0;
	for ( auto start = denominations.begin(); start != denominations.end(); ++start ) {
		int cnt = std::count( coins.begin(), coins.end(), *start ); // O(n) algorithm
		int sum = cnt * (*start);
		total += sum;
	}

	return total;
}

// Algorithm 2:
// 1. Simply add all of them
int Piggybank::GetTotalAmount_B()
{
	return std::accumulate( coins.begin(), coins.end(), 0 );
}

void PrintResults(Piggybank pb, string input_method)
{
	cout << "----------------------" << endl;
	cout << input_method << endl;
	cout << "----------------------" << endl;
	cout << "Total number of coins: " << pb.GetCoinCount() << endl;
	cout << "Coin denominations: ";
	vector<int> d = pb.GetCoinDenominations();
	for ( size_t i = 0; i < d.size() - 1; ++i ) {
		cout << d[i] << ", ";
	}
	cout << d[d.size() - 1] << endl << endl;

	int total = pb.GetTotalAmount_A();
	cout << "Applying Method A: " << endl;
	cout << "Savings: " << total << " INR" << endl << endl;

	total = pb.GetTotalAmount_B();
	cout << "Applying Method A: " << endl;
	cout << "Savings: " << total << " INR" << endl << endl;
}

void Test_ProgramDefined()
{
	Piggybank pb;
	PrintResults( pb, "Program defined Input:" );
}

void Test_UserInput()
{
	int d[3] = {5, 10, 20};
	vector<int> denom( d, d + 3 );

	Piggybank pb;
	pb.SetCoinDenominations( denom );
	pb.SetCoinCount(rand() % 10000);
	pb.SetCoins();

	PrintResults( pb, "User Input:" );
}

int main()
{
	Test_ProgramDefined();
	Test_UserInput();

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
