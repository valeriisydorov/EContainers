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
    size_type size();

    void clear();
    bool insert(const key_type& key);
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

    private:
        node_pointer_type left;
        node_pointer_type right;
        node_pointer_type parent;
        key_type data;

    };

    node_pointer_type root;
    size_type length;

};