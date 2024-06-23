#pragma once


#include <cstddef>
#include <stdexcept>


template <typename T>
class EVector {
    class Iterator;
    class ConstIterator;
    class Allocator;

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

    public:

    private:
        value_type* current;
    };

    class ConstIterator {
        friend class EVector;

    public:

    private:
        const value_type* current;
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
    iterator cbegin();
    iterator end();
    iterator cend();

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

    bool contains(const value_type& value);
    size_type find(const value_type& value);
//    iterator find(const value_type& value);

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






