#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

// SOLUTION 1: Create a subset (using recursion) of all possible trade combinations, calculate profit of each and select the maximum
void RecTransactionSet(std::vector<std::pair<int, int>> sofar, std::vector<int>& prices, int k, int index_start, std::vector< std::vector< std::pair<int, int> > >* pVec)
{
	int L = prices.size();

	for (int i = 0 + index_start; i <= L - 2*k+1 ; i++)
	{
		for (int l = L - k - i ; l > 0; l--)
		{
			sofar.emplace_back(std::pair<int, int>{ i, i + l });
			if ( k > 1 )
			{
				RecTransactionSet(sofar, prices, k-1, i+l, pVec);
			}
			else
			{
				pVec->emplace_back(sofar);
			}
			sofar.erase(sofar.end() - 1);
		}
	}
}
int CalcProfit(std::vector<int> prices, std::vector< std::vector< std::pair<int, int> > >* pVec)
{
	int max_profit = std::accumulate(pVec->begin(), pVec->end(), 0, 
	[&prices](int m, std::vector< std::pair<int, int>> v) 
	{
		int profit = 0;
		for (std::pair<int, int> p : v)
		{
			profit += prices[p.second] - prices[p.first];
			std::cout << "("<<p.first << "," << p.second << "),";
		}
		std::cout << profit<<"\n";
		if (profit > m)
		{
			return profit;
		}
		else
		{
			return m;
		}
	});
	return max_profit;
}
int maxProfitWithKTransactions(std::vector<int> prices, int k)
{
	if (prices.size() < 2)
	{
		return 0;
	}
	else
	{
		int i = std::min(int(prices.size()-1),k);
		auto pVec = new std::vector<std::vector<std::pair<int,int>>>;

		RecTransactionSet(std::vector<std::pair<int, int>>(), prices, i, 0, pVec);
		int maxprofit = CalcProfit(prices, pVec);
		delete pVec;
		return maxprofit;
	}
}

// SOLUTION 2: AlgoExpert solution


int main()
{
	//std::vector<int> prices = { 1,100,101,200,201,300,301,400,401,500 };
	//std::vector<int> prices = { 5,11,3,50,60,90 };
	std::vector<int> prices = { 1,10 };
	int max_profit = maxProfitWithKTransactions(prices, 3);
	std::cout << "Max profit is: " << max_profit;

	//std::vector<int> prices = { 1,2,3,4,5 };
	//int sum = std::accumulate(prices.begin(), prices.end(), 0);
	//int sum_even = std::accumulate(prices.begin(), prices.end(), 0, [](int sum, int num) { return sum + ((num % 2 == 0) ? num : 0); });
	//int product = std::accumulate(prices.begin(), prices.end(), 1, [](int prod, int num) { return prod * num; });

	std::cin.get();
	return 0;
}