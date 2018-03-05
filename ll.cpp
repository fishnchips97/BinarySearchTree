// Erik Fisher
// CS 11 section 5569
// 4/09/2016
// Dave Harden
// ll.cpp




#include <iostream>



namespace cs_ll {
    
    template <class T>
    LL<T>::LL() {
        //std::cout << "default constructor" << endl;
        list = NULL;
    }
    
    
    
    
    
    
    template <class T>
    bool LL<T>::empty() const {
        bool TruFals = (list == NULL);
        return TruFals;
    }
    
    
    
    
    
    
    template <class T>
    typename LL<T>::size_type LL<T>::size() const {
        size_type count = 0;
        node* tempPtr = list;
        
        while (tempPtr != NULL) {
            count++;
            tempPtr = tempPtr -> next;
        }
        
        return count;
    }
    
    
    
    
    
    
    template <class T>
    void LL<T>::clear() {
        node* tempptr = list;
        while (tempptr != NULL) {
            list = list -> next;
            delete tempptr;
            tempptr = list;
        }
    }
    
    
    
    
    
    
    
    template <class T>
    void LL<T>::pop_front() {
        
        if (list == NULL) {
            throw Empty_List_Error();
        }
        
        node* tempptr = list;
        if (tempptr != NULL) {
            list = list -> next;
            delete tempptr;
            tempptr = list;
        }
    }
    
    
    
    
    
    
    
    template <class T>
    void LL<T>::push_front(const value_type& x) {
        node* newnode = new node;
        newnode -> data = x;
        node* originalStart = list;
        newnode -> next = originalStart;
        list = newnode;
        
    }
    
    
    
    
    
    
    
    template <class T>
    typename LL<T>::value_type& LL<T>::front() {
        if (list == NULL) {
            throw Empty_List_Error();
        }
        
        return list -> data;
    }
    
    
    
    
    
    
    
    template <class T>
    const typename LL<T>::value_type& LL<T>::front() const {
        
        if (list == NULL) {
            throw Empty_List_Error();
        }
        
        return list -> data;
    }
    
    
    
    
    
    
    template <class T>
    LL<T>::LL(const LL& copyMe) {
        copyList(copyMe);
    }
    
    
    
    
    
    
    template <class T>
    LL<T> LL<T>::operator=(const LL& right) {
        if (this != &right) {
            clear();
            copyList(right);
        }
        return *this;
    }
    
    
    
    
    
    
    template <class T>
    LL<T>::~LL() {
        clear();
    }
    
    
    
    
    
    /*
     template <class T>
     void LL<T>::print() const {
     node* tempPtr = list;
     while (tempPtr != NULL) {
     std::cout << tempPtr -> data << " ";
     tempPtr = tempPtr -> next;
     }
     }
     */
    
    
    
    
    
    
    //Pre: This private funciton needs two LL objects to be declared
    //Post: one list is copied to another
    template <class T>
    void LL<T>::copyList(const LL& copyMe) {
        if (copyMe.list == NULL) {
            list = NULL;
        } else {
            node* sourceptr = copyMe.list;
            node* newnode = new node;
            newnode -> data = sourceptr -> data;
            newnode -> next = NULL;
            list = newnode;
            node* newlistptr = list;
            sourceptr = sourceptr -> next;
            while (sourceptr != NULL) {
                newnode = new node;
                newnode -> data = sourceptr -> data;
                newnode -> next = NULL;
                newlistptr -> next = newnode;
                sourceptr = sourceptr -> next;
                newlistptr = newnode;
            }
        }
    }
    




    template <class T>
    void LL<T>::insert_after(iterator& position, const value_type& insertMe) {
        node* temp = new node;
        temp -> next = position.link() -> next;
        position.link() -> next = temp;
        temp -> data = insertMe;
        position++;
    }

    template <class T>
    void LL<T>::delete_after(iterator& position) {
        node* deletingNode;
        deletingNode = position.link() -> next;
        position.link() -> next = position.link() -> next -> next;
        delete deletingNode;
    }

}