#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, std::string>> entries;

    for (int i = 0; i < m; i++) {
        int k;
        std::string s;
        std::cin >> k >> s;
        entries.push_back({k, s});
    }

    for (int i = 1; i <= n; i++) {
        std::string out = "";

        for (auto entry : entries) 
            if (i % entry.first == 0) 
                out += entry.second;
        

        if (out == "") std::cout << i << '\n';
        else std::cout << out << '\n';
    }
}
