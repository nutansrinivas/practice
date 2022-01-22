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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
    
    std::vector<TreeNode*> generateTrees(int start, int end)
    {
        std::vector<TreeNode*> list;
        if (start > end)
        {
            list.push_back(nullptr);
            return list;
        }
        
        for (int i=start; i<=end; i++)
        {
            std::vector<TreeNode*> leftBST = generateTrees(start, i-1);
            std::vector<TreeNode*> rightBST = generateTrees(i+1, end);
            
            for (int j=0; j<leftBST.size(); j++)
            {
                for (int k=0; k<rightBST.size(); k++)
                {
                    TreeNode* node = new TreeNode(i);
                    node->left = leftBST[j];
                    node->right = rightBST[k];
                    list.push_back(node);
                }
            }
        }
        
        return list;
    }
};
