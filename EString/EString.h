#ifndef ESTRING_H
#define ESTRING_H


#include <iostream>
#include <cstddef>
#include <cstring>
#include <memory>
#include <iterator>
#include <initializer_list>
#include <string>
#include <stdexcept>


class EString {
    using value_type = char;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using allocator_type = std::allocator<value_type>;

    friend std::ostream& operator<<(std::ostream&, const EString&);
    friend std::istream& operator>>(std::istream&, EString&);

    friend EString operator+(const EString&, const EString&);
    
    friend bool operator==(const EString&, const EString&) noexcept;
    friend bool operator!=(const EString&, const EString&) noexcept;
    friend bool operator<(const EString&, const EString&) noexcept;
    friend bool operator>(const EString&, const EString&) noexcept;
    friend bool operator<=(const EString&, const EString&) noexcept;
    friend bool operator>=(const EString&, const EString&) noexcept;
public:
    using iterator = value_type*;
    using const_iterator = const value_type*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    EString();
    EString(const value_type*);
    EString(const value_type*, size_type);
    EString(size_type, value_type);
    template <typename It> EString(It, It);

    EString(const EString&);
    EString(EString&&) noexcept;
    EString& operator=(const EString&);
    EString& operator=(EString&&) noexcept;

    EString(std::initializer_list<value_type>);
    EString(const std::string&);
    EString& operator=(const std::string&);

    EString& assign(const value_type*);
    EString& assign(const value_type*, size_type);
    EString& assign(size_type, value_type);
    template <typename It> EString& assign(It, It);
    EString& assign(const EString&);
    EString& assign(const EString&, size_type, size_type);
    EString& assign(EString&&) noexcept;
    EString& assign(std::initializer_list<value_type>) noexcept;
    EString& assign(const std::string&);
    EString& assign(const std::string&, size_type, size_type);

    ~EString();

    value_type& at(size_type);
    const value_type& at(size_type) const;
    value_type& operator[](size_type);
    const value_type& operator[](size_type) const;
    value_type& front();
    const value_type& front() const;
    value_type& back();
    const value_type& back() const;
    const value_type* data() const noexcept;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;

    size_type size() const noexcept;
    size_type length() const noexcept;
    size_type capacity() const noexcept;
    size_type max_size() const noexcept;
    bool empty();

    void reserve(size_type n = 0);
    void shrink_to_fit();

    EString& insert(size_type, size_type, value_type);
    EString& insert(size_type, const value_type*);
    EString& insert(size_type, const value_type*, size_type);
    EString& insert(size_type, const EString&);
    EString& insert(size_type, const EString&, size_type, size_type);
    iterator insert(const_iterator, value_type);
    iterator insert(const_iterator, size_type, value_type);
    template <typename It> iterator insert(const_iterator, It, It);
    iterator insert(const_iterator, std::initializer_list<value_type>);
    EString& insert(size_type, const std::string&);
    EString& insert(size_type, const std::string&, size_type, size_type);

    void clear() noexcept;
    EString& erase(size_type index = 0, size_type count = npos);
    iterator erase(const_iterator);
    iterator erase(const_iterator, const_iterator);
    void push_back(value_type);
    void pop_back();
    EString& replace(size_type, size_type, const EString&, size_type, size_type);
    size_type copy(value_type*, size_type, size_type pos = 0) const;
    void resize(size_type) noexcept;
    void resize(size_type, char) noexcept;

    size_type find(const EString&, size_type pos = 0) const noexcept;
    size_type find(value_type, size_type pos = 0) const noexcept;
    size_type rfind(const EString&, size_type pos = npos) const noexcept;
    size_type rfind(value_type, size_type pos = npos) const noexcept;
    size_type find_first_of(const EString&, size_type pos = 0) const noexcept;
    size_type find_first_of(value_type, size_type pos = 0) const noexcept;
    size_type find_first_not_of(const EString&, size_type pos = 0) const noexcept;
    size_type find_first_not_of(value_type, size_type pos = 0) const noexcept;
    size_type find_last_of(const EString&, size_type pos = npos) const noexcept;
    size_type find_last_of(value_type, size_type pos = npos) const noexcept;
    size_type find_last_not_of(const EString&, size_type pos = npos) const noexcept;
    size_type find_last_not_of(value_type, size_type pos = npos) const noexcept;

    int compare(const EString&) const noexcept;
private:
    allocator_type allocator;
    value_type* value;
    size_type value_length;
    size_type capacity_length;

    static constexpr size_type npos = -1;
};

std::ostream& operator<<(std::ostream&, const EString&);
std::istream& operator>>(std::istream&, EString&);

EString operator+(const EString&, const EString&);

bool operator==(const EString&, const EString&) noexcept;
bool operator!=(const EString&, const EString&) noexcept;
bool operator<(const EString&, const EString&) noexcept;
bool operator>(const EString&, const EString&) noexcept;
bool operator<=(const EString&, const EString&) noexcept;
bool operator>=(const EString&, const EString&) noexcept;

template <typename It> EString::EString(It first, It last): value(nullptr), value_length(0), capacity_length(0) {
    difference_type len = std::distance(first, last);
    value = allocator.allocate(len + 1);
    size_type i = 0;
    for (It it = first; it != last; ++it) {
        value[i++] = *it;
    }
    value[len] = '\0';
    value_length = len;
    capacity_length = len;
}

template <typename It> EString& EString::assign(It first, It last) {
    difference_type len = std::distance(first, last);
    if (len > capacity_length) {
        reserve(len);
    }
    size_type i = 0;
    for (It it = first; it != last; ++it) {
        value[i++] = *it;
    }
    value[len] = '\0';
    value_length = len;
    return *this;
}

template <typename It> EString::iterator EString::insert(const_iterator pos, It first, It last) {
    difference_type index = pos - begin();
    if (index > value_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    difference_type len = std::distance(first, last);
    if (value_length + len > capacity_length) {
        reserve(value_length + len);
    }
    for (size_type i = value_length + len; i > index; --i) {
        value[i] = value[i - len];
    }
    size_type i = index;
    for (It it = first; it != last; ++it) {
        value[i++] = *it;
    }
    value[value_length + len] = '\0';
    value_length += len;
    return begin() + index;
}


#endif
