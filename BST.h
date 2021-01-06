//
// Created by misha on 06/01/2021.
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
    ~BstNode(){delete pData;}
    BstNode<T>* getLeft(){return left;}
    BstNode<T>* getRight(){return right;}

    T* getData(){return pData;}

    void setLeft(BstNode<T>* l){left=l;}
    void setRight(BstNode<T>* r){right=r;}

    void setData(const T* d){*pData = d;}
    BstNode<T>* Find(const T* d) {
        {
            if(*d == *pData)
                return this;
            else if(*d > *pData)
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
        os << *node->getData() << " ";
        Inorder(node->right, os);
    }

    BstNode<T> * min(){
        return left ? left->min() : this;
    }

    BstNode<T> * max(){
        return right ? right->max() : this;
    }

    BstNode<T>* Remove(T* target){
        if(left && *target < *pData)
            left = left->Remove(target);
        else if(right && *target > *pData)
            right = right->Remove(target);

        else {
            if (!left) {
                BstNode<T> *temp = right;
                delete this;
                return temp;
            } else if (!right) {
                BstNode<T> *temp = left;
                delete this;
                return temp;
            } else {
                BstNode<T> *successor = right->min();
                delete pData;
                pData = successor->pData;
                right = right->Remove(target);
            }
        }
        return this;

    }




};


template <class T>
class Tree{
private:
    BstNode<T> * root;
    int size;
public:
    virtual ~Tree(){
        while(root) {
            T *temp = root->getData();
            root = root->Remove(temp);
        }
        cout << "\nTree has been deleted";
    }
    void clear(){
        delete this;
    }

    Tree():root(0), size(0){}

    void insert( T* data){
        if(root == 0) {
            root = new BstNode<T>(data);
            size++;
        }
        if(!search(data))
            size++;
        root->Insert(data);

    }
    T* search(const T* target){
        BstNode<T> * retval = root->Find(target);
        return retval ? retval->getData() : 0;
    }

    T* min(){
        return root->min()->getData();
    }
    T* max()
    {
        return root->max()->getData();
    }

    void remove(T* target){
        if(root->Find(target) == 0) {
            cout << "No such element" << endl;
            return;
        }
        root = root->Remove(target);
        size--;
    }

    friend ostream & operator<<(ostream& os, const Tree & rhs)
    {
        rhs.root->Inorder(rhs.root, os);
        return os;
    }
    int get_size(){
        return size;
    }

    template<class Iterator>
            void invoke(Iterator & it, BstNode<T>* node){
        if(node == 0)
            return;
        invoke(it, node->getLeft());
        it(node);
        invoke(it, node->getRight());
    }

};


#endif //DRONES_BST_H
