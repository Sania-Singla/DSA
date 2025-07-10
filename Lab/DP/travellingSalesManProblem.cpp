#include <iostream>
#include <climits>
#include <cstring> // For memset

using namespace std;

const int N = 4;
const int INF = 1e9;

int graph[N][N] = {
    {0, 5, 9, 8},
    {5, 0, 7, 6},
    {9, 7, 0, 4},
    {8, 6, 4, 0}};

int dp[1 << N][N]; // DP table for memoization

int tsp(int visited, int current_city)
{
    // Base case: all cities visited, return to start
    if (visited == (1 << N) - 1)
    {
        return graph[current_city][0];
    }

    // Return memoized result if available
    if (dp[visited][current_city] != -1)
    {
        return dp[visited][current_city];
    }

    int min_cost = INF;

    // Try visiting each unvisited city
    for (int next_city = 0; next_city < N; next_city++)
    {
        if (!(visited & (1 << next_city)))
        {
            int new_cost = graph[current_city][next_city] + tsp(visited | (1 << next_city), next_city);
            min_cost = min(min_cost, new_cost);
        }
    }

    return dp[visited][current_city] = min_cost;
}

int main()
{
    // Initialize DP table with -1 (uncomputed)
    memset(dp, -1, sizeof(dp));

    // Start with city 0 visited, at city 0
    cout << "Minimum TSP cost: " << tsp(1, 0) << endl;

    return 0;
}