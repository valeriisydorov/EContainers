#pragma once


#include <cstddef>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <cstdlib>
#include <cstring>


template <typename T>
class EVector {
    class Iterator;
    class ConstIterator;

    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;

    class Iterator {
        friend class EVector;
        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.current == rhs.current) && (lhs.container == rhs.container);
        }
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return !(lhs == rhs);
        }

    public:
        using pointer_type = value_type*;
        using reference = value_type&;
        using container_pointer = EVector<value_type>*;

        Iterator();
        Iterator(pointer_type curr, container_pointer cont);
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
        container_pointer container;
    };

    class ConstIterator {
        friend class EVector;
        friend bool operator==(const ConstIterator& lhs, const ConstIterator& rhs) {
            return (lhs.current == rhs.current) && (lhs.container == rhs.container);
        }
        friend bool operator!=(const ConstIterator& lhs, const ConstIterator& rhs) {
            return !(lhs == rhs);
        }

    public:
        using pointer_type = const value_type*;
        using reference = const value_type&;
        using container_pointer = const EVector<value_type>*;

        ConstIterator();
        ConstIterator(pointer_type curr, container_pointer cont);
        ConstIterator(const Iterator& it);
        ConstIterator(const ConstIterator& other) = default;
        ConstIterator(ConstIterator&& other) noexcept = default;
        ConstIterator& operator=(const ConstIterator& rhs) = default;
        ConstIterator& operator=(ConstIterator&& rhs) noexcept = default;

        ~ConstIterator() = default;

        reference operator*() const;

        ConstIterator& operator++();
        ConstIterator operator++(int);
        ConstIterator& operator--();
        ConstIterator operator--(int);

    private:
        pointer_type current;
        container_pointer container;
    };

public:
    using iterator = Iterator;
    using const_iterator = ConstIterator;

    EVector();
    EVector(size_type count, const value_type& value);
    EVector(const EVector& other);
    EVector(EVector&& other) noexcept;
    EVector& operator=(const EVector& rhs);
    EVector& operator=(EVector&& rhs) noexcept;
    ~EVector();

    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

    iterator begin() noexcept;
    const_iterator cbegin() noexcept;
    iterator end() noexcept;
    const_iterator cend() noexcept;

    size_type size() const;
    size_type capacity() const;
    void reserve(size_type new_cap);

    size_type insert(size_type pos, const value_type& value);
    iterator insert(const_iterator it, const value_type& value);
    size_type erase(size_type pos);
    iterator erase(value_type& value);
    void push_back(const value_type& value);
    void push_back(value_type&& value);
    void resize(size_type count);

    bool contains(const value_type& value) const;
    iterator find(const value_type& value);
    const_iterator find(const value_type& value) const;

private:
    value_type* data;
    size_type data_length;
    size_type capacity_length;

    static constexpr size_type start_capacity_length = 2;

    void move_procedure(
            value_type* dest,
            value_type* src,
            size_type start,
            size_type end,
            size_type dest_offs = 0,
            size_type src_offs = 0
    );
};


template <typename T>
EVector<T>::EVector()
: data(static_cast<T*>(std::malloc(start_capacity_length * sizeof(value_type))))
, data_length(0)
, capacity_length(start_capacity_length)
{
    if (!data) {
        throw std::bad_alloc();
    }
}

template <typename T>
EVector<T>::EVector(size_type count, const value_type& value) : EVector() {
    reserve(count);
    for (size_type i = 0; i < count; ++i) {
        push_back(value);
    }
}

