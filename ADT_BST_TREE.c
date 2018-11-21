#include "ADT_BST_TREE.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

BST_TREE* create_bst(){
	BST_TREE* bst_tree = (BST_TREE*)malloc(sizeof(BST_TREE));
	if(!bst_tree) return NULL;	
	bst_tree->root = NULL;
	bst_tree->count = 0;
	return bst_tree;
}

bool insert(BST_TREE* tree, int data){
	T_NODE* newRoot;
	newRoot = add_bst(tree->root, data);
	
	if( newRoot == NULL){
		return false;
	}
	else {
		tree->root = newRoot;
		(tree->count)++;
	}
	return true;
}
bool deletion(BST_TREE* tree, int data){
	bool success;
	T_NODE* new_root;
	new_root = delete_bst(tree->root, data, &success);
	if(success){
		tree->root = new_root;		
		tree->count--;
		if(tree->count==0) tree->root=NULL;
	}	
	return success;
}

T_NODE* add_bst(T_NODE* root, int data){
	if(root == NULL){
		T_NODE* newPtr = (T_NODE*)malloc(sizeof(T_NODE));
		newPtr->left = NULL;
		newPtr->right = NULL;
		newPtr->data = data;

		return newPtr;
	}
	
	if(data< (root->data)){
		root->left = add_bst(root->left, data);
		
		return root;
	}

	else{
		root->right = add_bst(root->right, data);
	
		return root;
	}
}

T_NODE* delete_bst(T_NODE* root, int data, bool* success){
	T_NODE* newroot;
	T_NODE* deleted_node;
	T_NODE* search;

	if(root == NULL){
		*success = false;
		return NULL;
	}
	if(data<(root->data)){
		root->left = delete_bst(root->left, data, success);
	}else if(data>(root->data)){
		root->right = delete_bst(root->right, data, success); //제거노드 찾아가기
	}else{//제거 root 도착 CASE 1 왼쪽이 없다
			deleted_node = root;
			if(root->left == NULL){
			newroot = root -> right;
			free(deleted_node);
			*success = true;
			return newroot;
	}else//CASE 2 오른쪽이 없다
		if(root->right == NULL){
		newroot= root->left;
		free(deleted_node);
		*success = true;
		return newroot;
	}else{//CASE 3 i have two slave
		search = root->left;
		while(search->right!=NULL){
			search = search -> right;
		}
		root->data = search->data; // 새 보스가 된다
		root->left = delete_bst(root->left,search->data,success);
		//내자리 지워줘
		} 
	}
		return root;
}

void traverse_preorder(T_NODE* root){
	if(root != NULL){
		printf("%d ", root->data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
}

void traverse_postorder(T_NODE* root){
	if(root != NULL){
		traverse_postorder(root->left);
		traverse_postorder(root->right);
		printf("%d ", root->data);
	}
}

void traverse_inorder(T_NODE* root){
	if(root != NULL){
		traverse_inorder(root->left);
		printf("%d ", root->data);
		traverse_inorder(root->right);
	}
}

T_NODE* find_smallest_node(T_NODE* root){
	if(root->left == NULL) 	return root;
	else return find_smallest_node(root->left);
}

T_NODE* find_largest_node(T_NODE* root){
	if(root->right == NULL) return root;
	else return find_largest_node(root->right);
}

T_NODE* search_bst(T_NODE* root, int key){
	if(root == NULL) return NULL;
	if(key < root->data) return search_bst(root->left, key);
	else if(key > root->data) return search_bst(root->right, key);
	else return root;
}






BST_TREE* search_traverse_preorder(BST_TREE* newtree, BST_TREE* tree, T_NODE* root){
	int temp;

	if(root != NULL){
		temp = root->data;
		insert(newtree, temp);
		search_traverse_preorder(newtree, tree, root->left);
		search_traverse_preorder(newtree, tree, root->right);
	}
	return newtree;
}


BST_TREE* copy_tree(BST_TREE* tree){
	BST_TREE* new_tree;
	new_tree = create_bst();

	if(!new_tree) return NULL;
	new_tree = search_traverse_preorder(new_tree,tree,tree->root);
	
	return new_tree;

}


BST_TREE* search_traverse_postorder(BST_TREE* newtree, BST_TREE* tree, T_NODE* root){
	int temp;
	BST_TREE* temp_tree;	
	temp_tree = create_bst();
	if(root != NULL){
		search_traverse_postorder(newtree, tree, root->left);
		search_traverse_postorder(newtree, tree, root->right);
		temp = root->data;
		insert(temp_tree,temp);
	}
	return newtree;
}


BST_TREE* copy_tree2(BST_TREE* tree){
	BST_TREE* new_tree;
	new_tree = create_bst();

	if(!new_tree) return NULL;
	new_tree = search_traverse_postorder(new_tree,tree,tree->root);
	return new_tree;
}








