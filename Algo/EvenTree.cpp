#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

struct TreeNode
{
    int v;
    std::vector<TreeNode> children;

    TreeNode(int key) : v(key) {}

    size_t CountEdgesForEvenTree() const {
        size_t edges = 0;

        if (v == 1) {
            for (auto&& c : children) edges += c.CountEdgesForEvenTree();
            return edges;
        }
        if (children.empty() || !(allChildCount & 1))
            return edges;

        if (allChildCount & 1) {
            edges = 1;
            for (auto&& c : children) edges += c.CountEdgesForEvenTree();
        }
        return edges;
    }

    bool AddChild(int parent, int index) {
        if (parent == v) {
            children.emplace_back(TreeNode(index));
            return true;
        }
        for (auto&& c : children)
            if (c.AddChild(parent, index))
                return true;

        return false;
    }

    size_t allChildCount;

    size_t CountChild() {
        allChildCount = children.size();
        for (auto&& c : children) allChildCount += c.CountChild();
        return allChildCount;
    }

};

int main() {
    unsigned int edgesCount, verticesCount;
    if (cin >> verticesCount >> edgesCount) {

        vector<pair<int,int>> vertices;
        for (unsigned int i = 0; i < edgesCount; ++i) {
            int verticeIndex, parentIndex;
            if (cin >> verticeIndex >> parentIndex) {
                vertices.emplace_back(make_pair(verticeIndex, parentIndex));
            }
        }

        if (verticesCount & 1) {
            cout << 0 << endl;
            return 0;
        }

        sort(begin(vertices), end(vertices), [](const pair<int,int>& lhs, const pair<int,int> rhs){
           return lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first > rhs.first);
        });

        TreeNode root{1};
        while (!vertices.empty()) {
            if (!root.AddChild(vertices.back().second, vertices.back().first))
                return -1;
            vertices.pop_back();
        }

        if (root.CountChild()) {
            cout << root.CountEdgesForEvenTree() << endl;
        }
    }
    return 0;
}
