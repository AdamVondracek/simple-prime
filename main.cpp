#include<iostream>
#include<fstream>
#include<concepts>
#include<set>
#include<unordered_set>

template <std::integral IntT>
void fill_candidates(std::set<IntT>& set, const IntT max_val)
{
	set.insert(3);
	for (IntT n = 6; n <= max_val; n+=6)
	{
		set.insert(n - 1);
		set.insert(n + 1);
	}
}

template <std::integral IntT>
void find_primes(std::set<IntT>& set, const IntT max)
{
	std::unordered_set<IntT> lookup(set.begin(), set.end());
	IntT multiple = 0;
	for (IntT n : set)
	{
		for (IntT m : set)
		{
			multiple = n * m;
			if (multiple >= max)
			{
				break;
			}

			if (lookup.contains(multiple))
			{
				set.erase(multiple);
			}
		}
	}
}

template<std::integral IntT>
void print_set(const std::set<IntT> set)
{
	for (IntT p : set)
	{
		std::cout << p << std::endl;
	}
}

template<typename IntT>
void print_set(const std::set<IntT> set, const std::string& filename)
{
	std::ofstream outFile;
	outFile.open(filename);
	for (IntT p : set)
	{
		outFile << p << '\n';
	}
	outFile.close();
}

int main(void)
{
	typedef unsigned long long ull;
	constexpr size_t max = 1000000;
	std::set<ull> primes;
	fill_candidates(primes, max);
	find_primes(primes, max);
	print_set(primes, "primes.txt");
}
