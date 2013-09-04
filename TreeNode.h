// TreeNode.H - TreeNode struct declaration
// Written by Joshua Kuiros

#pragma once
#include <iostream>
using namespace std;

template<typename T>struct TreeNode
{
	TreeNode(const T& value, TreeNode<T>*left=NULL, TreeNode<T>*right=NULL)
	{
		Value = value;
		Left = left;
		Right = right;
	}
	T Value;
	TreeNode<T>*Left;
	TreeNode<T>*Right;

	bool IsLeaf()const
	{
		return Left==NULL && Right==NULL;
	}
};