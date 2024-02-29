'''
Explanation:

1. The function `findBottomLeftValue` takes a pointer to the root of a binary tree as its argument.

2. It checks if the root has no left and right children. If it doesn't, it means the root itself is the only node in the tree, and it returns the value of the root.

3. If the tree is not empty, it initializes a queue to perform a level order traversal. The idea of the level order traversal is to visit each level of the tree from right to left.

4. A pointer `last` is initialized to store the leftmost node of the last row of the tree. This will be updated during the traversal.

5. The root node is enqueued to start the traversal.

6. The while loop continues until the queue is empty, which means all nodes have been visited.

7. Within the loop, the front node of the queue is dequeued and stored in the variable `last`.

8. If the dequeued node has a right child, it is enqueued before the left child. This ensures that we traverse from right to left within each level.

9. After the traversal is complete, the value of the leftmost node of the last row is returned.

This code effectively finds the leftmost value in the last row of the binary tree using a level order traversal technique.
'''
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) 
    {   
        // Check if the root has no left and right children,
        // if so, return the value of the root itself.
        if(root->left==NULL && root->right==NULL)
            return root->val;

        // Create a queue to perform level order traversal.
        queue<TreeNode*> q;

        // Initialize a pointer to store the leftmost node of the last row.
        TreeNode *last;

        // Enqueue the root node to start the traversal.
        q.push(root);

        // Begin the level order traversal.
        while(!q.empty())
        {
            // Pop the front element from the queue.
            last=q.front();
            q.pop();

            // Enqueue right child before left child, if they exist.
            if(last->right)
                q.push(last->right);
            if(last->left)
                q.push(last->left);
        }
        
        // Return the value of the leftmost node of the last row.
        return last->val; 
    }
};
