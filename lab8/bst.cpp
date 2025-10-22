#include "bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

int rangeSum(Node *root, int L, int R) {
	
	//Base case - called on a null node -> return 0!	
	
	//Otherwise get the value of the left and right trees under you (recursive call)
	//Sum em
	//Should add node->key to the sum?
	//Return the sum!

	if(!root){
		return 0;
	}

	else{
		int sum = 0;
		if(root->key < L){
			sum += rangeSum(root->right, L, R);
		}

		else if(root->key > R){
			sum += rangeSum(root->left, L, R);
		}

		else {
			sum += rangeSum(root->left, L, R) + rangeSum(root->right, L, R) + root->key;
		}

		return sum;
	}

	return 0;
}
    
int height(Node *root){
	if(!root){
		return 0;
	}

	else if (root->right && root->left){
		int rightTree = height(root->right);
		int leftTree = height(root->left);
		if(rightTree > leftTree){
			return rightTree+1;
		}
		else{
			return leftTree+1;
		}
	}

	else if(root->right){
		return height(root->right) + 1;
	}

	else{
		return height(root->left) + 1;
	}
}

bool isBalanced(Node *root) {
	//Get the heights of the left and right subtrees - helper func?
	//Determine if this node is balanced! If not ret false!

	//Check if there are subtrees under us
	//Are they balanced?

	//If all nodes are balanced return true!

	if(!root){
		return true;
	}

	else{
		int rightHeight = height(root->right);
		int leftHeight = height(root->left);



		return isBalanced(root->right) && isBalanced(root->left) && 
		((rightHeight + 1 == leftHeight) || (leftHeight + 1 == rightHeight) || (leftHeight == rightHeight));
	}
}

/*

Given a binary tree, return the level order traversal of its nodes' values. (i.e. from left to right, level by level).


If you're given this binary tree as input:

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/
vector<vector<int>> levelOrder(Node* root) {
	vector<vector<int>> results;

	// results.push_back({root->key});

	// if(!root->left && !root->right){
	// 	return results;
	// }

	// else if(root->left){
	// 	return levelOrder(root->left);
	// }

	// else if(root->right){
	// 	return levelOrder(root->right);
	// }

	// else{
	// 	results = levelOrder(root->left);
	// }

    return results;
}

