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

    TreeNode(int vertice) : v(vertice) {}

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

    size_t GetChildCount() const {
        auto count = children.size();
        for (auto&& c : children) count += c.GetChildCount();
        return count;
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
    }
    return 0;
}
