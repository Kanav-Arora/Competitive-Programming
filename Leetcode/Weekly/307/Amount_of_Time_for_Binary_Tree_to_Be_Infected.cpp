// MEDIUM

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
    This problem is similar to the traditional burn a tree problem
*/

class Solution
{
public:
    /*
        In this function we'll pass two maps parentNode and visited by reference

        parentNode maps the parent of all nodes
        visited maps all node with bool values; initially false

        This function will make a DFS call to traverse through tree
    */

    void Mapping(TreeNode *root, map<TreeNode *, TreeNode *> &parentNode, map<TreeNode *, bool> &visited)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            visited[root] = false;
            return;
        }

        visited[root] = false;
        if (root->left)
            parentNode[root->left] = root;

        if (root->right)
            parentNode[root->right] = root;

        Mapping(root->left, parentNode, visited);
        Mapping(root->right, parentNode, visited);
    }

    /*
        This function will make a DFS call to find the infected/target/start node
    */

    TreeNode *FindNode(TreeNode *root, int t)
    {
        if (root == NULL)
            return NULL;

        if (root->val == t)
            return root;

        TreeNode *lt = FindNode(root->left, t);
        TreeNode *rt = FindNode(root->right, t);

        if (lt != NULL)
            return lt;

        if (rt != NULL)
            return rt;

        return NULL;
    }

    /*
        We'll make a queue and add infected node to it

        Now infected node can infect node adjacent to it. This adjacent node can be:
        - Child nodes
        - Parent node

        Child node can be traversed from the current node and for parent node we have parentNode mapping
    */

    int amountOfTime(TreeNode *root, int start)
    {
        map<TreeNode *, TreeNode *> parentNode;
        map<TreeNode *, bool> visited;
        Mapping(root, parentNode, visited);
        parentNode[root] = NULL;

        TreeNode *target = FindNode(root, start);
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = 1;

        bool addition = false;
        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            addition = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode *frontNode = q.front();
                q.pop();
                if (frontNode->left != NULL && visited[frontNode->left] == false)
                {
                    visited[frontNode->left] = true;
                    q.push(frontNode->left);
                    addition = true;
                }

                if (frontNode->right != NULL && visited[frontNode->right] == false)
                {
                    visited[frontNode->right] = true;
                    q.push(frontNode->right);
                    addition = true;
                }

                if (parentNode[frontNode] != NULL && visited[parentNode[frontNode]] == false)
                {
                    visited[parentNode[frontNode]] = true;
                    q.push(parentNode[frontNode]);
                    addition = true;
                }
            }

            if (addition == true)
            {
                time++;
            }
        }

        return time;
    }
};