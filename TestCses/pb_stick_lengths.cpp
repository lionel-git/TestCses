#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <chrono>
#include <cassert>

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
//#define FILE_INPUT "c:\\tmp\\test_input (2).txt"
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#else
#define STREAM_IN std::cin
#define OPEN_IN
#endif

typedef std::int64_t ll_type;

#define VALUE_MIN (INT64_MIN);
#define VALUE_MAX (INT64_MAX);
#define N_MAX 200000

//https://cses.fi/problemset/task/1074
// Stick Lengths

int main_stick_lengths() {

	OPEN_IN;

	std::size_t n;
	STREAM_IN >> n;

	// Calcul mediane ?

	std::vector<ll_type> v(n);
	for (std::size_t i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		v[i] = k;
	}
	std::sort(v.begin(), v.end());

	ll_type mediane = v[v.size() / 2];

	ll_type delta = 0;
	for (std::size_t i = 0; i < n; i++)
	{
		delta += std::abs(v[i] - mediane);
	}
	std::cout << delta;
	return 0;
}
