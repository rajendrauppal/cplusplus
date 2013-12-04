
/*

Piggybank.h

$Id: ~/git/C++/src/Piggybank/Piggybank.h $

Definition of the Piggybank class.

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

#ifndef Piggybank_INCLUDED
#define Piggybank_INCLUDED

#include <vector>
using std::vector;

class Piggybank
{
public:
	Piggybank();

	~Piggybank();

	int GetCoinCount();

	void SetCoinCount(int n);

	void SetCoinDenominations(vector<int> d);

	vector<int> GetCoinDenominations();

	vector<int> GetCoins();

	void SetCoins();

	int GetTotalAmount_A();

	int GetTotalAmount_B();

private:
	vector<int> denominations;
	vector<int> coins;
	int ncoins;
	const int MAX_RAND;
};

#endif // Piggybank_INCLUDED