#ifndef ESTRING_H
#define ESTRING_H


#include <iostream>
#include <cstddef>


class EString {
    using value_type = char;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using iterator = value_type*;
    using const_iterator = const value_type*;

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
    EString();
    EString(const EString&);
    EString(EString&&) noexcept;

    EString& operator=(const EString&);
    EString& operator=(EString&&) noexcept;

    ~EString();

    value_type& at(size_type);
    const value_type& at(size_type) const;
    EString& operator[](size_type);
    const EString& operator[](size_type) const;
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
    iterator rbegin() noexcept;
    const_iterator rbegin() const noexcept;
    const_iterator crbegin() const noexcept;
    iterator rend() noexcept;
    const_iterator rend() const noexcept;
    const_iterator crend() const noexcept;

    size_type size() const noexcept;
    size_type lenght() const noexcept;
    size_type capacity() const noexcept;
    size_type max_size() const noexcept;
    void reserve(size_type n = 0);
    bool empty();

    EString& assign(size_type, value_type);
    EString& assign(const EString&);
    EString& assign(const EString&, size_type, size_type);
    EString& insert(size_type, size_type, value_type);
    EString& insert(size_type, const value_type*);
    void clear() noexcept;
    EString& erase(size_type index = 0, size_type count = -1);
    iterator erase(const_iterator);
    iterator erase(const_iterator, const_iterator);
    void push_back(value_type);
    void pop_back(value_type);
    EString& replace(size_type, size_type, const EString&, size_type, size_type);
    size_type copy(value_type*, size_type, size_type pos = 0) const;
    void resize(size_type) noexcept;
    void resize(size_type, char) noexcept;

    size_type find(const EString&, size_type pos = 0) const noexcept;
    size_type find(value_type, size_type pos = 0 ) const noexcept;
    size_type rfind(const EString&, size_type pos = -1) const noexcept;
    size_type rfind(value_type, size_type pos = -1) const noexcept;
    size_type find_first_of(const EString&, size_type pos = 0) const noexcept;
    size_type find_first_of(value_type, size_type pos = 0) const noexcept;
    size_type find_first_not_of(const EString&, size_type pos = 0) const noexcept;
    size_type find_first_not_of(value_type, size_type pos = 0) const noexcept;
    size_type find_last_of(const EString&, size_type pos = -1) const noexcept;
    size_type find_last_of(value_type, size_type pos = -1) const noexcept;
    size_type find_last_not_of(const EString&, size_type pos = -1) const noexcept;
    size_type find_last_not_of(value_type, size_type pos = -1) const noexcept;

    int compare(const EString&) const noexcept;

private:
    value_type* value;
    size_type value_length;

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


#endif
