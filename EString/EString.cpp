#include "EString.h"

EString::EString(const value_type* str, size_type len) : value(nullptr), value_length(len), capacity_length(len) {
    value = allocator.allocate(len + 1);
    for (size_type i = 0; i < len; ++i) {
        value[i] = str[i];
    }
    value[len] = '\0';
}

EString::EString(const value_type* str) : EString(str, std::strlen(str)) {}

EString::EString() : EString("") {}

EString::EString(size_type len, value_type ch) : value(nullptr), value_length(len), capacity_length(len) {
    value = allocator.allocate(len + 1);
    for (size_type i = 0; i < len; ++i) {
        value[i] = ch;
    }
    value[len] = '\0';
}

EString::EString(std::initializer_list<value_type> lst) : EString(lst.begin(), lst.end()) {}

EString::EString(const std::string& str) : EString(str.begin(), str.end()) {}

EString::EString(const EString& other) : value(nullptr), value_length(other.value_length), capacity_length(other.capacity_length) {
    value = allocator.allocate(value_length + 1);
    for (size_type i = 0; i <= value_length; ++i) {
        value[i] = other.value[i];
    }
    value[other.value_length] = '\0';
}

EString::EString(EString&& other) noexcept : value(other.value), value_length(other.value_length), capacity_length(other.capacity_length) {
    other.value = nullptr;
    other.value_length = 0;
    other.capacity_length = 0;
}