template <typename T>
EVector<T>::EVector(const EVector& other)
: data(new value_type[other.capacity_length])
, data_length(other.data_length)
, capacity_length(other.capacity_length)
{
    for (size_type i = 0; i < data_length; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
EVector<T>::EVector(EVector&& other) noexcept
: data(other.data)
, data_length(other.data_length)
, capacity_length(other.capacity_length)
{
    other.data = nullptr;
    other.data_length = 0;
    other.capacity_length = 0;
}

template <typename T>
EVector<T>& EVector<T>::operator=(const EVector& rhs) {
    if (this != &rhs) {
        value_type* new_data = new value_type[rhs.capacity_length];
        for (size_type i = 0; i < rhs.data_length; ++i) {
            new_data[i] = rhs.data[i];
        }
        delete[] data;
        data = new_data;
        data_length = rhs.data_length;
        capacity_length = rhs.capacity_length;
    }
    return *this;
}

template <typename T>
EVector<T>& EVector<T>::operator=(EVector&& rhs) noexcept {
    if (this != &rhs) {
        delete[] data;
        data = rhs.data;
        data_length = rhs.data_length;
        capacity_length = rhs.capacity_length;
        rhs.data = nullptr;
        rhs.data_length = 0;
        rhs.capacity_length = 0;
    }
    return *this;
}

template <typename T>
EVector<T>::~EVector() {
    if (data) {
        if constexpr (!std::is_trivially_destructible_v<value_type>) {
            for (std::size_t i = 0; i < data_length; ++i) {
                data[i].~value_type();
            }
        }
        std::free(data);
    }
    data = nullptr;
    data_length = 0;
    capacity_length = 0;
}

template <typename T>
typename EVector<T>::reference
EVector<T>::operator[](size_type pos) {
    if (pos >= data_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    return data[pos];
}

template <typename T>
typename EVector<T>::const_reference
EVector<T>::operator[](size_type pos) const {
    if (pos >= data_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    return data[pos];
}

template <typename T>
typename EVector<T>::iterator
EVector<T>::begin() noexcept {
    return iterator(data, this);
}

template <typename T>
typename EVector<T>::const_iterator
EVector<T>::cbegin() noexcept {
    return const_iterator(data, this);
}

template <typename T>
typename EVector<T>::iterator
EVector<T>::end() noexcept {
    return iterator(data + data_length, this);
}

template <typename T>
typename EVector<T>::const_iterator
EVector<T>::cend() noexcept {
    return const_iterator(data + data_length, this);
}

template <typename T>
typename EVector<T>::size_type
EVector<T>::size() const {
    return data_length;
}

template <typename T>
typename EVector<T>::size_type
EVector<T>::capacity() const {
    return capacity_length;
}

template <typename T>
void EVector<T>::reserve(size_type new_cap) {
    if (new_cap > capacity_length) {
        value_type* new_data = static_cast<value_type*>(std::malloc(new_cap * sizeof(value_type)));
        if (!new_data) {
            throw std::bad_alloc();
        }
        if (data_length) {
            move_procedure(new_data, data, 0, data_length);
        }
        std::free(data);
        data = new_data;
        capacity_length = new_cap;
    }
}

template <typename T>
typename EVector<T>::size_type
EVector<T>::insert(size_type pos, const value_type& value) {
    if (pos > data_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    if (pos == data_length) {
        push_back(value);
    } else if (pos < data_length) {
        if (data_length + 1 > capacity_length) {
            value_type* new_data = new value_type[capacity_length * 2];
            move_procedure(new_data, data, 0, pos);
            new_data[pos] = value;
            move_procedure(new_data, data, pos, data_length, 1);
            delete[] data;
            data = new_data;
            capacity_length = capacity_length * 2;
        } else {
            for (size_type i = data_length; i > pos; --i) {
                data[i] = std::move(data[i - 1]);
            }
            data[pos] = value;
        }
        data_length++;
    }
    return pos;
}

template <typename T>
typename EVector<T>::iterator
EVector<T>::insert(const_iterator it, const value_type& value) {
    if (it.container != this) {
        throw std::invalid_argument("invalid_argument: Invalid iterator for the EVector.");
    }
    const size_type index = it.current - data;
    insert(index, value);
    return iterator(data + index, this);
}

template <typename T>
typename EVector<T>::size_type
EVector<T>::erase(size_type pos) {
    if (pos >= data_length) {
        throw std::out_of_range("out_of_range: Position out of bounds.");
    }
    if (pos < data_length - 1) {
        move_procedure(data, data, pos, data_length - 1, 0, 1);
    }
    data_length--;
    if constexpr (!std::is_trivially_destructible_v<value_type>) {
        data[data_length].~value_type();
    }
    if (pos < data_length) {
        return pos;
    } else {
        return data_length;
    }
}

template <typename T>
typename EVector<T>::iterator
EVector<T>::erase(value_type& value) {
    iterator it = find(value);
    if (it != end()) {
        const size_type index = it.current - data;
        erase(index);
        it = iterator(data + index, this);
    }
    return it;
}

template <typename T>
void EVector<T>::push_back(const value_type& value) {
    if (data_length == capacity_length) {
        reserve(capacity_length * 2);
    }
    new(&data[data_length++]) value_type(value);
}

template <typename T>
void EVector<T>::push_back(value_type&& value) {
    if (data_length == capacity_length) {
        reserve(capacity_length * 2);
    }
    new(&data[data_length++]) value_type(std::move(value));
}

template <typename T>
void EVector<T>::resize(size_type count) {
    if (data_length == count) {
        return;
    }
    if (count < data_length) {
        for (size_type i = count; i < data_length; ++i) {
            if constexpr (!std::is_trivially_destructible_v<value_type>) {
                data[i].~value_type();
            }
        }
    } else if (count > data_length) {
        if (count > capacity_length) {
            reserve(count);
        }
        for (size_type i = data_length; i < count; ++i) {
            if constexpr (std::is_default_constructible_v<value_type>) {
                new(&data[i]) value_type();
            }
        }
    }
    data_length = count;
}

template <typename T>
bool EVector<T>::contains(const value_type& value) const {
    return find(value) != end();
}

template <typename T>
typename EVector<T>::iterator
EVector<T>::find(const value_type& value) {
    for (iterator it = begin(); it != end(); ++it) {
        if (*it == value) {
            return it;
        }
    }
    return end();
}

template <typename T>
typename EVector<T>::const_iterator
EVector<T>::find(const value_type& value) const {
    for (const_iterator it = cbegin(); it != cend(); ++it) {
        if (*it == value) {
            return it;
        }
    }
    return cend();
}

template <typename T>
void EVector<T>::move_procedure(
        value_type* dest,
        value_type* src,
        size_type start,
        size_type end,
        size_type dest_offs,
        size_type src_offs
) {
    for (size_type i = start; i < end; ++i) {
        std::memmove(&dest[i + dest_offs], &src[i + src_offs], sizeof(value_type));
    }
}

template <typename T>
EVector<T>::iterator::Iterator()
: current(nullptr)
, container(nullptr)
{}

template <typename T>
EVector<T>::iterator::Iterator(pointer_type curr, container_pointer cont)
: current(curr)
, container(cont)
{}

template <typename T>
typename EVector<T>::iterator::reference
EVector<T>::iterator::operator*() {
    if (current == nullptr || current >= container->data + container->data_length) {
        throw std::runtime_error("runtime_error: Attempt to dereference a null iterator.");
    }
    return *current;
}

template <typename T>
typename EVector<T>::iterator&
EVector<T>::iterator::operator++() {
    if (current == nullptr || current >= container->data + container->data_length) {
        throw std::out_of_range("out_of_range: Cannot increment iterator past the ending of EVector.");
    }
    ++current;
    return *this;
}

template <typename T>
typename EVector<T>::iterator
EVector<T>::iterator::operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
typename EVector<T>::iterator&
EVector<T>::iterator::operator--() {
    if (current == nullptr || current <= container->data) {
        throw std::out_of_range("out_of_range: Cannot decrement iterator past the beginning of of EVector.");
    }
    --current;
    return *this;
}

template <typename T>
typename EVector<T>::iterator
EVector<T>::iterator::operator--(int) {
    iterator temp = *this;
    --(*this);
    return temp;
}

template <typename T>
EVector<T>::const_iterator::ConstIterator()
: current(nullptr)
, container(nullptr)
{}

template <typename T>
EVector<T>::const_iterator::ConstIterator(pointer_type curr, container_pointer cont)
: current(curr)
, container(cont)
{}

template <typename T>
typename EVector<T>::const_iterator::reference
EVector<T>::const_iterator::operator*() const {
    if (current == nullptr || current >= container->data + container->data_length) {
        throw std::runtime_error("runtime_error: Attempt to dereference a null iterator.");
    }
    return *current;
}

template <typename T>
typename EVector<T>::const_iterator&
EVector<T>::const_iterator::operator++() {
    if (current == nullptr || current >= container->data + container->data_length) {
        throw std::out_of_range("out_of_range: Cannot increment iterator past the ending of EVector.");
    }
    ++current;
    return *this;
}

template <typename T>
typename EVector<T>::const_iterator
EVector<T>::const_iterator::operator++(int) {
    const_iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
typename EVector<T>::const_iterator&
EVector<T>::const_iterator::operator--() {
    if (current == nullptr || current <= container->data) {
        throw std::out_of_range("out_of_range: Cannot decrement iterator past the beginning of of EVector.");
    }
    --current;
    return *this;
}

template <typename T>
typename EVector<T>::const_iterator
EVector<T>::const_iterator::operator--(int) {
    const_iterator temp = *this;
    --(*this);
    return temp;
}