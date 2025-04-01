/*
given a binary tree, collect the nodes while doing this:
collect and remove all leaves , repeat until tree is empty

    1
   / \
  2   3
 / \     
4   5  

return: [[4,5,3],[2],[1]]

    1
   / \
  2   3
 /
4 

return: [[4,3],[2],[1]]

constraints:
nodes -> some number
node.val - > some number


idea:
while the tree is not empty
    traverse to every node in tree, at each node, check uif a leaf
        if yes a leaf
            remove node from tree and add to list
        if no
            skip

        add list to list of lists

    
return list of all nodes


instead:
dfs down the tree, in each recursive call pass in the height, 


*/


#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from a vector representation
TreeNode* buildTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Process left child
        if (i < values.size() && values[i] != -1) {
            curr->left = new TreeNode(values[i]);
            q.push(curr->left);
        }
        i++;

        // Process right child
        if (i < values.size() && values[i] != -1) {
            curr->right = new TreeNode(values[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Helper function to print tree (level-order)
void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << (curr ? to_string(curr->val) : "null") << " ";
        if (curr) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout << endl;
}




vector<vector<int>> remove_leaves_until_empty(vector<int> tree)
{
    TreeNode* root = buildTree(tree);
    vector<vector<int>> result;
    
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return -1;
        
        int height = max(dfs(node->left), dfs(node->right)) + 1;
        
        if (height == result.size()) 
            result.push_back({});
        
        result[height].push_back(node->val);
        return height;
    };
    
    dfs(root);
    return result;
}




void test(vector<int> tree, vector<vector<int>> expected)
{
    vector<vector<int>> pred = remove_leaves_until_empty(tree);

    if(pred == expected)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";

}


int main()
{
    test({1, 2, 3, 4, 5, -1, -1}, {{4,5,3},{2},{1}});

    return 0;
}