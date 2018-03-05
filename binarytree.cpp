// Erik Fisher
// CS 11 section 5569
// 5/09/2016
// Dave Harden
// binarytree.cpp



// Here is the file binarytree.cpp

#include <iostream>
#include "binarytree.h"
using namespace std;



binarytree::binarytree() {
    root = nullptr;
    mSize = 0;
}






void binarytree::print() {
    print_aux(root);
}






void binarytree::insert(int item) {
    insert_aux(root, item);
    mSize++;
}






binarytree::size_type binarytree::size() {
    return mSize;
}






int binarytree::find(int target, bool& found){
    return find_aux(root, target, found);
}






void binarytree::del(int target, bool& found) {
    del_aux(root, target, found);
    if (found) {
        mSize--;
    }
}






void del_aux(binarytree::treenode*& root,
             int target,
             bool& found) {
    
    if (root == nullptr) {
        found = false;
    } else if (target < root -> data) {
        del_aux(root -> left, target, found);
    } else if (target > root -> data) {
        del_aux(root -> right, target, found);
    } else if (root -> left == nullptr) {
        binarytree::treenode* tempptr = root;
        root = root -> right;
        delete tempptr;
        found = true;
    } else {
        int max;
        remove_max(root -> left, max);
        root -> data = max;
        found = true;
    }
}





// pre: root != nullptr

void remove_max(binarytree::treenode*& root, int& max) {
    if (root -> right == nullptr) {
        max = root -> data;
        binarytree::treenode* tempptr = root;
        root = root -> left;
        delete tempptr;
    } else {
        remove_max(root -> right, max);
    }
    
}






int find_aux(binarytree::treenode* root,
             int target,
             bool& found) {
    
    if (root == nullptr) {
        found = false;
        return 0;
    } else if (target == root -> data) {
        found = true;
        return root -> data;
    } else if (target < root -> data) {
        return find_aux(root -> left, target, found);
    } else {
        return find_aux(root -> right, target, found);
    }
}






void insert_aux(binarytree::treenode*& root, int item) {
    if (root == nullptr) {
        // root = new treenode(item, nullptr, nullptr);
        root = new binarytree::treenode;
        root -> data = item;
        root -> left = nullptr;
        root -> right = nullptr;
    } else if (item <= root -> data) {
        insert_aux(root -> left, item);
    } else {
        insert_aux(root -> right, item);
    }
}






void print_aux(binarytree::treenode* root) {
    if (root != nullptr) {
        print_aux(root -> left);
        cout << root -> data << " ";
        print_aux(root -> right);
    }
}






binarytree::size_type binarytree::numPrimes() {
    
    return primeCount_aux(root);
}






bool isPrime(int possiblePrime) {
    bool trueFalse = true;
    
    
    
    for (int i = 2; (i < possiblePrime && trueFalse == true); i++) {
        if (possiblePrime % i == 0) {
            trueFalse = false;
        }
    }
    
    return trueFalse;
}






binarytree::size_type primeCount_aux(binarytree::treenode* root){
    int primes = 0;
    if (root != nullptr && isPrime(root -> data) ) {
        primes = 1;
    }
    
    if (root == nullptr) {
        return primes; // this will be 0
        
    } else {
        
        return primeCount_aux(root -> left)
        + primeCount_aux(root -> right)
        + primes;
    }
}






LL<int> binarytree::toLL() {
    LL<int> LList;
    toLL_aux(root, LList);
    
    return LList;
}






void toLL_aux(binarytree::treenode* root, LL<int>& LList) {
    if (root != nullptr) {
        
        toLL_aux(root -> right, LList);
        LList.push_front(root -> data);
        toLL_aux(root -> left, LList);
        
    }
}






binarytree::binarytree(const binarytree& copyMe) {
    root = nullptr;
    mSize = 0;
    copy(copyMe);
    
}






void binarytree::copy(const binarytree& copyMe) {
    copy_aux(*this, copyMe.root);
    
}






void copy_aux(binarytree& newTree, binarytree::treenode* copyMe) {
    if (copyMe != nullptr) {
        
        copy_aux(newTree, copyMe -> right);
        newTree.insert(copyMe -> data);
        copy_aux(newTree, copyMe -> left);
        
    }
    
}






binarytree::~binarytree() {
    clear();
}






void binarytree::clear() {
    clear_aux(root);
}






void clear_aux(binarytree::treenode* root) {
    // based off book's algorithm
    if (root != nullptr) {
        if (root->left != nullptr) {
            clear_aux(root->left);
        }
        
        if (root->right != nullptr) {
            clear_aux(root->right);
        }
        delete root;
    }
    
    
    
}







binarytree binarytree::operator=(const binarytree& right) {
    if (this != &right) {
        clear();
        copy(right);
    }
    return *this;
    
}