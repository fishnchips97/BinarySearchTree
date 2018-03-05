// Erik Fisher
// CS 11 section 5569
// 5/09/2016
// Dave Harden
// main


#include <iostream>
#include <string>
#include "binarytree.h"
//#include "ll.h"
using namespace std;

void printLL(const LL<int>& printMe);


int main() {
    
    
    
    binarytree tree;
    int num;
    
    cout << "enter number to insert (negative to quit): ";
    cin >> num;
    while (num >= 0) {
        tree.insert(num);
        cout << "enter number to insert (negative to quit): ";
        cin >> num;
    }
    cout << "The size is: " << tree.size() << endl;
    cout << "The number of primes is: " << tree.numPrimes() << endl;
    tree.print();
    cout << endl;
    
    
    
    LL<int> test;
    test = tree.toLL();
    cout << endl;
    cout << "Linked List conversion: " << endl;
    printLL(test);
    
    binarytree tree2(tree);
    //tree2 = tree;
    
    tree.insert(100);
    cout << "tree: ";
    tree.print();
    cout << endl;
    cout << "tree2: ";
    tree2.print();
    
    
    
    cout << endl;
    cout << "tree's size:" << tree.size() << endl;
    cout << "tree2's size:" << tree2.size() << endl;
    
    
    return 0;
    
    
    
}


void printLL(const LL<int>& printMe) {
    for (LL<int>::const_iterator i = printMe.begin(); i != printMe.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}