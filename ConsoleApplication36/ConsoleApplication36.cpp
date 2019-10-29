#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "pch.h"
using namespace std;

double f_abs(double x)
{
	return (x < 0) ? -x : x;
}

int i_pow_nat(int b, int p)
{
	if (!p) return 1;
	return b * i_pow_nat(b, p - 1);
}

string numeric_to_string(int n)
{
	vector<string> num_vect_0 = {
		"","one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"
	};
	vector<string> num_vect_1 = {
		"ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen","sixteen", "seventeen", "eighteen", "nineteen"
	};
	vector<string> num_vect_2 = {
		"", "", "twenty", "thirty", "forty",
		"fifty", "sixty", "seventy", "eighty", "ninety"
	};

	if (n < 10) {
		return num_vect_0[n];
	}
	else if (n < 20) {
		return num_vect_1[n - 10];
	}
	else if (n < 100) {
		return num_vect_2[n / 10] +
			((n % 10 != 0) ? " " + numeric_to_string(n % 10) : "");
	}
	else if (n < 1000) {
		return numeric_to_string(n / 100) +
			" hundred" + ((n % 100 != 0) ? " " + numeric_to_string(n % 100) : "");
	}
	else if (n < 1000000) {
		return numeric_to_string(n / 1000) +
			" thousand" + ((n % 1000 != 0) ? " " + numeric_to_string(n % 1000) : "");
	}
	else if (n < 1000000000) {
		return numeric_to_string(n / 1000000) +
			" million" + ((n % 1000000 != 0) ? " " + numeric_to_string(n % 1000000) : "");
	}
	else if (n < 1000000000000) {
		return numeric_to_string(n / 1000000000) +
			" billion" + ((n % 1000000000 != 0) ? " " + numeric_to_string(n % 1000000000) : "");
	}
	return "";
}

unsigned f_int_pos(unsigned inp, unsigned mod_n)
{
	return (inp * inp) % mod_n;
}

unsigned f_int_neg(int inp, unsigned mod_n)
{
	return (i_pow_nat(inp, 5) + i_pow_nat(inp, 3)) % mod_n;
}

unsigned f_dec_any(double inp, int val)
{
	return static_cast<int>(f_abs((sin(inp + static_cast<float>(val))) * 100)) % 100;
}

void invert_str(string& addr)
{
	unsigned l = addr.length();

	for (unsigned j = 0; j < l / 2; j++)
	{
		swap(addr[j], addr[l - j - 1]);
	}
}

string f_str_inv(const string& inp)
{
	string result = inp;
	invert_str(result);
	return result;
}

string f_other(const string& msg)
{
	return msg;
}

string f(int n)
{
	return numeric_to_string((n >= 0) ? (f_int_pos(n, 159)) : (f_int_neg(n, 259)));
}

string f(float d)
{
	return numeric_to_string(f_dec_any(d, 359));
}

string f(double d)
{
	return numeric_to_string(f_dec_any(d, 359));
}

string f(const string& s)
{
	return f_str_inv(s);
}

string f(pair<int, int> p)
{
	return f(p.second) + " " + f(p.first);
}

string f_int_seq(const list<int>& v)
{
	vector<string> container;
	for (auto j : v)
	{
		container.push_back(f(j));
	}
	sort(
		container.begin(), container.end(),
		[](const string& a, const string& b)
	{
		return a < b;
	}
	);
	string result;
	for (auto s : container)
	{
		result += s + "; ";
	}
	return result;
}

string f(const list<int>& v)
{
	return f_int_seq(v);
}

template <typename other>
string f(other x)
{
	return "sorry try again";
}

int main()
{
	int num_0;

	cout << "input integer value" << endl;
	cin >> num_0;
	cout << f(num_0) << endl;

	float num_1;

	cout << "input float value" << endl;
	cin >> num_1;
	cout << f(num_1) << endl;

	pair<int, int> p_0;

	cout << "input integer value (first pair elem)" << endl;
	cin >> p_0.first;

	cout << "input integer value (second pair elem)" << endl;
	cin >> p_0.second;

	cout << f(p_0) << endl;

	list<int> l_i;

	for (unsigned j = 0; j < 3; j++)
	{
		int temp;
		cout << "input integer value" <<endl;
		cin >> temp;
		l_i.push_back(temp);
	}

cout << f(l_i) << endl;

	char other = 'c';

	cout << f(other) << endl;

}

