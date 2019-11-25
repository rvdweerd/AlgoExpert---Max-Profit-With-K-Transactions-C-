# algorithms / Max-Profit-With-K-Transactions-C++
AlgoExpert.io challenge.<br>
Implementation of a sample question on https://www.algoexpert.io (category: very hard)<br>

Given:<br>
a) a vector of prices on trade days, <br>
b) a maximum number of allowable transactions, k <br>
Calculate the maximum profit that can be achieved, while only holding 1 share at a time

(Own) recursive solution implemented (using &lt;algorithm>, &lt;numeric>):<br>
* Creates a subset of all possible trade combinations
* Calculates the profit of each and returns the maximum (using std::accumulate())

(Optimal AlgoExpert) solution with dynamic table implemented
