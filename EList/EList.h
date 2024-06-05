#ifndef ELIST_H
#define ELIST_H


#include <cstddef>
#include <stdexcept>


template <typename T> class EList {
    class Node;

    using pointer = Node*;

public:
    template <typename U, typename P> class Iterator;

    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using iterator = Iterator<value_type, pointer>;
    using const_iterator = Iterator<const value_type, const pointer>;

    template <typename U, typename P> class Iterator {
    public:
        using value_type = U;
        using pointer = P;
        using reference = value_type&;
        using const_reference = const value_type&;

        Iterator();
        Iterator(pointer node = nullptr);

        reference operator*();
        pointer operator->();

        Iterator& operator++();
        Iterator operator++(int);
        Iterator operator+(difference_type) const;
        Iterator& operator--();
        Iterator operator--(int);
        Iterator operator-(difference_type) const;

        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;

    private:
        pointer current;
    };

    EList();
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
    void push_back(const value_type&);
    void push_front(const value_type&);
    void pop_back();
    void pop_front();

    void remove(const value_type&);
    void remove(size_type);
    void remove(iterator);

    bool contains(const value_type&) const;
    iterator find(const value_type&);

private:
    class Node {
        friend class EList;
        friend class Iterator<value_type, pointer>;
        friend class Iterator<const value_type, const pointer>;

    public:
        Node();
        Node(const value_type&);
        Node(const Node&);
        Node(Node&&) noexcept;
        Node& operator=(const Node&);
        Node& operator=(Node&&) noexcept;

        ~Node();

    private:
        void set_prev(pointer);
        void set_next(pointer);
        pointer get_prev() const;
        pointer get_next() const;

        pointer prev;
        pointer next;
        value_type data;

    };

    pointer head;
    pointer tail;
    size_type length;

};


template <typename T> EList<T>::EList() : head(nullptr), tail(nullptr), length(0) {}

template <typename T> EList<T>::EList(size_type count, const value_type& value) : EList() {
    if (count == 0) {
        throw std::invalid_argument("invalid_argument: Count should be greater than zero");
    }
    for (size_type i = 0; i < count; ++i) {
        push_back(value);
    }
}

template <typename T> EList<T>::~EList() {
    while (head != nullptr) {
        pointer temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    length = 0;
}

template <typename T> typename EList<T>::size_type EList<T>::size() const noexcept {
    return length;
}

template <typename T> void EList<T>::push_back(const value_type& value) {
    pointer node = new Node(value);
    if (tail) {
        tail->set_next(node);
        node->set_prev(tail);
        tail = node;
    } else {
        head = node;
        tail = node;
    }
    ++length;
}


template <typename T> EList<T>::Node::Node() : prev(nullptr), next(nullptr), data(value_type{}) {}

template <typename T> EList<T>::Node::Node(const value_type& value) : prev(nullptr), next(nullptr), data(value) {}

template <typename T> EList<T>::Node::~Node() {}

template <typename T> void EList<T>::Node::set_prev(pointer ptr) {
    prev = ptr;
}

template <typename T> void EList<T>::Node::set_next(pointer ptr) {
    next = ptr;
}



#endif
