#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        queue<pair<TreeNode *, pair<TreeNode *, int>>> q;
        q.push({NULL, {root, root->val}});

        while (!q.empty())
        {
            int size = q.size();
            vector<pair<TreeNode *, pair<TreeNode *, int>>> vec;
            int sum = 0;
            while (size--)
            {
                auto front = q.front();
                q.pop();
                if (front.second.first->left)
                    q.push({front.second.first, {front.second.first->left, front.second.first->left->val}});
                if (front.second.first->right)
                    q.push({front.second.first, {front.second.first->right, front.second.first->right->val}});
                sum += front.second.second;
                vec.push_back(front);
            }

            int s = vec.size();
            for (int i = 0; i < s; i++)
            {
                if (vec[i].first == NULL)
                {
                    vec[i].second.first->val = 0;
                    continue;
                }
                int temp = sum;
                temp -= vec[i].second.second;
                for (int j = 0; j < s; j++)
                {
                    if (i == j)
                        continue;
                    if (vec[i].first == vec[j].first)
                        temp -= vec[j].second.second;
                }
                vec[i].second.first->val = temp;
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}