#ifndef ELIST_H
#define ELIST_H


#include <cstddef>
#include <stdexcept>
#include <utility>


template <typename T>
class EList {
    class Node;

    using pointer_type = Node*;

public:
    template <typename V, typename P, typename C>
    class Iterator;

    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using iterator = Iterator<value_type, pointer_type, EList<T>*>;
    using const_iterator = Iterator<const value_type, const pointer_type, const EList<T>*>;

    template <typename V, typename P, typename C>
    class Iterator {
        friend class EList<T>;
        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.current == rhs.current) && (lhs.container == rhs.container);
        }
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return !(rhs == lhs);
        }

    public:
        using value_type = V;
        using pointer_type = P;
        using reference = value_type&;
        using const_reference = const value_type&;
        using container_pointer = C;

        Iterator();
        Iterator(pointer_type, container_pointer);
        Iterator(const Iterator&) = default;
        Iterator(Iterator&&) noexcept = default;
        Iterator& operator=(const Iterator&) = default;
        Iterator& operator=(Iterator&&) noexcept = default;

        ~Iterator() = default;

        reference operator*();
        const_reference operator*() const;
        pointer_type operator->();
        pointer_type operator->() const;

        Iterator& operator++();
        Iterator operator++(int);
        Iterator operator+(difference_type) const;
        Iterator& operator--();
        Iterator operator--(int);
        Iterator operator-(difference_type) const;

    private:
        pointer_type current;
        container_pointer container;
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

    void insert(size_type, const value_type&);
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
        friend class Iterator<value_type, pointer_type, EList<T>*>;
        friend class Iterator<const value_type, const pointer_type, const EList<T>*>;

    public:
        Node();
        Node(const value_type&);

        void set_data(const value_type&);
        value_type& get_data();
        const value_type& get_data() const;
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

    void clear();
};


template <typename T>
EList<T>::EList() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
EList<T>::EList(size_type count, const value_type& value) : EList() {
    if (count == 0) {
        throw std::invalid_argument("invalid_argument: Count should be greater than zero.");
    }
    for (size_type i = 0; i < count; ++i) {
        push_back(value);
    }
}

template <typename T>
EList<T>::EList(const EList& other) : EList() {
    pointer_type temp = other.head;
    while (temp != nullptr) {
        push_back(temp->get_data());
        temp = temp->get_next();
    }
}

template <typename T>
EList<T>& EList<T>::operator=(const EList& rhs) {
    if (this != &rhs) {
        clear();
        pointer_type temp = rhs.head;
        while (temp != nullptr) {
            push_back(temp->get_data());
            temp = temp->get_next();
        }
    }
    return *this;
}

template <typename T>
EList<T>::~EList() {
    clear();
}

template <typename T>
void EList<T>::clear() {
    while (head != nullptr) {
        pointer_type temp = head;
        head = head->get_next();
        delete temp;
    }
    tail = nullptr;
    length = 0;
}

template <typename T>
typename EList<T>::iterator
EList<T>::operator[](size_type pos) {
    if (pos >= size()) {
        throw std::out_of_range("out_of_range: Position out of range for the EList.");
    }
    iterator it;
    if (pos > size() / 2) {
        it = end();
        for (size_type i = size(); i > pos; --i) {
            --it;
        }
    } else {
        it = begin();
        for (size_type i = 0; i < pos; ++i) {
            ++it;
        }
    }
    return it;
}

template <typename T>
typename EList<T>::const_iterator
EList<T>::operator[](size_type pos) const {
    EList<T>& current_object = const_cast<EList<T>&>(*this);
    iterator it = current_object[pos];
    return const_iterator(it.current, it.container);
}

template <typename T>
typename EList<T>::iterator
EList<T>::begin() noexcept {
    return iterator(head, this);
}

template <typename T>
typename EList<T>::const_iterator
EList<T>::begin() const noexcept {
    return const_iterator(head, this);
}

template <typename T>
typename EList<T>::iterator
EList<T>::end() noexcept {
    return iterator(nullptr, this);
}

template <typename T>
typename EList<T>::const_iterator
EList<T>::end() const noexcept {
    return const_iterator(nullptr, this);
}

template <typename T>
typename EList<T>::size_type
EList<T>::size() const noexcept {
    return length;
}

