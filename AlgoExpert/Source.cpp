#include "Algo1_maxprofit.h"
#include "Algo2_largestrange.h"

void Algo1_maxprofit()
{
	std::vector<int> prices = { 1,100,101,200,201,300,301,400,401,500 };
	//std::vector<int> prices = { 5,11,3,50,60,90 };
	//std::vector<int> prices = { 1,10 };
	int max_profit = maxProfitWithKTransactions(prices, 1);
	std::cout << "Max profit is: " << max_profit;

	//std::vector<int> prices = { 1,2,3,4,5 };
	//int sum = std::accumulate(prices.begin(), prices.end(), 0);
	//int sum_even = std::accumulate(prices.begin(), prices.end(), 0, [](int sum, int num) { return sum + ((num % 2 == 0) ? num : 0); });
	//int product = std::accumulate(prices.begin(), prices.end(), 1, [](int prod, int num) { return prod * num; });
	return;
}

void Algo2_largestrange()
{
	std::vector<int> array = { 19,-1,18,17,2,10,3,12,5,16,4,11,8,7,6,15,12,12,2,1,6,13,14 };
	std::vector<int> answer = largestRange(array);
	for (int v : answer)
	{
		std::cout << v << ",";
	}
}
int main()
{
	//Algo1_maxprofit();
	Algo2_largestrange();

	std::cin.get();
	return 0;
}