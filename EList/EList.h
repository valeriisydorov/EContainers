#ifndef ELIST_H
#define ELIST_H


#include <cstddef>
#include <stdexcept>


template <typename T> class EList {
    class Node;

    using pointer_type = Node*;

public:
    template <typename U, typename P> class Iterator;

    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using iterator = Iterator<value_type, pointer_type>;
    using const_iterator = Iterator<const value_type, const pointer_type>;

    template <typename U, typename P> class Iterator {
    public:
        using value_type = U;
        using pointer_type = P;
        using reference = value_type&;
        using const_reference = const value_type&;

        Iterator();
        Iterator(pointer_type node = nullptr);

        reference operator*();
        pointer_type operator->();

        Iterator& operator++();
        Iterator operator++(int);
        Iterator operator+(difference_type) const;
        Iterator& operator--();
        Iterator operator--(int);
        Iterator operator-(difference_type) const;

        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;

    private:
        pointer_type current;
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
        friend class Iterator<value_type, pointer_type>;
        friend class Iterator<const value_type, const pointer_type>;

    public:
        Node();
        Node(const value_type&);
        Node(const Node&);
        Node(Node&&) noexcept;
        Node& operator=(const Node&);
        Node& operator=(Node&&) noexcept;

        ~Node();

    private:
        void set_prev(pointer_type);
        void set_next(pointer_type);
        pointer_type get_prev() const;
        pointer_type get_next() const;

        pointer_type prev;
        pointer_type next;
        value_type data;

    };

    pointer_type head;
    pointer_type tail;
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
        pointer_type temp = head;
        head = head->get_next();
        delete temp;
    }
    tail = nullptr;
    length = 0;
}

template <typename T> typename EList<T>::size_type EList<T>::size() const noexcept {
    return length;
}

template <typename T> void EList<T>::push_back(const value_type& value) {
    pointer_type node = new Node(value);
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

template <typename T> void EList<T>::push_front(const value_type& value) {
    pointer_type node = new Node(value);
    if (head) {
        head->set_prev(node);
        node->set_next(head);
        head = node;
    } else {
        head = node;
        tail = node;
    }
    ++length;
}

template <typename T> void EList<T>::pop_back() {
    if (!tail) {
        throw std::out_of_range("out_of_range: pop_back called on empty EList");
    }
    pointer_type temp = tail;
    if (tail->get_prev()) {
        tail = tail->get_prev();
        tail->set_next(nullptr);
    } else {
        head = nullptr;
        tail = nullptr;
    }
    delete temp;
    --length;
}

template <typename T> void EList<T>::pop_front() {
    if (!head) {
        throw std::out_of_range("out_of_range: pop_front called on empty EList");
    }
    pointer_type temp = head;
    if (head->get_next()) {
        head = head->get_next();
        head->set_prev(nullptr);
    } else {
        head = nullptr;
        tail = nullptr;
    }
    delete temp;
    --length;
}

template <typename T> EList<T>::Node::Node() : prev(nullptr), next(nullptr), data(value_type{}) {}

template <typename T> EList<T>::Node::Node(const value_type& value) : prev(nullptr), next(nullptr), data(value) {}

template <typename T> EList<T>::Node::~Node() {}

template <typename T> void EList<T>::Node::set_prev(pointer_type pointer_prev) {
    prev = pointer_prev;
}

template <typename T> void EList<T>::Node::set_next(pointer_type pointer_next) {
    next = pointer_next;
}

template <typename T> typename EList<T>::pointer_type EList<T>::Node::get_prev() const {
    return prev;
}

template <typename T> typename EList<T>::pointer_type EList<T>::Node::get_next() const {
    return next;
}



#endif
