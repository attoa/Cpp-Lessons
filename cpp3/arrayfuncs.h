#pragma once

template<typename T>
size_t sizeOfArray(const T& arr)
{
	return sizeof(arr) / sizeof(arr[0]);
}

template<typename T>
void printArray(const T& arr)
{
	for (int i = 0; i < sizeOfArray(arr); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void printArray(const std::vector<T>& arr)
{
	for (T n : arr)
		std::cout << n << " ";
	std::cout << std::endl;
}