template <typename T>
void EList<T>::insert(size_type pos, const value_type& value) {
    if (pos > size()) {
        throw std::out_of_range("out_of_range: Position out of range for the EList.");
    }
    if (pos == 0) {
        push_front(value);
    } else if (pos < size()) {
        pointer_type node = new Node(value);
        pointer_type current = head;
        if (pos > size() / 2) {
            current = tail;
            for (size_type i = size() - 1; i > pos; --i) {
                current = current->get_prev();
            }
        } else {
            for (size_type i = 0; i < pos; ++i) {
                current = current->get_next();
            }
        }
        node->set_next(current);
        node->set_prev(current->get_prev());
        current->get_prev()->set_next(node);
        current->set_prev(node);
        ++length;
    } else {
        push_back(value);
    }
}

template <typename T>
void EList<T>::push_back(const value_type& value) {
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

template <typename T>
void EList<T>::push_front(const value_type& value) {
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

template <typename T>
void EList<T>::pop_back() {
    if (!tail) {
        throw std::out_of_range("out_of_range: pop_back called on empty EList.");
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

template <typename T>
void EList<T>::pop_front() {
    if (!head) {
        throw std::out_of_range("out_of_range: pop_front called on empty EList.");
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

template <typename T>
EList<T>::Node::Node() : prev(nullptr), next(nullptr), data(value_type{}) {}

template <typename T>
EList<T>::Node::Node(const value_type& value) : prev(nullptr), next(nullptr), data(value) {}

template <typename T>
void EList<T>::Node::set_prev(pointer_type pointer_prev) {
    prev = pointer_prev;
}

template <typename T>
void EList<T>::Node::set_next(pointer_type pointer_next) {
    next = pointer_next;
}

template <typename T>
typename EList<T>::pointer_type
EList<T>::Node::get_prev() const {
    return prev;
}

template <typename T>
typename EList<T>::pointer_type
EList<T>::Node::get_next() const {
    return next;
}

template <typename T>
void EList<T>::Node::set_data(const value_type& value) {
    data = value;
}

template <typename T>
typename EList<T>::value_type& EList<T>::Node::get_data() {
    return data;
}

template <typename T>
typename EList<T>::value_type const& EList<T>::Node::get_data() const {
    return data;
}

template <typename T>
template <typename V, typename P, typename C>
EList<T>::Iterator<V, P, C>::Iterator() : current(nullptr), container(nullptr) {}

template <typename T>
template <typename V, typename P, typename C>
EList<T>::Iterator<V, P, C>::Iterator(pointer_type node, container_pointer cont) : current(node), container(cont) {}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>::reference
EList<T>::Iterator<V, P, C>::operator*() {
    if (current == nullptr) {
        throw std::runtime_error("runtime_error: Attempt to dereference a null iterator.");
    }
    return current->data;
}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>::const_reference
EList<T>::Iterator<V, P, C>::operator*() const {
    if (current == nullptr) {
        throw std::runtime_error("runtime_error: Attempt to dereference a null const iterator.");
    }
    return current->data;
}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>::pointer_type
EList<T>::Iterator<V, P, C>::operator->() {
    if (current == nullptr) {
        throw std::runtime_error("runtime_error: Attempt to access a member via a null pointer in iterator.");
    }
    return current;
}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>::pointer_type
EList<T>::Iterator<V, P, C>::operator->() const {
    if (current == nullptr) {
        throw std::runtime_error("runtime_error: Attempt to access a member via a null pointer in const iterator.");
    }
    return current;
}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>&
EList<T>::Iterator<V, P, C>::operator++() {
    if (current == nullptr) {
        throw std::out_of_range("out_of_range: Cannot increment iterator past the ending of EList.");
    }
    current = current->get_next();
    return *this;
}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>&
EList<T>::Iterator<V, P, C>::operator--() {
    if (current == nullptr) {
        current = container->tail;
    } else if (current->get_prev() == nullptr) {
        throw std::out_of_range("out_of_range: Cannot decrement iterator past the beginning of EList.");
    } else {
        current = current->get_prev();
    }
    return *this;
}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>
EList<T>::Iterator<V, P, C>::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>
EList<T>::Iterator<V, P, C>::operator--(int) {
    Iterator temp = *this;
    --(*this);
    return temp;
}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>
EList<T>::Iterator<V, P, C>::operator+(difference_type diff) const {
    Iterator temp = *this;
    if (diff > 0) {
        for (difference_type i = 0; i < diff; ++i) {
            ++temp;
        }
    } else {
        for (difference_type i = 0; i < -diff; ++i) {
            --temp;
        }
    }
    return temp;
}

template <typename T>
template <typename V, typename P, typename C>
typename EList<T>::template Iterator<V, P, C>
EList<T>::Iterator<V, P, C>::operator-(difference_type diff) const {
    return *this + (-diff);
}


#endif
