#ifndef ELIST_H
#define ELIST_H


#include <cstddef>


template <typename T> class EList {
    class Node;

    using value_type = T;
    using size_type = std::size_t;
    using pointer_type = Node*;


//    difference_type
//    reference
//    const_reference

//    iterator
//    const_iterator
//    reverse_iterator
//    const_reverse_iterator

public:
    class Iterator {
    public:
    private:

    };

    EList(size_type, const value_type&);
    EList(const EList&);
    EList(EList&&) noexcept;
    EList& operator=(const EList&);
    EList& operator=(EList&&) noexcept;

    ~EList();

    size_type size() const noexcept;

    void push_back(const EList&);
    void push_front(const EList&);
    void pop_back();
    void pop_front();

    void remove(const EList&);

private:
    class Node {
    public:
    private:
        pointer_type prev;
        pointer_type next;
        value_type data;
    };

    pointer_type head;
    pointer_type tail;
    size_type length;

//    insert(index, value)

//    iterator [] const
//    iterator []

//    contains(value)
//    iterator find(value)

//    remove_at(index)
//    remove_at(iterator)

//    end()
//    begin() for range based for

};


#endif
