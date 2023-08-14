//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
map<int,int>mp;
Node* helper(int level,int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    if(iStart > iEnd)
    {
        return NULL;
    }
    Node* root = new Node(levelOrder[level]);
    int inRoot = mp[levelOrder[level]];
    root->left = helper(2*level+1,inorder,levelOrder,iStart,inRoot-1,n);
    root->right = helper(2*level+2,inorder,levelOrder,inRoot+1,iEnd,n);
    return root;
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
//add code here.
    for(int i=0;i<n;i++)
    {
        mp[inorder[i]] = i;
    }
    return helper(0,inorder,levelOrder,iStart,iEnd,n);
}