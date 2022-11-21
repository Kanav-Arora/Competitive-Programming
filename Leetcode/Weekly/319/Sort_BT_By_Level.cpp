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
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> qi;
        qi.push(root);
        int mini_3 = 0;
        while(!qi.empty()){
            int len_size = qi.size();
            vector<int> vec_arr(len_size);
            int k_ptr=0;
            while(len_size--){
                TreeNode* node_n = qi.front();
                qi.pop();
                vec_arr[k_ptr++] = node_n->val;
                if(node_n->left)
                    qi.push(node_n->left);
                if(node_n->right)
                    qi.push(node_n->right);
            }
            mini_3+=f(vec_arr);
        } 
        return mini_3;
    }
    int f(vector<int> numing){
        int len = numing.size();
        map<int, int> mapping;
        for (int k_ptr = 0; k_ptr < len; k_ptr++)
        {
            mapping[numing[k_ptr]] = k_ptr;
        }
        sort(numing.begin(), numing.end());
        vector<bool> vis_vec(len, false);
        int soln = 0;
        for (int k_ptr = 0; k_ptr < len; k_ptr++)
        {
            if(vis_vec[k_ptr] or mapping[numing[k_ptr]] == k_ptr)
                continue;
            int j = k_ptr, cycles_count = 0;
            while(!vis_vec[j]){
                vis_vec[j] = true;
                j = mapping[numing[j]];
                cycles_count++;
            }
            if(cycles_count > 0)
                soln += cycles_count-1;
        }
        return soln;
    }
};