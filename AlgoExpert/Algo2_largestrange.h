#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> largestRange(std::vector<int> array)
{
	//sort;
	std::sort(array.begin(), array.end());

	//remove duplicates using algorithm lib *
	auto last = std::unique(array.begin(), array.end());
	array.erase(last, array.end());

	// extract subsets
	std::vector<std::vector<int >> vecextr = { {} };
	size_t i = 0;
	for (auto it = array.begin(); it != array.end(); ++it)
	{
		if (vecextr[i].size() != 0 && *it != vecextr[i].back() + 1)
		{
			i++;
			vecextr.push_back({});
		}
		vecextr[i].push_back(*it);
	}

	//find largest
	size_t nLargest = 0;
	size_t indexOfLargest;
	for (auto i = 0; i < vecextr.size(); i++)
	{
		size_t vecsize = vecextr[i].size();
		if (vecsize > nLargest)
		{
			nLargest = vecsize;
			indexOfLargest = i;
		}
	}

	//return
	return { vecextr[indexOfLargest][0], vecextr[indexOfLargest].back() };

	// print results
	/*
	std::cout << "Largest consecutive subset is";
	for (int v : vecextr[indexOfLargest])
	{
		std::cout << v << ",";
	}

	std::vector<int> answer = { vecextr[indexOfLargest][0], vecextr[indexOfLargest].back() };
	std::cout << "\nAnswer:";
	for (int v : answer)
	{
		std::cout << v << ",";
	}
	*/
}