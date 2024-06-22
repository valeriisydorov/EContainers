#pragma once
#include <cstddef>


template <typename T>
class EVector {

    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;

public:
    EVector();
    EVector(size_type count, value_type& value);
    EVector(const EVector& other);
    EVector(EVector&& other);
    EVector& operator=(const EVector& rhs);
    EVector& operator=(EVector&& rhs);
    ~EVector();

    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

//    iterator begin();
//    iterator end();

    size_type size() const;
    size_type capacity() const;
    void reserve(size_type new_cap);

    size_type insert(size_type pos, const value_type& value);
//    iterator insert(const_iterator pos, const value_type& value);
    size_type erase(size_type pos);
//    iterator erase(value_type& value);
    void push_back(const value_type& value);
    void push_back(value_type&& value);
    void resize(size_type count);

    bool contains(const value_type& value);
    size_type find(const value_type& value);
//    iterator find(const value_type& value);

private:

};






