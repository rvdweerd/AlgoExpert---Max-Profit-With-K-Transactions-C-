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

// SOLUTION 2: AlgoExpert solution; build a profit table size (t=k)x(d=prices.size()) that contains max achievable profit for each cell [t][d]
int maxProfitWithKTransactions2(std::vector<int> prices, int k)
{
	if (prices.size() < 2)
	{
		return 0;
	}
	else
	{
		std::vector<std::vector<int>> profit(k + 1, std::vector<int>(prices.size()));
		for (int i = 1; i < k + 1; i++)
		{
			for (int j = 1; j < prices.size(); j++)
			{
				int val1 = profit[i][j - 1];
				int val_t = (-prices[0] + profit[i - 1][0]);
				for (int x = 1; x < j; x++)
				{
					int p = (-prices[x] + profit[i - 1][x]);
					if (p > val_t) val_t = p;
				}
				int val2 = val_t + prices[j];
				profit[i][j] = std::max(val1, val2);
			}
		}
		return profit[k][prices.size() - 1];
	}
}

int main()
{
	//std::vector<std::vector<int>> table0(2);
	//table0.emplace_back(std::vector<int>{2});
	//table0.emplace_back(std::vector<int>{ 1,1 });
	//table0[0] = std::vector<int>{ 10,10,10,10 };

	//std::vector<std::vector<int>> table(2,std::vector<int>(4));
	//table[1][3] = 10;
	//int a = table[1][3];
	//
	//int arr[3][2] = { {1,2},{3,4},{5,6} };
	//int b = arr[2][1];
	
	
	//std::vector<int> prices = { 1,100,101,200,201,300,301,400,401,500 };
	std::vector<int> prices = { 5,11,3,50,60,90 };
	//std::vector<int> prices = { 1,10 };
	int max_profit = maxProfitWithKTransactions2(prices, 2);
	std::cout << "Max profit is: " << max_profit;

	//std::vector<int> prices = { 1,2,3,4,5 };
	//int sum = std::accumulate(prices.begin(), prices.end(), 0);
	//int sum_even = std::accumulate(prices.begin(), prices.end(), 0, [](int sum, int num) { return sum + ((num % 2 == 0) ? num : 0); });
	//int product = std::accumulate(prices.begin(), prices.end(), 1, [](int prod, int num) { return prod * num; });

	std::cin.get();
	return 0;
}