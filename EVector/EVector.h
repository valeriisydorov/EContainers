#pragma once


#include <cstddef>
#include <stdexcept>


template <typename T>
class EVector {
    class Iterator;
    class ConstIterator;
    class Allocator;

    friend class Allocator;

    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using iterator = Iterator;
    using const_iterator = ConstIterator;
    using reference = value_type&;
    using const_reference = const value_type&;

    class Iterator {
        friend class EVector;
        friend bool operator==(const Iterator& lhs, const Iterator& rhs);
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs);

    public:
        using pointer_type = value_type*;
        using reference = value_type&;

        Iterator();
        Iterator(pointer_type pointer);
        Iterator(const Iterator& other) = default;
        Iterator(Iterator&& other) noexcept = default;
        Iterator& operator=(const Iterator& rhs) = default;
        Iterator& operator=(Iterator&& rhs) noexcept = default;

        ~Iterator() = default;

        reference operator*();
        pointer_type operator->();

        Iterator& operator++();
        Iterator operator++(int);
        Iterator operator+(difference_type diff) const;
        Iterator& operator--();
        Iterator operator--(int);
        Iterator operator-(difference_type diff) const;

    private:
        pointer_type current;
    };

    class ConstIterator {
        friend class EVector;
        friend bool operator==(const ConstIterator& lhs, const ConstIterator& rhs);
        friend bool operator!=(const ConstIterator& lhs, const ConstIterator& rhs);

    public:
        using pointer_type = const value_type*;
        using reference = const value_type&;

        ConstIterator();
        ConstIterator(pointer_type pointer);
        ConstIterator(const Iterator& it);
        ConstIterator(const ConstIterator& other) = default;
        ConstIterator(ConstIterator&& other) noexcept = default;
        ConstIterator& operator=(const ConstIterator& rhs) = default;
        ConstIterator& operator=(ConstIterator&& rhs) noexcept = default;

        ~ConstIterator() = default;

        reference operator*() const;
        pointer_type operator->() const;

        ConstIterator& operator++();
        ConstIterator operator++(int);
        ConstIterator operator+(difference_type diff) const;
        ConstIterator& operator--();
        ConstIterator operator--(int);
        ConstIterator operator-(difference_type diff) const;

    private:
        pointer_type current;
    };

public:
    EVector();
    EVector(size_type count, value_type& value);
    EVector(const EVector& other);
    EVector(EVector&& other) noexcept;
    EVector& operator=(const EVector& rhs);
    EVector& operator=(EVector&& rhs) noexcept;
    ~EVector();

    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

    iterator begin();
    const_iterator cbegin();
    iterator end();
    const_iterator cend();

    size_type size() const;
    size_type capacity() const;
    void reserve(size_type new_cap);

    size_type insert(size_type pos, const value_type& value);
    iterator insert(const_iterator pos, const value_type& value);
    size_type erase(size_type pos);
    iterator erase(value_type& value);
    void push_back(const value_type& value);
    void push_back(value_type&& value);
    void resize(size_type count);

    bool contains(const value_type& value) const;
    iterator find(const value_type& value);

private:
    class Allocator {
        friend class EVector;

    public:

    private:

    };

    value_type* value;
    size_type value_length;
    size_type capacity_length;
    allocator_type allocator;

};

