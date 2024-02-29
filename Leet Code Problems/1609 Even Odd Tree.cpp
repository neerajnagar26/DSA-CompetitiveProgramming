# Intuition
The problem requires checking if a given binary tree is an even-odd tree, where levels alternate between strictly increasing odd integers and strictly decreasing even integers.
# Approach
To solve the problem, I implemented a breadth-first search (BFS) approach using a queue. At each level of the tree, I maintain a vector to store the values encountered. I then verify whether the values in the vector satisfy the required conditions based on the current level of the tree:

For odd levels, the values must be strictly increasing and odd.
For even levels, the values must be strictly decreasing and even.

I used a flag to indicate the level and alternated between odd and even levels while traversing the tree. If at any level, the values in the vector do not meet the conditions, the function returns false. Otherwise, it continues until the entire tree is traversed.

# Complexity
- Time complexity:O(N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(N)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
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
    // Function to check if the given vector follows the required pattern based on the current level
    bool check_vec(vector<int> vec, int level) {
        int n = vec.size();
        if (n < 1)
            return true;

        // Odd level condition
        if (level % 2 != 0) {
            if (vec[0] % 2 != 0) // First element should be odd
                return false;
            for (int i = 1; i < n; i++) {
                // Values should be strictly decreasing and odd
                if (vec[i] >= vec[i - 1] || vec[i] % 2 != 0)
                    return false;
            }
        } else { // Even level condition
            if (vec[0] % 2 == 0) // First element should be even
                return false;
            for (int i = 1; i < n; i++) {
                // Values should be strictly increasing and even
                if (vec[i] <= vec[i - 1] || vec[i] % 2 == 0)
                    return false;
            }
        }

        return true;
    }

    // Main function to check if the given binary tree is an even-odd tree
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr)
            return true;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr); // Use nullptr as a level delimiter

        int level = 0;
        vector<int> vec;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                // Check the validity of the vector for the current level
                if (check_vec(vec, level) == false)
                    return false;

                vec.clear(); // Clear the vector for the next level
                level++; // Move to the next level
                if (!q.empty())
                    q.push(nullptr); // Push level delimiter if the queue is not empty
            } else {
                vec.push_back(node->val); // Add current node's value to the vector
                if (node->left)
                    q.push(node->left); // Enqueue left child
                if (node->right)
                    q.push(node->right); // Enqueue right child
            }
        }
        return true; // If the tree satisfies the conditions
    }
};

```