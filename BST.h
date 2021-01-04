//
// Created by misha on 04/01/2021.
//

#ifndef DRONES_BST_H
#define DRONES_BST_H
#include <iostream>
using namespace std;

template<class T>
class BstNode
{
    BstNode<T> *left, *right;
    T* pData;
    BstNode(const BstNode<T>&);
    BstNode<T>& operator=(const BstNode<T>&);
public:
    BstNode():left(0), right(0), pData(new T){}
    BstNode(T* pd)
            :left(0),right(0)
    {pData = new T; *pData = *pd;}
    ~BstNode(){delete left; delete right; delete pData;}
    BstNode<T>* getLeft(){return left;}
    BstNode<T>* getRight(){return right;}

    T* getData(){return pData;}

    void setLeft(BstNode<T>* l){left=l;}
    void setRight(BstNode<T>* r){right=r;}

    void setData(const T& d){*pData = d;}
    BstNode<T>* Find(const T& d) {
        {
            if(d == *pData)
                return this;
            else if(d > *pData)
                return right ? right->Find(d) : 0;
            else
                return left ? left->Find(d) : 0;
        }
    }
    void Insert(T* data) {
        if(*data == *pData)
            *pData = *data;
        if(*data < *pData)
        {
            if(left)
                left->Insert(data);
            else
                left = new BstNode<T>(data);
        }
        if(*data > *pData)
        {
            if(right)
                right->Insert(data);
            else
                right = new BstNode<T>(data);
        }

    }

    void Inorder(BstNode<T> * node, ostream & os)
    {
        if(node == NULL)
            return;
        Inorder(node->left, os);
        os << *node->getData();
        Inorder(node->right, os);
    }




};


template <class T>
class Tree{
public:
    BstNode<T> * root;

    Tree(){
        root = 0;
    }
    void insert( T* data){
        if(root == 0)
            root = new BstNode<T>(data);

        root->Insert(data);

    }

    friend ostream & operator<<(ostream& os, const Tree & rhs)
    {
        rhs.root->Inorder(rhs.root, os);
        return os;
    }
};

#endif //DRONES_BST_H
