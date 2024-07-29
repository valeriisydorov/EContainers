#pragma once

#include <cstddef>
#include <stdexcept>


template <typename K>
class ESet {
    class Node;

    using node_pointer_type = Node*;

public:
    class Iterator;

    using key_type = K;
    using size_type = std::size_t;
    using reference = key_type&;

    class Iterator {
        friend class ESet;
        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.current == rhs.current) && (lhs.container == rhs.container);
        }
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return !(lhs == rhs);
        }

    public:
        using reference = key_type&;
        using container_pointer_type = const ESet<key_type>*;

        Iterator();
        Iterator(node_pointer_type curr, container_pointer_type cont);
        Iterator(const Iterator& other) = default;
        Iterator(Iterator&& other) noexcept = default;
        Iterator& operator=(const Iterator& rhs) = default;
        Iterator& operator=(Iterator&& rhs) noexcept = default;

        ~Iterator() = default;

        reference operator*() const;

        Iterator& operator++();
        Iterator operator++(int);

    private:
        node_pointer_type current;
        container_pointer_type container;
    };

    using iterator = Iterator;

    ESet();
    ESet(const ESet& other);
    ESet(ESet&& other) noexcept;
    ESet& operator=(const ESet& rhs);
    ESet& operator=(ESet&& rhs) noexcept;

    ~ESet();

    iterator begin() noexcept;
    iterator begin() const noexcept;
    iterator end() noexcept;
    iterator end() const noexcept;

    bool empty() const;
    size_type size() const;

    void clear();
    iterator insert(const key_type& key, bool* is_in_set = nullptr);
    size_type remove(const key_type& key);
    iterator remove_at(iterator pos);

    iterator find(const key_type& key) const;
    bool contains(const key_type& key) const;

private:

    class Node {
        friend class ESet;
        friend class Iterator;

    public:
        Node();
        explicit Node(const key_type& key);
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

    node_pointer_type get_min_node(node_pointer_type node) const;
    void move_node_pointers(node_pointer_type node, node_pointer_type new_node);

};


template <typename K>
ESet<K>::ESet()
    : root(nullptr)
    , length(0)
{
}

template <typename K>
ESet<K>::~ESet()
{

}

template <typename K>
typename ESet<K>::iterator
ESet<K>::begin() noexcept
{
    return iterator(get_min_node(root), this);
}

template <typename K>
typename ESet<K>::iterator
ESet<K>::begin() const noexcept
{
    return iterator(get_min_node(root), this);
}

template <typename K>
typename ESet<K>::iterator
ESet<K>::end() noexcept
{
    return iterator(nullptr, this);
}

template <typename K>
typename ESet<K>::iterator
ESet<K>::end() const noexcept
{
    return iterator(nullptr, this);
}

template <typename K>
bool ESet<K>::empty() const
{
    return begin() == end();
}

template <typename K>
typename ESet<K>::size_type
ESet<K>::size() const
{
    return length;
}

template <typename K>
typename ESet<K>::iterator
ESet<K>::insert(const key_type& key, bool* is_in_set)
{
    node_pointer_type node = root;
    node_pointer_type parent_node = nullptr;

    while (node != nullptr) {
        parent_node = node;
        if (key < node->data) {
            node = node->get_left();
        } else if (key > node->data) {
            node = node->get_right();
        } else {
            if (is_in_set != nullptr) {
                *is_in_set = true;
            }
            return iterator(node, this);
        }
    }

    node_pointer_type new_node = new Node(key);
    new_node->set_parent(parent_node);

    if (parent_node == nullptr) {
        root = new_node;
    } else if (key < parent_node->data) {
        parent_node->set_left(new_node);
    } else {
        parent_node->set_right(new_node);
    }

    length++;

    if (is_in_set != nullptr) {
        *is_in_set = false;
    }
    return iterator(new_node, this);
}

template <typename K>
typename ESet<K>::size_type
ESet<K>::remove(const key_type& key)
{
    size_type result = 0;
    iterator it = find(key);

    if (it != end()) {
        node_pointer_type removed_node = it.current;

        if (!removed_node->has_left() && !removed_node->has_right()) {
            move_node_pointers(removed_node, nullptr);
        } else if (!removed_node->has_left() || !removed_node->has_right()) {
            node_pointer_type child_node = removed_node->has_left() ? removed_node->get_left() : removed_node->get_right();

            move_node_pointers(removed_node, child_node);

            child_node->set_parent(removed_node->get_parent());
        } else {
            node_pointer_type moved_node = get_min_node(removed_node->get_right());
            removed_node->data = moved_node->data;

            if (moved_node == removed_node->get_right()) {
                removed_node->set_right(moved_node->get_right());
            } else {
                moved_node->get_parent()->set_left(moved_node->get_right());
            }

            if (moved_node->has_right()) {
                moved_node->get_right()->set_parent(moved_node->get_parent());
            }

            removed_node = moved_node;
        }

        delete removed_node;
        result++;
        length--;
    }

    return result;
}

template <typename K>
typename ESet<K>::iterator
ESet<K>::find(const key_type& key) const
{
    node_pointer_type node = root;

    while (node != nullptr) {
        if (key < node->data) {
            node = node->get_left();
        } else if (key > node->data) {
            node = node->get_right();
        } else {
            return iterator(node, this);
        }
    }

    return end();
}

template <typename K>
bool ESet<K>::contains(const key_type& key) const
{
    return find(key) != end();
}

template <typename K>
typename ESet<K>::node_pointer_type
ESet<K>::get_min_node(node_pointer_type node) const
{
    while (node && node->has_left()) {
        node = node->get_left();
    }
    return node;
}

template <typename K>
void ESet<K>::move_node_pointers(node_pointer_type node, node_pointer_type new_node)
{
    if (!node->has_parent()) {
        root = new_node;
    } else if (node == node->get_parent()->get_left()) {
        node->get_parent()->set_left(new_node);
    } else {
        node->get_parent()->set_right(new_node);
    }
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
ESet<K>::Node::Node(const key_type& key)
    : left(nullptr)
    , right(nullptr)
    , parent(nullptr)
    , data(key)
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
ESet<K>::iterator::Iterator(node_pointer_type curr, container_pointer_type cont)
    : current(curr)
    , container(cont)
{
}

template <typename K>
typename ESet<K>::iterator::reference
ESet<K>::iterator::operator*() const
{
    if (current == nullptr) {
        throw std::out_of_range("out_of_range: Dereferencing a null iterator.");
    }
    return current->data;
}

template <typename K>
typename ESet<K>::iterator&
ESet<K>::Iterator::operator++()
{
    if (current == nullptr) {
        throw std::out_of_range("out_of_range: Cannot increment iterator past the ending of ESet.");
    }

    if (current->has_right()) {
        current = current->get_right();
        while (current->has_left()) {
            current = current->get_left();
        }
    } else {
        node_pointer_type parent = current->get_parent();
        while (parent != nullptr && current == parent->get_right()) {
            current = parent;
            parent = parent->get_parent();
        }
        current = parent;
    }

    return *this;
}

template <typename K>
typename ESet<K>::iterator
ESet<K>::Iterator::operator++(int)
{
    iterator temp = *this;
    ++(*this);

    return temp;
}