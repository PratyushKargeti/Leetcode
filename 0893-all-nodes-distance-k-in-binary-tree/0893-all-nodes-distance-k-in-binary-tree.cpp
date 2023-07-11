/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> parent;
        q.push(root);

        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front->left){
                parent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                parent[front->right] = front;
                q.push(front->right);
            }
        }

        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;
        int cnt=0;
        while(!q.empty()){
            if(cnt==k) break;
            cnt++;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*front=q.front();
                q.pop();
                if(front->left  &&  !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right  &&  !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(parent[front]  &&  !visited[ parent[front] ]){
                    q.push( parent[front] );
                    visited[parent[front]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            ans.push_back( front->val );
        }
        return ans;
    }
//     Explaination
// Create a queue named q to perform level order traversal of the tree.
// Create an unordered map named parent to store the parent-child relationships of nodes in the tree.
// Push the root node of the tree into the queue.
// Perform a level order traversal using the queue until it becomes empty:
// a. Dequeue the front node front from the queue.
// b. If front has a left child, store the parent-child relationship in the parent map and enqueue the left child.
// c. If front has a right child, store the parent-child relationship in the parent map and enqueue the right child.
// Create an unordered map named visited to keep track of visited nodes.
// Push the target node into the queue and mark it as visited in the visited map.
// Initialize a count cnt to 0 to track the distance from the target node.
// While the queue is not empty and the count cnt is less than or equal to k:
// a. Increment cnt.
// b. Get the size of the queue and iterate size times:
// Dequeue the front node front from the queue.
// If front has a left child and it has not been visited before, enqueue it and mark it as visited.
// If front has a right child and it has not been visited before, enqueue it and mark it as visited.
// If front has a parent (accessed using parent[front]) and it has not been visited before, enqueue it and mark it as visited.
// Create a vector named ans to store the values of the nodes at distance k.
// While the queue is not empty, dequeue the front node front from the queue and push its value into the ans vector.
// Return the ans vector containing the values of the nodes at distance k from the target node.
// By following this approach, we can find the nodes at distance k from the target node in the binary tree.

// Complexity
// Time complexity: O(N), We are just traversing the nodes.

// Space complexity: O(N), We use unordered_map to store the parent.
};