#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

map<string, vector<pair<string, int>>> Graph_nodes = {
    {"Arad", {{"Sibiu", 140}, {"Timisoara", 118}, {"Zerind", 75}}},
    {"Bucharest", {{"Fagaras", 211}, {"Giurgiu", 90}, {"Pitesti", 101}, {"Urziceni", 85}}},
    {"Craiova", {{"Dobreta", 120}, {"Pitesti", 138}, {"Rimnicu Vilcea", 146}}},
    {"Dobreta", {{"Craiova", 120}, {"Mehadia", 75}}},
    {"Eforie", {{"Hirsova", 86}}},
    {"Fagaras", {{"Bucharest", 211}, {"Sibiu", 99}}},
    {"Giurgiu", {{"Bucharest", 90}}},
    {"Hirsova", {{"Eforie", 86}}},
    {"Iasi", {{"Neamt", 87}, {"Vaslui", 92}}},
    {"Lugoj", {{"Mehadia", 75}, {"Timisoara", 111}}},
    {"Mehadia", {{"Dobreta", 75}, {"Lugoj", 70}}},
    {"Neamt", {{"Iasi", 87}}},
    {"Oradea", {{"Sibiu", 151}, {"Zerind", 71}}},
    {"Pitesti", {{"Bucharest", 101}, {"Craiova", 138}, {"Rimnicu Vilcea", 97}}},
    {"Rimnicu Vilcea", {{"Craiova", 146}, {"Pitesti", 97}, {"Sibiu", 80}}},
    {"Sibiu", {{"Arad", 140}, {"Fagaras", 99}, {"Oradea", 151}, {"Rimnicu Vilcea", 80}}},
    {"Timisoara", {{"Arad", 118}, {"Lugoj", 111}}},
    {"Urziceni", {{"Bucharest", 85}, {"Hirsova", 98}, {"Vaslui", 142}}},
    {"Vaslui", {{"Iasi", 92}, {"Urziceni", 142}}},
    {"Zerind", {{"Arad", 75}, {"Oradea", 71}}}
};

map<string, int> H_dist = {
    {"Arad", 366}, {"Bucharest", 0}, {"Craiova", 160}, {"Dobreta", 242}, {"Eforie", 161},
    {"Fagaras", 176}, {"Giurgiu", 77}, {"Hirsova", 151}, {"Iasi", 226}, {"Lugoj", 244},
    {"Mehadia", 241}, {"Neamt", 234}, {"Oradea", 380}, {"Pitesti", 100}, {"Rimnicu Vilcea", 193},
    {"Sibiu", 253}, {"Timisoara", 329}, {"Urziceni", 80}, {"Vaslui", 199}, {"Zerind", 374}
};

int heuristic(const string &node) { return H_dist[node]; }

vector<string> a_star(const string &start, const string &goal) {
    set<string> open_set = {start}, closed_set;
    map<string, int> g{{start, 0}};
    map<string, string> parent{{start, start}};
    
    while (!open_set.empty()) {
        string current = *min_element(open_set.begin(), open_set.end(),
            [&](const string &a, const string &b) { return g[a] + heuristic(a) < g[b] + heuristic(b); });
        
        if (current == goal) break;
        open_set.erase(current);
        closed_set.insert(current);

        for (const auto &neighbor : Graph_nodes[current]) {
            string neighbor_node = neighbor.first;
            int cost = neighbor.second;
            if (closed_set.count(neighbor_node)) continue;

            int tentative_g = g[current] + cost;
            if (!open_set.count(neighbor_node) || tentative_g < g[neighbor_node]) {
                g[neighbor_node] = tentative_g;
                parent[neighbor_node] = current;
                open_set.insert(neighbor_node);
            }
        }
    }
    
    // Check if goal was reached
    if (parent.find(goal) == parent.end()) {
        cout << "No path found from " << start << " to " << goal << endl;
        return {};
    }

    vector<string> path;
    for (string at = goal; at != start; at = parent[at]) path.push_back(at);
    path.push_back(start);
    reverse(path.begin(), path.end());
    
    for (const auto &node : path) cout << node << " ";
    cout << endl;
    
    return path;
}

int main() {
    string start, goal;
    do {
        cout << "Enter Start Node: "; cin >> start;
        cout << "Enter Goal Node: "; cin >> goal;
        a_star(start, goal);
        cout << "Continue? (y/n): "; char ans; cin >> ans;
        if (ans == 'n') break;
    } while (true);
    return 0;
}
