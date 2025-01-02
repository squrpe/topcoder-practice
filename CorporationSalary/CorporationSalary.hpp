#ifndef CORPORATION_SALARY_HPP
#define CORPORATION_SALARY_HPP

#include <vector>
#include <string>

using namespace std;

class CorporationSalary {

private:

    vector<vector<bool>> graph;
    vector<long long> memo;

    long long dfs(int employee) {
        if (memo[employee] != -1) {
            return memo[employee];
        }

        long long salary = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (graph[employee][i]) {
                salary += dfs(i);
            }
        }

        if (salary == 0) {
            salary = 1;
        }

        memo[employee] = salary;
        return salary;
    }

public:

    long long totalSalary(vector<string> relations) {

        int n = relations.size();
        graph.assign(n, vector<bool>(n, false));
        memo.assign(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = (relations[i][j] == 'Y');
            }
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += dfs(i);
        }

        return total;

    }
    
};

#endif