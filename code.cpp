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
    vector<TreeNode*>res;
    void forest(TreeNode* root, vector<int>& to_delete)
    {
        if(root!=NULL)
        {
            if(find(to_delete.begin(),to_delete.end(),root->val)!=to_delete.end())
            {
                forest(root->left,to_delete);
                forest(root->right,to_delete);
            }
            else
            {
                queue<TreeNode*>s;
                s.push(root);
                while(!s.empty())
                {
                    int size=s.size();
                    for(int i=0;i<size;i++)
                    {
                        TreeNode* node=s.front();
                        s.pop();
                        if(node->left!=NULL)
                        {
            if(find(to_delete.begin(),to_delete.end(),node->left->val)!=to_delete.end())
            {
                forest(node->left->left,to_delete);
                forest(node->left->right,to_delete);
                node->left=NULL;
            }
                            else
                            {
                                s.push(node->left);
                            }
                        }
                        if(node->right!=NULL)
                        {
            if(find(to_delete.begin(),to_delete.end(),node->right->val)!=to_delete.end())
            {
                forest(node->right->left,to_delete);
                forest(node->right->right,to_delete);
                node->right=NULL;
            }
                            else
                            {
                                s.push(node->right);
                            }
                        }
                    }
                }
                res.push_back(root);
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       forest(root,to_delete);
        return res;
    }
};
