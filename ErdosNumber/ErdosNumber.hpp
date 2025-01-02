#ifndef ERDOSNUMBER_HPP
#define ERDOSNUMBER_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

class ErdosNumber {

    private:

    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> erdosNumbers;

    void buildGraph(const vector<string>& publications) {

        for (const auto& pub : publications) {

            istringstream iss(pub);
            string author;
            vector<string> authors;

            while (iss >> author) {

                authors.push_back(author);

                if (graph.find(author) == graph.end()) {
                    graph[author] = vector<string>();
                }

            }
            for (size_t i = 0; i < authors.size(); ++i) {

                for (size_t j = i + 1; j < authors.size(); ++j) {
                    graph[authors[i]].push_back(authors[j]);
                    graph[authors[j]].push_back(authors[i]);
                }

            }
            
        }

    }

    void calculateErdosNumbers() {

        queue<string> q;
        q.push("ERDOS");
        erdosNumbers["ERDOS"] = 0;

        while (!q.empty()) {

            string current = q.front();
            q.pop();

            for (const auto& neighbor : graph[current]) {
                if (erdosNumbers.find(neighbor) == erdosNumbers.end()) {
                    erdosNumbers[neighbor] = erdosNumbers[current] + 1;
                    q.push(neighbor);
                }
            }

        }

    }

    vector<string> formatResults() {

        vector<string> results;

        for (const auto& pair : graph) {

            string result = pair.first;
            if (erdosNumbers.find(pair.first) != erdosNumbers.end()) {
                result += " " + to_string(erdosNumbers[pair.first]);
            }
            results.push_back(result);

        }

        sort(results.begin(), results.end());
        return results;

    }

    public:

    vector<string> calculateNumbers(vector<string> publications) {

        graph.clear();
        erdosNumbers.clear();

        buildGraph(publications);
        calculateErdosNumbers();
        return formatResults();

    }

};

#endif
