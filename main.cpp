// main.cpp - Main entry point for Binary Serach Tree program
// Written by Joshua Kuiros

#include <iostream>
#include <string>
#include "TreeNode.h"
using namespace std;

template<typename DATA_TYPE>
void Insert(TreeNode<DATA_TYPE>*& root, const DATA_TYPE& newElement)
{
	//Base Case
	if( root == NULL )
	{
		TreeNode<DATA_TYPE>* newNode = new TreeNode<DATA_TYPE>( newElement );
		root = newNode;
	}
	else if( root->Value == newElement )
		cout << root->Value << ": Item exists in tree" << endl;
	//Recursion
	else if( root->Value > newElement )
		Insert ( root->Left, newElement );
	else 
		Insert ( root->Right, newElement );
}

template<typename DATA_TYPE>
void Print(TreeNode<DATA_TYPE>* &root)
{
	//Base Case
	if( root != NULL )
	{
		 Print(root->Left);
		 cout << root->Value << " ";
		 Print(root->Right);
	}
}

template<typename DATA_TYPE>
void Delete(TreeNode<DATA_TYPE>*& root, const DATA_TYPE& deleteData)
{
	//Base Case
	if( root == NULL )
		return;
	else if( root->Value == deleteData )
		if( root->IsLeaf() )
		{
			delete root;
			root = NULL;
		}
		else if( ( root->Left == NULL  ||  root->Right == NULL ) && (!( root->Left == NULL && root->Right == NULL ) ) )
		{
			if( root->Left == NULL )
				root = root->Right;
			else
				root = root->Left;
		}
		else
		{
			TreeNode<DATA_TYPE>* leftMostNode = root->Left;
			while( leftMostNode->Right != NULL )
				leftMostNode->Right = leftMostNode->Right;
			root->Value = leftMostNode->Value;
			Delete(root->Left, leftMostNode->Value);
		}else
		//Recursive
		if( root->Value  > deleteData )
			Delete( root->Left, deleteData );
		else
			Delete( root->Right, deleteData );
}

void main()
{
	TreeNode<string>* treeRoot = NULL;
	TreeNode<string>* currentNode = treeRoot;
	string word;
	string deleteWord;

	cout << "Enter a sentence: " << endl;
	while( cin.peek()!='\n' )
	{
		cin >> word;
		Insert(treeRoot, word);
	}

	Print(treeRoot);
	cout << endl;

	cout << "Enter a word to be deleted from the tree: " << endl;
	cin >> deleteWord;

	Delete(treeRoot, deleteWord);
	Print(treeRoot);
	cout << endl;


	system("pause");

}

