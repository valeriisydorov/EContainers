#include "EString.h"


EString::EString() : EString("") {}

EString::EString(const value_type* str) : EString(str, std::strlen(str)) {}

EString::EString(const value_type* str, size_type len) : EString(str, str + len) {}

EString::EString(size_type len, value_type ch) : value(nullptr), value_length(len), capacity_length(len) {
    value = allocator.allocate(len + 1);
    for (size_type i = 0; i < len; ++i) {
        value[i] = ch;
    }
    value[len] = '\0';
}

EString::EString(std::initializer_list<value_type> lst) : EString(lst.begin(), lst.end()) {}

EString::EString(const EString& other) : EString(other.begin(), other.end()) {}

EString::EString(const std::string& str) : EString(str.begin(), str.end()) {}

EString::EString(EString&& other) noexcept : EString() {
    swap(other);
}

EString& EString::operator=(const EString& rhs) {
    if (this != &rhs) {
        *this = EString(rhs.data(), rhs.size());
    }
    return *this;
}

EString& EString::operator=(EString&& rhs) noexcept {
    if (this != &rhs) {
        value = nullptr;
        value_length = 0;
        capacity_length = 0;
        swap(rhs);
    }
    return *this;
}

EString& EString::operator=(const std::string& rhs) {
    *this = EString(rhs.data(), rhs.size());
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
    return at(index);
}