EString& EString::operator=(const EString& rhs) {
    if (this != &rhs) {
        if (rhs.value_length > capacity_length) {
            reserve(rhs.value_length);
        }
        for (size_type i = 0; i < rhs.value_length; ++i) {
            value[i] = rhs.value[i];
        }
        value[rhs.value_length] = '\0';
        value_length = rhs.value_length;
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
    size_type len = rhs.size();
    if (len > capacity_length) {
        reserve(len);
    }
    for (size_type i = 0; i < len; ++i) {
        value[i] = rhs[i];
    }
    value[len] = '\0';
    value_length = len;
    return *this;
}

EString& EString::assign(const value_type* str) {
    size_type len = std::strlen(str);
    if (len > capacity_length) {
        reserve(len);
    }
    for (size_type i = 0; i < len; ++i) {
        value[i] = str[i];
    }
    value[len] = '\0';
    value_length = len;
    return *this;
}

EString& EString::assign(const value_type* str, size_type len) {
    if (len > capacity_length) {
        reserve(len);
    }
    for (size_type i = 0; i < len; ++i) {
        value[i] = str[i];
    }
    value[len] = '\0';
    value_length = len;
    return *this;
}

EString& EString::assign(size_type len, value_type ch) {
    if (len > capacity_length) {
        reserve(len);
    }
    for (size_type i = 0; i < len; ++i) {
        value[i] = ch;
    }
    value[len] = '\0';
    value_length = len;
    return *this;
}

EString& EString::assign(const EString& other) {
    return operator=(other);
}

EString& EString::assign(const EString& other, size_type pos, size_type count) {
    if (this != &other) {
        if (pos > other.value_length) {
            throw std::out_of_range("out_of_range: Position is out of bounds.");
        }
        if (pos + count > other.value_length) {
            throw std::out_of_range("out_of_range: Count is out of bounds.");
        }
        if (count > capacity_length) {
            reserve(count);
        }
        for (size_type i = 0; i < count; ++i) {
            value[i] = other.value[pos + i];
        }
        value[count] = '\0';
        value_length = count;
    }
    return *this;
}

EString& EString::assign(EString&& other) noexcept {
    return operator=(std::move(other));
}

EString& EString::assign(std::initializer_list<value_type> lst) noexcept {
    size_type len = lst.size();
    if (len > capacity_length) {
        reserve(len);
    }
    size_type i = 0;
    for (const value_type& ch : lst) {
        value[i++] = ch;
    }
    value[len] = '\0';
    value_length = len;
    return *this;
}

EString& EString::assign(const std::string& str) {
    return operator=(str);
}

EString& EString::assign(const std::string& str, size_type pos, size_type count) {
    size_type len = str.size();
    if (pos > len) {
        throw std::out_of_range("out_of_range: Position is out of bounds.");
    }
    if (pos + count > len) {
        throw std::out_of_range("out_of_range: Count is out of bounds.");
    }
    if (count > capacity_length) {
        reserve(count);
    }
    for (size_type i = 0; i < count; ++i) {
        value[i] = str[pos + i];
    }
    value[count] = '\0';
    value_length = count;
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

EString& EString::insert(size_type index, size_type count, value_type ch) {
    if (index > value_length) {
        throw std::out_of_range("out_of_range: Index out of bounds.");
    }
    if (value_length + count > capacity_length) {
        reserve(value_length + count);
    }
    for (size_type i = value_length + count; i > index; --i) {
        value[i] = value[i - count];
    }
    for (size_type i = 0; i < count; ++i) {
        value[index + i] = ch;
    }
    value[value_length + count] = '\0';
    value_length += count;
    return *this;
}

EString& EString::insert(size_type index, const value_type* str, size_type count) {
    if (index > value_length) {
        throw std::out_of_range("out_of_range: Index out of bounds.");
    }
    if (index + count > std::strlen(str)) {
        throw std::out_of_range("out_of_range: Count out of bounds.");
    }
    if (value_length + count > capacity_length) {
        reserve(value_length + count);
    }
    for (size_type i = value_length + count; i > index; --i) {
        value[i] = value[i - count];
    }
    for (size_type i = 0; i < count; ++i) {
        value[index + i] = str[i];
    }
    value[value_length + count] = '\0';
    value_length += count;
    return *this;
}

EString& EString::insert(size_type index, const EString& str) {
    if (index > value_length) {
        throw std::out_of_range("out_of_range: Index out of bounds.");
    }
    size_type len = str.size();
    if (value_length + len > capacity_length) {
        reserve(value_length + len);
    }
    for (size_type i = value_length + len; i > index; --i) {
        value[i] = value[i - len];
    }
    for (size_type i = 0; i < len; ++i) {
        value[index + i] = str[i];
    }
    value[value_length + len] = '\0';
    value_length += len;
    return *this;
}

EString& EString::insert(size_type index, const value_type* str) {
    return insert(index, EString(str));
}

EString& EString::insert(size_type index, const std::string& str) {
    return insert(index, EString(str));
}

EString& EString::insert(size_type index, const EString& str, size_type second_index, size_type count) {
    if (index > value_length) {
        throw std::out_of_range("out_of_range: Index out of bounds.");
    }
    if (second_index > str.value_length) {
        throw std::out_of_range("out_of_range: Second index out of bounds.");
    }
    if (second_index + count > str.value_length) {
        throw std::out_of_range("out_of_range: Count out of bounds.");
    }
    if (value_length + count > capacity_length) {
        reserve(value_length + count);
    }
    for (size_type i = value_length + count; i > index; --i) {
        value[i] = value[i - count];
    }
    for (size_type i = 0; i < count; ++i) {
        value[index + i] = str[second_index + i];
    }
    value[value_length + count] = '\0';
    value_length += count;
    return *this;
}

EString& EString::insert(size_type index, const std::string& str, size_type second_index, size_type count) {
    return insert(index, EString(str), second_index, count);
}

EString::iterator EString::insert(const_iterator pos, size_type count, value_type ch) {
    difference_type index = pos - begin();
    if (index > value_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    if (value_length + count > capacity_length) {
        reserve(value_length + count);
    }
    for (size_type i = value_length + count; i > index; --i) {
        value[i] = value[i - count];
    }
    for (size_type i = 0; i < count; ++i) {
        value[index + i] = ch;
    }
    value[value_length + count] = '\0';
    value_length += count;
    return begin() + index;
}

EString::iterator EString::insert(const_iterator pos, value_type ch) {
    return insert(pos, 1, ch);
}

EString::iterator EString::insert(const_iterator pos, std::initializer_list<value_type> lst) {
    difference_type index = pos - begin();
    if (index > value_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    size_type len = lst.size();
    if (value_length + len > capacity_length) {
        reserve(value_length + len);
    }
    for (size_type i = value_length + len; i > index; --i) {
        value[i] = value[i - len];
    }
    size_type i = index;
    for (const value_type& ch : lst) {
        value[i++] = ch;
    }
    value[value_length + len] = '\0';
    value_length += len;
    return begin() + index;
}

void EString::clear() noexcept {
    value[0] = '\0';
    value_length = 0;
}

void EString::push_back(value_type ch) {
    if (value_length + 1 > capacity_length) {
        reserve(value_length + 1);
    }
    value[value_length] = ch;
    value[++value_length] = '\0';
}

void EString::pop_back() {
    value[--value_length] = '\0';
}

std::ostream& operator<<(std::ostream& os, const EString& es) {
    os << es.data();
    return os;
}







































