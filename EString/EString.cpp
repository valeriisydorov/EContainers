#include "EString.h"

EString::EString() : value(nullptr), value_length(0), capacity_length(0) {}

EString::EString(const value_type* str) : value(nullptr), value_length(0), capacity_length(0) {
    size_type len = std::strlen(str);
    value = allocator.allocate(len + 1);
    for (size_type i = 0; i < len; ++i) {
        value[i] = str[i];
    }
    value[len] = '\0';
    value_length = len;
    capacity_length = len;
}

EString::EString(const value_type* str, size_type len) : value(nullptr), value_length(len), capacity_length(len) {
    value = allocator.allocate(len + 1);
    for (size_type i = 0; i < len; ++i) {
        value[i] = str[i];
    }
    value[len] = '\0';
}

EString::EString(size_type len, value_type ch) : value(nullptr), value_length(len), capacity_length(len) {
    value = allocator.allocate(len + 1);
    for (size_type i = 0; i < len; ++i) {
        value[i] = ch;
    }
    value[len] = '\0';
}

EString::EString(std::initializer_list<value_type> lst) : value(nullptr), value_length(0), capacity_length(0) {
    size_type len = lst.size();
    value = allocator.allocate(len + 1);
    std::initializer_list<value_type>::const_iterator it = lst.begin();
    for (size_type i = 0; i < len; ++i, ++it) {
        value[i] = *it;
    }
    value[len] = '\0';
    value_length = len;
    capacity_length = len;
}

EString::EString(const std::string& str) : value(nullptr), value_length(0), capacity_length(0) {
    size_type len = str.size();
    value = allocator.allocate(len + 1);
    for (size_type i = 0; i < len; ++i) {
        value[i] = str[i];
    }
    value[len] = '\0';
    value_length = len;
    capacity_length = len;
}

EString::EString(const EString& other) : value(nullptr), value_length(other.value_length), capacity_length(other.capacity_length) {
    value = allocator.allocate(value_length + 1);
    for (size_type i = 0; i <= value_length; ++i) {
        value[i] = other.value[i];
    }
}

EString::EString(EString&& other) noexcept : value(other.value), value_length(other.value_length), capacity_length(other.capacity_length) {
    other.value = nullptr;
    other.value_length = 0;
    other.capacity_length = 0;
}

EString& EString::operator=(const EString& rhs) {
    if (this != &rhs) {
        delete[] value;
        value_length = rhs.value_length;
        capacity_length = rhs.capacity_length;
        value = allocator.allocate(value_length + 1);
        for (size_type i = 0; i <= value_length; ++i) {
            value[i] = rhs.value[i];
        }
    }
    return *this;
}

EString& EString::operator=(EString&& rhs) noexcept {
    if (this != &rhs) {
        delete[] value;
        value = rhs.value;
        value_length = rhs.value_length;
        capacity_length = rhs.capacity_length;
        rhs.value = nullptr;
        rhs.value_length = 0;
        rhs.capacity_length = 0;
    }
    return *this;
}

EString& EString::operator=(const std::string& rhs) {
    delete[] value;
    value_length = rhs.size();
    capacity_length = rhs.size();
    value = allocator.allocate(value_length + 1);
    for (size_type i = 0; i < value_length; ++i) {
        value[i] = rhs[i];
    }
    value[value_length] = '\0';
    return *this;
}

EString::~EString() {
    delete[] value;
    value_length = 0;
    capacity_length = 0;
}

EString::value_type& EString::at(size_type index) {
    if (index >= value_length) {
        throw std::out_of_range("out_of_range: Index out of bounds.");
    }
    return value[index];
}

const EString::value_type& EString::at(size_type index) const {
    if (index >= value_length) {
        throw std::out_of_range("out_of_range: Index out of bounds.");
    }
    return value[index];
}

EString::value_type& EString::operator[](size_type index) {
    if (index >= value_length) {
        throw std::out_of_range("out_of_range: Index out of bounds.");
    }
    return value[index];
}

const EString::value_type& EString::operator[](size_type index) const {
    if (index >= value_length) {
        throw std::out_of_range("out_of_range: Index out of bounds.");
    }
    return value[index];
}

EString::value_type& EString::front() {
    return value[0];
}

const EString::value_type& EString::front() const {
    return value[0];
}

EString::value_type& EString::back() {
    return value[value_length - 1];
}

const EString::value_type& EString::back() const {
    return value[value_length - 1];
}

const EString::value_type* EString::data() const noexcept {
    return value;
}

EString::iterator EString::begin() noexcept {
    return value;
}

EString::const_iterator EString::begin() const noexcept {
    return value;
}

EString::const_iterator EString::cbegin() const noexcept {
    return value;
}

EString::iterator EString::end() noexcept {
    return value + value_length;
}

EString::const_iterator EString::end() const noexcept {
    return value + value_length;
}

EString::const_iterator EString::cend() const noexcept {
    return value + value_length;
}

EString::reverse_iterator EString::rbegin() noexcept {
    return reverse_iterator(end());
}

EString::const_reverse_iterator EString::rbegin() const noexcept {
    return const_reverse_iterator(end());
}

EString::const_reverse_iterator EString::crbegin() const noexcept {
    return const_reverse_iterator(cend());
}

EString::reverse_iterator EString::rend() noexcept {
    return reverse_iterator(begin());
}

EString::const_reverse_iterator EString::rend() const noexcept {
    return const_reverse_iterator(begin());
}

EString::const_reverse_iterator EString::crend() const noexcept {
    return const_reverse_iterator(cbegin());
}

EString::size_type EString::size() const noexcept {
    return value_length;
}

EString::size_type EString::length() const noexcept {
    return value_length;
}

EString::size_type EString::capacity() const noexcept {
    return capacity_length;
}

EString::size_type EString::max_size() const noexcept {
    return allocator.max_size();
}

bool EString::empty() {
    return begin() == end();
}

void EString::reserve(size_type n) {
    if (n > capacity_length) {
        value_type* new_value = allocator.allocate(n + 1);
        std::move(value, value + value_length + 1, new_value);
        allocator.deallocate(value, capacity_length + 1);
        value = new_value;
        capacity_length = n;
    }
}

void EString::shrink_to_fit() {
    if (value_length < capacity_length) {
        value_type* new_value = allocator.allocate(value_length + 1);
        std::move(value, value + value_length + 1, new_value);
        allocator.deallocate(value, capacity_length + 1);
        value = new_value;
        capacity_length = value_length;
    }
}

std::ostream& operator<<(std::ostream& os, const EString& es) {
    os << es.data();
    return os;
}