const EString::value_type& EString::operator[](size_type index) const {
    return at(index);
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

EString& EString::append(size_type count, value_type ch) {
    return insert(value_length, count, ch);
}

EString& EString::append(const EString& str) {
    return insert(value_length, str);
}

EString& EString::append(const EString& str, size_type pos, size_type count) {
    return insert(value_length, str, pos, count);
}

EString& EString::append(const value_type* str, size_type count) {
    return append(EString(str, count));
}

EString& EString::append(const value_type* str) {
    return append(EString(str));
}

EString& EString::append(std::initializer_list<value_type> lst) {
    return append(lst.begin(), lst.end());
}

EString& EString::append(const std::string& str) {
    return append(EString(str));
}

EString& EString::append(const std::string& str, size_type pos, size_type count) {
    return append(EString(str), pos, count);
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

EString::iterator EString::erase(const_iterator pos) {
    difference_type index = pos - begin();
    if (index >= value_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    for (size_type i = index; i < value_length - 1; ++i) {
        value[i] = value[i + 1];
    }
    value[--value_length] = '\0';
    return begin() + index;
}

EString::iterator EString::erase(const_iterator first, const_iterator last) {
    difference_type index = first - begin();
    difference_type second_index = last - begin();
    if (index >= value_length || second_index > value_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    size_type len = second_index - index;
    for (size_type i = index; i < value_length - len; ++i) {
        value[i] = value[i + len];
    }
    value[value_length - len] = '\0';
    value_length -= len;
    return begin() + index;
}

EString& EString::replace(size_type pos, size_type count, const EString& str, size_type pos_second, size_type count_second) {
    if (pos >= value_length || pos_second >= str.value_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    if (pos + count > value_length || pos_second + count_second > str.value_length) {
        throw std::out_of_range("out_of_range: Count out of bounds.");
    }
    size_type len = value_length - count + count_second;
    if (len > capacity_length) {
        reserve(len);
    }
    if (count_second < count) {
        size_type offset = count - count_second;
        for (size_type i = pos + count_second; i <= value_length; ++i) {
            value[i - offset] = value[i];
        }
    } else if (count_second > count) {
        size_type offset = count_second - count;
        for (size_type i = value_length; i >= pos + count; --i) {
            value[i + offset] = value[i];
        }
    }
    for (size_type i = 0; i < count_second; ++i) {
        value[pos + i] = str.value[pos_second + i];
    }
    value[len] = '\0';
    value_length = len;
    return *this;
}

EString& EString::replace(const_iterator first, const_iterator last, std::initializer_list<value_type> lst) {
    return replace(first - begin(), last - first, EString(lst), 0, lst.size());
}

EString::size_type EString::copy(value_type* dest, size_type count, size_type pos) const {
    if (pos >= value_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    size_type avail_count = value_length - pos;
    size_type real_count = count < avail_count ? count : avail_count;
    for (size_type i = 0; i < real_count; ++i) {
        dest[i] = value[pos + i];
    }
    return real_count;
}

void EString::resize(size_type count, char ch) noexcept {
    if (count <= value_length) {
        value[count] = '\0';
        value_length = count;
    } else {
        reserve(count);
        for (size_type i = 0; i < count - value_length; ++i) {
            value[value_length + i] = ch;
        }
        value[count] = '\0';
        value_length = count;
    }
}

void EString::resize(size_type count) noexcept {
    resize(count, '\0');
}

void EString::swap(EString& other) {
    using std::swap;
    swap(value, other.value);
    swap(value_length, other.value_length);
    swap(capacity_length, other.capacity_length);
}

EString EString::substr(size_type pos, size_type count) const {
    if (pos >= value_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    if (pos + count > value_length) {
        throw std::out_of_range("out_of_range: Count out of bounds.");
    }
    return EString(value + pos, count);
}

std::ostream& operator<<(std::ostream& os, const EString& str) {
    os << str.data();
    return os;
}

std::istream& operator>>(std::istream& is, EString& str) {
    str.clear();
    char ch;
    while (is.get(ch)) {
        if (ch == '\n' || ch == EOF) {
            break;
        }
        if (str.value_length == str.capacity_length) {
            str.reserve(str.capacity_length * 2);
        }
        str.push_back(ch);
    }
    return is;
}

EString operator+(const EString& lhs, const EString& rhs) {
    EString result(lhs);
    result.append(rhs);
    return result;
}

EString operator+(const EString& lhs, const EString::value_type* rhs) {
    EString result(lhs);
    result.append(rhs);
    return result;
}

EString operator+(const EString& lhs, EString::value_type rhs) {
    EString result(lhs);
    result.append(1, rhs);
    return result;
}

EString operator+(const EString& lhs, const std::string& rhs) {
    EString result(lhs);
    result.append(rhs);
    return result;
}

EString operator+(const EString::value_type* lhs, const EString& rhs) {
    EString result(lhs);
    result.append(rhs);
    return result;
}

EString operator+(EString::value_type lhs, const EString& rhs) {
    EString result(rhs);
    result.insert(result.begin(), lhs);
    return result;
}

EString operator+(const std::string& lhs, const EString& rhs) {
    EString result(lhs);
    result.append(rhs);
    return result;
}

EString operator+(EString&& lhs, EString&& rhs) {
    EString result(std::move(lhs));
    result.append(std::move(rhs));
    return result;
}

EString operator+(EString&& lhs, const EString& rhs) {
    EString result(std::move(lhs));
    result.append(rhs);
    return result;
}

EString operator+(EString&& lhs, const EString::value_type* rhs) {
    EString result(std::move(lhs));
    result.append(rhs);
    return result;
}

EString operator+(EString&& lhs, EString::value_type rhs) {
    EString result(std::move(lhs));
    result.append(1, rhs);
    return result;
}

EString operator+(EString&& lhs, const std::string& rhs) {
    EString result(std::move(lhs));
    result.append(rhs);
    return result;
}

EString operator+(const EString& lhs, EString&& rhs) {
    EString result(lhs);
    result.append(std::move(rhs));
    return result;
}

EString operator+(const EString::value_type* lhs, EString&& rhs) {
    EString result(lhs);
    result.append(std::move(rhs));
    return result;
}

EString operator+(EString::value_type lhs, EString&& rhs) {
    EString result(std::move(rhs));
    result.insert(result.begin(), lhs);
    return result;
}

EString operator+(const std::string& lhs, EString&& rhs) {
    EString result(lhs);
    result.append(std::move(rhs));
    return result;
}

bool operator==(const EString& lhs, const EString& rhs) noexcept {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    EString::const_iterator it1 = lhs.begin();
    EString::const_iterator it2 = rhs.begin();
    for (; it1 != lhs.end(); ++it1, ++it2) {
        if (*it1 != *it2) {
            return false;
        }
    }
    return true;
}

bool operator==(const EString& lhs, const EString::value_type* rhs) noexcept {
    size_t len = std::strlen(rhs);
    if (lhs.size() != len) {
        return false;
    }
    EString::const_iterator it1 = lhs.begin();
    const EString::value_type* it2 = rhs;
    for (; it1 != lhs.end(); ++it1, ++it2) {
        if (*it1 != *it2) {
            return false;
        }
    }
    return true;
}

bool operator==(const EString& lhs, const std::string& rhs) noexcept {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    EString::const_iterator it1 = lhs.begin();
    std::string::const_iterator it2 = rhs.begin();
    for (; it1 != lhs.end(); ++it1, ++it2) {
        if (*it1 != *it2) {
            return false;
        }
    }
    return true;
}

bool operator==(const EString::value_type* lhs, const EString& rhs) noexcept {
    size_t len = std::strlen(lhs);
    if (len != rhs.size()) {
        return false;
    }
    const EString::value_type* it1 = lhs;
    EString::const_iterator it2 = rhs.begin();
    for (; it2 != rhs.end(); ++it1, ++it2) {
        if (*it1 != *it2) {
            return false;
        }
    }
    return true;
}

bool operator==(const std::string& lhs, const EString& rhs) noexcept {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    std::string::const_iterator it1 = lhs.begin();
    EString::const_iterator it2 = rhs.begin();
    for (; it1 != lhs.end(); ++it1, ++it2) {
        if (*it1 != *it2) {
            return false;
        }
    }
    return true;
}

bool operator!=(const EString& lhs, const EString& rhs) noexcept {
    return !(lhs == rhs);
}

bool operator!=(const EString& lhs, const EString::value_type* rhs) noexcept {
    return !(lhs == rhs);
}

bool operator!=(const EString& lhs, const std::string& rhs) noexcept {
    return !(lhs == rhs);
}

bool operator!=(const EString::value_type* lhs, const EString& rhs) noexcept {
    return !(lhs == rhs);
}

bool operator!=(const std::string& lhs, const EString& rhs) noexcept {
    return !(lhs == rhs);
}

bool operator<(const EString& lhs, const EString& rhs) noexcept {
    EString::const_iterator it1 = lhs.begin();
    EString::const_iterator it2 = rhs.begin();
    for (; it1 != lhs.end() && it2 != rhs.end(); ++it1, ++it2) {
        if (*it1 < *it2) {
            return true;
        } else if (*it1 > *it2) {
            return false;
        }
    }
    return lhs.size() < rhs.size();
}

bool operator<(const EString& lhs, const EString::value_type* rhs) noexcept {
    EString::const_iterator it1 = lhs.begin();
    const EString::value_type* it2 = rhs;
    for (; it1 != lhs.end() && *it2 != '\0'; ++it1, ++it2) {
        if (*it1 < *it2) {
            return true;
        } else if (*it1 > *it2) {
            return false;
        }
    }
    size_t len = std::strlen(rhs);
    return lhs.size() < len;
}

bool operator<(const EString& lhs, const std::string& rhs) noexcept {
    EString::const_iterator it1 = lhs.begin();
    std::string::const_iterator it2 = rhs.begin();
    for (; it1 != lhs.end() && it2 != rhs.end(); ++it1, ++it2) {
        if (*it1 < *it2) {
            return true;
        } else if (*it1 > *it2) {
            return false;
        }
    }
    return lhs.size() < rhs.size();
}

bool operator<(const EString::value_type* lhs, const EString& rhs) noexcept {
    const EString::value_type* it1 = lhs;
    EString::const_iterator it2 = rhs.begin();
    for (; *it1 != '\0' && it2 != rhs.end(); ++it1, ++it2) {
        if (*it1 < *it2) {
            return true;
        } else if (*it1 > *it2) {
            return false;
        }
    }
    size_t len = std::strlen(lhs);
    return len < rhs.size();
}

bool operator<(const std::string& lhs, const EString& rhs) noexcept {
    std::string::const_iterator it1 = lhs.begin();
    EString::const_iterator it2 = rhs.begin();
    for (; it1 != lhs.end() && it2 != rhs.end(); ++it1, ++it2) {
        if (*it1 < *it2) {
            return true;
        } else if (*it1 > *it2) {
            return false;
        }
    }
    return lhs.size() < rhs.size();
}

bool operator>(const EString& lhs, const EString& rhs) noexcept {
    return !(lhs < rhs) && (lhs != rhs);
}

bool operator>(const EString& lhs, const EString::value_type* rhs) noexcept {
    return !(lhs < rhs) && (lhs != rhs);
}

bool operator>(const EString& lhs, const std::string& rhs) noexcept {
    return !(lhs < rhs) && (lhs != rhs);
}

bool operator>(const EString::value_type* lhs, const EString& rhs) noexcept {
    return !(lhs < rhs) && (lhs != rhs);
}

bool operator>(const std::string& lhs, const EString& rhs) noexcept {
    return !(lhs < rhs) && (lhs != rhs);
}

bool operator<=(const EString& lhs, const EString& rhs) noexcept {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator<=(const EString& lhs, const EString::value_type* rhs) noexcept {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator<=(const EString& lhs, const std::string& rhs) noexcept {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator<=(const EString::value_type* lhs, const EString& rhs) noexcept {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator<=(const std::string& lhs, const EString& rhs) noexcept {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator>=(const EString& lhs, const EString& rhs) noexcept {
    return (lhs > rhs) || (lhs == rhs);
}

bool operator>=(const EString& lhs, const EString::value_type* rhs) noexcept {
    return (lhs > rhs) || (lhs == rhs);
}

bool operator>=(const EString& lhs, const std::string& rhs) noexcept {
    return (lhs > rhs) || (lhs == rhs);
}

bool operator>=(const EString::value_type* lhs, const EString& rhs) noexcept {
    return (lhs > rhs) || (lhs == rhs);
}

bool operator>=(const std::string& lhs, const EString& rhs) noexcept {
    return (lhs > rhs) || (lhs == rhs);
}

int EString::compare(const EString& str) const noexcept {
    if (*this < str) {
        return -1;
    } else if (*this > str) {
        return 1;
    }
    return 0;
}

int EString::compare(size_type pos, size_type count, const EString& str) const {
    EString sub = this->substr(pos, count);
    return sub.compare(str);
}

int EString::compare(size_type pos1, size_type count1, const EString& str, size_type pos2, size_type count2) const {
    EString sub1 = this->substr(pos1, count1);
    EString sub2 = str.substr(pos2, count2);
    return sub1.compare(sub2);
}

int EString::compare(const value_type* str) const {
    return compare(EString(str));
}

int EString::compare(size_type pos, size_type count, const value_type* str) const {
    EString sub = this->substr(pos, count);
    return sub.compare(EString(str));
}

int EString::compare(size_type pos1, size_type count1, const value_type* str, size_type pos2, size_type count2) const {
    EString sub1 = this->substr(pos1, count1);
    EString sub2 = EString(str).substr(pos2, count2);
    return sub1.compare(sub2);
}

int EString::compare(const std::string& str) const noexcept {
    return compare(EString(str));
}

int EString::compare(size_type pos, size_type count, const std::string& str) const {
    EString sub = this->substr(pos, count);
    return sub.compare(EString(str));
}

int EString::compare(size_type pos1, size_type count1, const std::string& str, size_type pos2, size_type count2) const {
    EString sub1 = this->substr(pos1, count1);
    EString sub2 = EString(str).substr(pos2, count2);
    return sub1.compare(sub2);
}

EString::size_type EString::find(const EString& str, size_type pos) const noexcept {
    if (pos >= value_length || value_length - pos < str.value_length) {
        return npos;
    }
    for (size_type i = pos; i <= value_length - str.value_length; ++i) {
        for (size_type j = 0; j < str.value_length; ++j) {
            if (at(i + j) != str[j]) {
                break;
            } else if (j == str.value_length - 1) {
                return i;
            }
        }
    }
    return npos;
}

EString::size_type EString::find(const value_type* str, size_type pos, size_type count) const {
    if (pos >= value_length || std::strlen(str) < count || value_length - pos < count) {
        return npos;
    }
    if (count == 0) {
        return pos;
    }
    for (size_type i = pos; i <= value_length - count; ++i) {
        for (size_type j = 0; j < count; ++j) {
            if (at(i + j) != str[j]) {
                break;
            } else if (j == count - 1) {
                return i;
            }
        }
    }
    return npos;
}

EString::size_type EString::find(const value_type* str, size_type pos) const {
    return find(str, pos, std::strlen(str));
}

EString::size_type EString::find(const std::string& str, size_type pos, size_type count) const {
    if (pos >= value_length || str.size() < count || value_length - pos < count) {
        return npos;
    }
    if (count == 0) {
        return pos;
    }
    for (size_type i = pos; i <= value_length - count; ++i) {
        for (size_type j = 0; j < count; ++j) {
            if (at(i + j) != str[j]) {
                break;
            } else if (j == count - 1) {
                return i;
            }
        }
    }
    return npos;
}

EString::size_type EString::find(const std::string& str, size_type pos) const {
    return find(str, pos, str.size());
}

EString::size_type EString::find(value_type ch, size_type pos) const noexcept {
    if (pos >= value_length) {
        return npos;
    }
    for (size_type i = pos; i <= value_length; ++i) {
        if (at(i) == ch) {
            return i;
        }
    }
    return npos;
}

EString::size_type EString::rfind(const EString& str, size_type pos) const noexcept {
    if (pos == npos) {
        pos = value_length;
    }
    if (pos > value_length || pos < str.value_length) {
        return npos;
    }
    for (size_type i = pos; i >= str.value_length; --i) {
        for (size_type j = 0; j < str.value_length; ++j) {
            if (at(i - str.value_length + j) != str[j]) {
                break;
            } else if (j == str.value_length - 1) {
                return i - str.value_length;
            }
        }
    }
    return npos;
}

EString::size_type EString::rfind(const value_type* str, size_type pos, size_type count) const {
    if (pos > value_length || std::strlen(str) < count || pos < count) {
        return npos;
    }
    if (count == 0) {
        return pos;
    }
    for (size_type i = pos; i >= count; --i) {
        for (size_type j = 0; j < count; ++j) {
            if (at(i - count + j) != str[j]) {
                break;
            } else if (j == count - 1) {
                return i - count;
            }
        }
    }
    return npos;
}

EString::size_type EString::rfind(const value_type* str, size_type pos) const {
    if (pos == npos) {
        pos = value_length;
    }
    return rfind(str, pos, std::strlen(str));
}








