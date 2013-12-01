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

#include "Piggybank.h"

using std::cout;
using std::cin;
using std::endl;

Piggybank::Piggybank()
{
	int d[4] = {1, 2, 5, 10};
	denominations.assign(d, d + 4);

	srand((unsigned int)time(NULL));
	ncoins = rand();
	for ( int i = 0; i < ncoins; ++i ) {
		int rand_denom = denominations[rand() % 4];
		coins.push_back(rand_denom);
	}
}

Piggybank::~Piggybank()
{
	
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
		int cnt = std::count( coins.begin(), coins.end(), *start ); // O(1) algorithm
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

int main()
{
	Piggybank pb;
	int total = pb.GetTotalAmount_A();
	cout << "Savings: " << total << " INR" << endl;

	total = pb.GetTotalAmount_B();
	cout << "Savings: " << total << " INR" << endl;

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
