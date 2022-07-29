/*
Range Sum of BST
https://leetcode.com/problems/range-sum-of-bst/
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        if(root == nullptr) return 0;
        if(root->val >= low && root->val <= high) {     // 중간 범위일 경우
            sum += root->val;                           // 자기 자신의 값을 더한다
            sum += rangeSumBST(root->left, low, high);  // 왼쪽 자식을 탐색한다
            sum += rangeSumBST(root->right, low, high); // 오른쪽 자식을 탐색한다
        }
        else if(root->val > high) sum += rangeSumBST(root->left, low, high); // high보다 높을 경우 왼쪽 자식 탐색   
        else if(root->val < low) sum += rangeSumBST(root->right, low, high);    // low보다 작을 경우 오른쪽 자식 탐색
        return sum;
    }
};