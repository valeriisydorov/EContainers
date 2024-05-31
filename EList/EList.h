#ifndef ELIST_H
#define ELIST_H


#include <cstddef>


template <typename T> class EList {
    class Node;
    using pointer = Node*;
public:
    template <typename U, typename P> class Iterator;

    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using size_type = std::size_t;
    using iterator = Iterator<T, pointer>;
    using const_iterator = Iterator<const T, const pointer>;

    template <typename U, typename P> class Iterator {
    public:
    private:

    };

    EList(size_type, const value_type&);
    EList(const EList&);
    EList(EList&&) noexcept;
    EList& operator=(const EList&);
    EList& operator=(EList&&) noexcept;

    ~EList();

    iterator operator[](size_type);
    const_iterator operator[](size_type) const;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;

    size_type size() const noexcept;

    iterator insert(const_iterator, const value_type&);
    void push_back(const EList&);
    void push_front(const EList&);
    void pop_back();
    void pop_front();

    void remove(const EList&);
    void remove(size_type);
    void remove(iterator);

    bool contains(const value_type&) const;
    iterator find(const value_type&);

private:
    class Node {
    public:
    private:
        pointer prev;
        pointer next;
        value_type data;
    };

    pointer head;
    pointer tail;
    size_type length;

};


#endif
