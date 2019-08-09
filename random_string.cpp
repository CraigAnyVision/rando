#include <chrono>
#include <cstring>
#include <iostream>
#include <random>
#include <string>

std::string random_string(std::string::size_type length)
{
	static const auto base64_chars =
	    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	    "abcdefghijklmnopqrstuvwxyz"
	    "0123456789+/";

	thread_local static std::mt19937 rg{std::random_device{}()};
	thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, std::strlen(base64_chars) - 2);

	std::string s;

	s.reserve(length);

	while (length--)
	{
		s += base64_chars[pick(rg)];
	}

	return s;
}

int main()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; ++i)
	{
		std::cout << random_string(10) << '\n';
	}

	auto t2 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	std::cout << "Time taken " << fp_ms.count() << " ms\n";
}
