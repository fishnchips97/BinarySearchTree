// Erik Fisher
// CS 11 section 5569
// 5/09/2016
// Dave Harden
// binarytree.h


// Here is the file binarytree.h

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstdlib>	// for size_t
#include "ll.h"
using namespace cs_ll;

class binarytree {
    
public:
    typedef std::size_t size_type;
    binarytree();
    ~binarytree();
    void insert(int item);
    void print();
    size_type size();
    int find(int target, bool& found);
    void del(int target, bool& found);
    size_type numPrimes();
    LL<int> toLL();
    binarytree(const binarytree& copyMe);
    binarytree operator=(const binarytree& right);
    
    
    
private:
    struct treenode {
        int data;
        treenode* left;
        treenode* right;
    };
    
    size_type mSize;
    treenode* root;
    void copy(const binarytree& copyMe);
    void clear();
public:
    friend void insert_aux(treenode*& root, int item);
    friend void print_aux(treenode* root);
    friend size_type primeCount_aux(treenode* root);
    friend int find_aux(treenode* root, int target, bool& found);
    friend void del_aux(treenode*& root, int target, bool& found);
    friend void remove_max(treenode*& root, int& max);
    friend void toLL_aux(treenode* root, LL<int>& LList);
    friend void copy_aux(binarytree& newTree, treenode* copyMe);
    friend void clear_aux(treenode* root);
    friend bool isPrime(int possiblePrime);
    
};





#endif /* BINARYTREE_H */
