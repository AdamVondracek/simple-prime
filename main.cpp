#include<iostream>
#include<fstream>
#include<concepts>
#include<set>
#include<unordered_set>
#include<array>

template <std::integral int_t, std::size_t _size>
std::array<int_t, _size> 
fill_candidates(void)
{
  std::array<int_t, _size> numbers = {};
  numbers[3] = (int_t)3;
	for (int_t n = 6; n < _size - 1; n+=6)
	{
		numbers[n - 1] = n - 1;
		numbers[n + 1] = n + 1;
	}
  return numbers;
}

template <std::integral int_t, std::size_t _size>
void find_primes(std::array<int_t, _size> &numbers)
{
  int_t multiple;
  for(int_t n : numbers)
  {
    for(int_t m = 3; (multiple = n*m) < _size && n != 0; ++m)
    {
      numbers[multiple] = 0;
    }
  }
  numbers[2] = 2;
}

int main(void)
{
	typedef unsigned long long ull;
	constexpr ull max = 1000;
	auto arr = fill_candidates<ull, max>();
	find_primes<ull, max>(arr);
	for(ull x : arr)
  {
    if(x != 0){ std::cout<< x << '\n'; }
  }
}
