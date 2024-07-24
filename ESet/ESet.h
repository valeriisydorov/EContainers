#pragma once

#include <cstddef>


template <typename K>
class ESet {
    class Node;

    using node_type = Node;
    using node_pointer_type = node_type*;

public:
    class Iterator;

    using key_type = K;
    using size_type = std::size_t;
    using reference = key_type&;

    class Iterator {
        friend class EVector;
//        friend bool operator==(const Iterator& lhs, const Iterator& rhs);
//        friend bool operator!=(const Iterator& lhs, const Iterator& rhs);

    public:
        using pointer_type = key_type*;
        using reference = key_type&;
        using container_pointer_type = ESet<key_type>*;

        Iterator();
        Iterator(pointer_type curr, container_pointer_type cont);
        Iterator(const Iterator& other) = default;
        Iterator(Iterator&& other) noexcept = default;
        Iterator& operator=(const Iterator& rhs) = default;
        Iterator& operator=(Iterator&& rhs) noexcept = default;

        ~Iterator() = default;

        reference operator*();

        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);

    private:
        pointer_type current;
        container_pointer_type container;
    };

    using iterator = Iterator;

    ESet();
    ESet(const ESet& other);
    ESet(ESet&& other) noexcept;
    ESet& operator=(const ESet& rhs);
    ESet& operator=(ESet&& rhs) noexcept;

    ~ESet();

    iterator begin();
    iterator end();

    bool empty() const;
    size_type size() const;

    void clear();
    bool insert(const key_type& key, bool* is_in_set = nullptr);
    size_type remove(const key_type& key);
    iterator remove_at(iterator pos);

    iterator find(const key_type& key);
    bool contains(const key_type& key) const;

private:

    class Node {
        friend class ESet;
        friend class Iterator;

    public:
        Node();
        Node(const key_type& key);
        Node(const Node& other) = default;
        Node(Node&& other) noexcept = default;
        Node& operator=(const Node& rhs) = default;
        Node& operator=(Node&& rhs) noexcept = default;

        ~Node() = default;

        void set_left(node_pointer_type left_node);
        void set_right(node_pointer_type right_node);
        void set_parent(node_pointer_type parent_node);

        node_pointer_type get_left() const;
        node_pointer_type get_right() const;
        node_pointer_type get_parent() const;

        bool has_left() const;
        bool has_right() const;
        bool has_parent() const;

    private:
        node_pointer_type left;
        node_pointer_type right;
        node_pointer_type parent;
        key_type data;

    };

    node_pointer_type root;
    size_type length;

};


template <typename K>
ESet<K>::ESet()
    : root(nullptr)
    , length(0)
{
}

template <typename K>
typename ESet<K>::size_type
ESet<K>::size() const
{
    return length;
}

template <typename K>
ESet<K>::Node::Node()
    : left(nullptr)
    , right(nullptr)
    , parent(nullptr)
    , data(key_type{})
{
}

template <typename K>
void ESet<K>::Node::set_left(node_pointer_type left_node)
{
    left = left_node;
}

template <typename K>
void ESet<K>::Node::set_right(node_pointer_type right_node)
{
    right = right_node;
}

template <typename K>
void ESet<K>::Node::set_parent(node_pointer_type parent_node)
{
    parent = parent_node;
}

template <typename K>
typename ESet<K>::node_pointer_type
ESet<K>::Node::get_left() const
{
    return left;
}

template <typename K>
typename ESet<K>::node_pointer_type
ESet<K>::Node::get_right() const
{
    return right;
}

template <typename K>
typename ESet<K>::node_pointer_type
ESet<K>::Node::get_parent() const
{
    return parent;
}

template <typename K>
bool ESet<K>::Node::has_left() const
{
    return left != nullptr;
}

template <typename K>
bool ESet<K>::Node::has_right() const
{
    return right != nullptr;
}

template <typename K>
bool ESet<K>::Node::has_parent() const
{
    return parent != nullptr;
}

template <typename K>
ESet<K>::iterator::Iterator()
    : current(nullptr)
    , container(nullptr)
{
}

template <typename K>
ESet<K>::iterator::Iterator(pointer_type curr, container_pointer_type cont)
    : current(curr)
    , container(cont)
{
}

template <typename K>
typename ESet<K>::iterator::reference
ESet<K>::iterator::operator*()
{
    return current->data;
}