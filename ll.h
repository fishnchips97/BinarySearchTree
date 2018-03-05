// Erik Fisher
// CS 11 section 5569
// 4/09/2016
// Dave Harden
// ll.h




#ifndef ll_h
#define ll_h

#include <cstdlib>


namespace cs_ll {
    
    template <class T>
    class LL {
    public:
        class Empty_List_Error {};
        typedef size_t size_type;
        typedef T value_type;
        LL();
        bool empty() const;
        size_type size() const;
        void clear();
        void pop_front();
        void push_front(const value_type& x);
        value_type& front();
        const value_type& front() const;
        LL(const LL& copyMe);
        LL operator=(const LL& right);
        ~LL();
        //void print() const;
        
    private:
        void copyList(const LL& copyMe);
        struct node {
            value_type data;
            node* next;
        };
        node* list;
        
    public:
        class iterator {
        public:
            iterator(node* initial = NULL) {
                current = initial;
            }
            
            value_type& operator*() const {
                return current -> data;
            }
            
            iterator& operator++() {
                current = current -> next;
                return *this;
            }
            
            iterator operator++(int) {
                iterator original(current);
                current = current -> next;
                return original;
            }
            
            bool operator==(iterator other) const {
                return current == other.current;
            }
            
            bool operator !=(iterator other) const {
                return current != other.current;
            }
            
            const node* link() const {
                return current;
            }
            
            node*& link() {
                return current;
            }
            
            
        private:
            node* current;
        };
        
    public:
        class const_iterator  {
        public:
            const_iterator(const node* initial = NULL) {
                current = initial;
            }
            
            const value_type& operator*() const {
                return current -> data;
            }
            
            const_iterator& operator++() {
                current = current -> next;
                return *this;
            }
            
            const_iterator operator++(int) {
                const_iterator original(current);
                current = current -> next;
                return original;
            }
            
            bool operator==(const const_iterator other) const {
                return current == other.current;
            }
            
            bool operator !=(const const_iterator other) const {
                return current != other.current;
            }
            
            const node* link() const {
                return current;
            }
            
            node*& link() {
                return current;
            }
        private:
            const node* current;
        };
        
        iterator begin() {
            return iterator(list);
        }
        
        iterator end() {
            return iterator(NULL);
        }
        
        const_iterator begin() const {
            return const_iterator(list);
        }
        
        const_iterator end() const {
            return const_iterator(NULL);
        }
        
    public:
        void insert_after(iterator& position, const value_type& insertMe);
        void delete_after(iterator& position); 

        

    };
    
    
}

#include "ll.cpp"

#endif /* ll_h */
