#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    
    vector<int> parent(n);
    vector<int> size(n, 1);
    iota(parent.begin(), parent.end(), 0);

    // Sem compressão de caminho
    // O(log N)
    auto find = [&](int x) -> int {
        while (x != parent[x]) {
            x = parent[x];
        }

        return x;
    };

    // Com compressão de caminho
    // O(α(N))
    auto find = [&](int a) -> int {
        int root = a;

        // Encontra a raiz
        while (root != parent[root])
            root = parent[root];

        // Comprime o caminho
        while (a != root) {
            int next = parent[a];
            parent[a] = root;
            a = next;
        }

        return root;
    };

    // Sem compressão de caminho O(log N)
    // Com compressão de caminho O(α(N))
    auto merge = [&](int a, int b) -> void {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        // Union by size
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    };

    return 0;
}