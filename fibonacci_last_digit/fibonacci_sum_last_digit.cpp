#include <iostream>
#include <cassert>
#include <cstdlib>


int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
    		std::cout << sum << '\n';
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_no_of(long long n)
{
    if (n <= 1)
        return n;

    constexpr 	long long m 			{10};
    constexpr	long long F0 		{0};
    constexpr	long long F1 		{1};
    				long long Fn_2		{F0};
    				long long Fn_1		{F1};
    				long long Fn;
    				long long sum 		{F0 + F1};

    for (long long i = 2; i <= n; ++i)
    {
        Fn = (Fn_1%=10 + Fn_2%=10)%10;
        Fn_2 = Fn_1;
        Fn_1 = Fn;
        //sum = (sum Fn;
    }
    std::cout << sum << '\n';
    return sum % 10;
}

template <int N>
struct FibonacciLastDigit
{
	enum {RET = (FibonacciLastDigit<N-1>::RET+FibonacciLastDigit<N-2>::RET)%10};
};

template <>
struct FibonacciLastDigit<0>
{
	enum {RET = 0};
};

template <>
struct FibonacciLastDigit<1>
{
	enum {RET = 1};
};


void test_solution()
{
    for (int i = 0; i < 1000000; ++i)
    {
    	auto n = std::rand()%20; // not huge value, otherwise naive solution won't work

    	std::cout << "run " << i << ": n = " << n << '\n';
        assert(fibonacci_sum_naive(n) == fibonacci_sum_no_of(n));
    }
}


int main() {
//    long long n = 0;
//    std::cin >> n;
    std::cout << fibonacci_sum_no_of(239);
 //   std::cout << fibonacci_sum_naive(239);

//	test_solution();

//	std::cout << FibonacciLastDigit<0>::RET << '\n';
//	std::cout << FibonacciLastDigit<1>::RET << '\n';
//	std::cout << FibonacciLastDigit<2>::RET << '\n';
//	std::cout << FibonacciLastDigit<3>::RET << '\n';
//	std::cout << FibonacciLastDigit<10>::RET << '\n';
//	std::cout << FibonacciLastDigit<30>::RET << '\n';
//	std::cout << FibonacciLastDigit<60>::RET << '\n';


}
