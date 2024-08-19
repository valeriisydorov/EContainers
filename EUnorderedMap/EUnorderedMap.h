#pragma once

#include <cstddef>
#include <stdexcept>
#include <functional>
#include "../EVector/EVector.h"
#include "../EList/EList.h"


template<typename K, typename V, typename H = std::hash<K>>
class EUnorderedMap
{
    class Entry;

public:
    class Iterator;

    using key_type = K;
    using mapped_type = V;
    using size_type = std::size_t;
    using iterator = Iterator;
    using entry_type = Entry;
    using entry_pointer_type = entry_type*;
    using bucket_type = EList<entry_type>;
    using bucket_type_iterator = typename bucket_type::iterator;
    using data_type = EVector<bucket_type>;
    using hash_function_type = H;

    class Iterator
    {
        friend class EUnorderedMap;
        friend bool operator==(const Iterator& lhs, const Iterator& rhs)
        {
            return (lhs.current == rhs.current)
                && (lhs.current_bucket_index == rhs.current_bucket_index)
                && (lhs.container == rhs.container);
        }
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs)
        {
            return !(lhs == rhs);
        }

    public:
        using reference = entry_type&;
        using container_pointer_type = EUnorderedMap<key_type, mapped_type>*;

        Iterator();
        Iterator(entry_pointer_type curr, size_type buck_index, container_pointer_type cont);
        Iterator(const Iterator& other) = default;
        Iterator(Iterator&& other) noexcept = default;
        Iterator& operator=(const Iterator& rhs) = default;
        Iterator& operator=(Iterator&& rhs) noexcept = default;

        ~Iterator() = default;

        reference operator*() const;

        Iterator& operator++();
        Iterator operator++(int);

        const key_type& get_key() const;
        mapped_type& get_value();
        const mapped_type& get_value() const;

    private:
        entry_pointer_type current;
        size_type current_bucket_index;
        container_pointer_type container;

        static constexpr size_type no_bucket_index = -1;
    };

    EUnorderedMap();
    EUnorderedMap(const EUnorderedMap& other) = default;
    EUnorderedMap(EUnorderedMap&& other) noexcept = default;
    EUnorderedMap& operator=(const EUnorderedMap& rhs) = default;
    EUnorderedMap& operator=(EUnorderedMap&& rhs) noexcept = default;

    ~EUnorderedMap() = default;

    iterator begin() noexcept;
    iterator begin() const noexcept;
    iterator end() noexcept;
    iterator end() const noexcept;

    size_type size() const;

    void clear();
    iterator insert(key_type key, mapped_type value);
    iterator remove_by_value(const mapped_type& value);
    size_type remove_by_key(const key_type& key);

    mapped_type& operator[](const key_type& key);
    mapped_type* find_value(const key_type& key);
    const mapped_type* find_value(const key_type& key) const;
    const key_type* find_key(const mapped_type& value);

private:
    class Entry
    {
        friend class EUnorderedMap;
        friend class Iterator;

        friend bool operator==(const Entry& lhs, const Entry& rhs) {
            return lhs.entry_key == rhs.entry_key && lhs.entry_value == rhs.entry_value;
        }

        friend bool operator!=(const Entry& lhs, const Entry& rhs) {
            return !(lhs == rhs);
        }

    public:
        Entry() = delete;
        explicit Entry(key_type key, mapped_type value);
        Entry(const Entry& other) = default;
        Entry(Entry&& other) noexcept = default;
        Entry& operator=(const Entry& rhs) = default;
        Entry& operator=(Entry&& rhs) noexcept = default;

        ~Entry() = default;

    private:
        const key_type entry_key;
        mapped_type entry_value;

    };

    data_type container_of_buckets;
    hash_function_type hash_function;
    size_type number_of_buckets;
    size_type number_of_entries;

    static constexpr size_type start_number_of_buckets = 7;
    static constexpr double max_load_factor = 0.75;

    size_type bucket_index(const key_type& key) const;
    bucket_type& get_bucket(const key_type& key);
    void rehash(size_type new_number_of_buckets);

};


template <typename K, typename V, typename H>
EUnorderedMap<K, V, H>::EUnorderedMap()
    : container_of_buckets()
    , hash_function(hash_function_type())
    , number_of_buckets(start_number_of_buckets)
    , number_of_entries(0)
{
    container_of_buckets.resize(start_number_of_buckets);
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::iterator EUnorderedMap<K, V, H>::begin() noexcept
{
    for (size_type index_of_bucket = 0; index_of_bucket < number_of_buckets; ++index_of_bucket)
    {
        bucket_type& bucket = container_of_buckets[index_of_bucket];
        if (bucket.size() != 0)
        {
            entry_pointer_type entry_pointer = &(*bucket.begin());

            return iterator(entry_pointer, index_of_bucket, this);
        }
    }

    return end();
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::iterator EUnorderedMap<K, V, H>::begin() const noexcept
{
    for (size_type index_of_bucket = 0; index_of_bucket < number_of_buckets; ++index_of_bucket)
    {
        const bucket_type& bucket = container_of_buckets[index_of_bucket];
        if (bucket.size() != 0)
        {
            entry_pointer_type entry_pointer = &(*bucket.begin());

            return iterator(entry_pointer, index_of_bucket, this);
        }
    }

    return end();
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::iterator EUnorderedMap<K, V, H>::end() noexcept
{
    return iterator(nullptr, iterator::no_bucket_index, this);
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::iterator EUnorderedMap<K, V, H>::end() const noexcept
{
    return iterator(nullptr, iterator::no_bucket_index, this);
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::size_type EUnorderedMap<K, V, H>::size() const
{
    return number_of_entries;
}

template <typename K, typename V, typename H>
void EUnorderedMap<K, V, H>::clear()
{
    for (size_type i = 0; i < number_of_buckets; ++i)
    {
        container_of_buckets[i].clear();
    }
    number_of_entries = 0;
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::iterator EUnorderedMap<K, V, H>::insert(key_type key, mapped_type value)
{
    if (number_of_entries > number_of_buckets * max_load_factor)
    {
        rehash(number_of_buckets * 2);
    }

    size_type index_of_bucket = bucket_index(key);
    bucket_type& bucket = container_of_buckets[index_of_bucket];

    for (entry_type& entry : bucket)
    {
        if (entry.entry_key == key)
        {
            entry.entry_value = value;

            return iterator(&entry, index_of_bucket, this);
        }
    }

    entry_type new_entry(key, value);
    bucket.push_back(new_entry);
    number_of_entries++;

    bucket_type_iterator last_entry_iterator = bucket.end() - 1;
    entry_pointer_type entry_pointer = &(*last_entry_iterator);

    return iterator(entry_pointer, index_of_bucket, this);
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::iterator EUnorderedMap<K, V, H>::remove_by_value(const mapped_type& value)
{
    for (iterator it = begin(); it != end(); ++it)
    {
        if (it.get_value() == value)
        {
            bucket_type& bucket = container_of_buckets[it.current_bucket_index];
            iterator removed_it = it++;
            bucket.remove(*removed_it);
            number_of_entries--;

            return it;
        }
    }

    return end();
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::size_type EUnorderedMap<K, V, H>::remove_by_key(const key_type& key)
{
    size_type result = 0;
    bucket_type& bucket = get_bucket(key);

    for (entry_type& entry : bucket)
    {
        if (entry.entry_key == key)
        {
            bucket.remove(entry);
            number_of_entries--;
            result = 1;

            break;
        }
    }

    return result;
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::mapped_type& EUnorderedMap<K, V, H>::operator[](const key_type& key)
{
    mapped_type* value = find_value(key);

    if (value != nullptr)
    {
        return *value;
    } else {
        iterator it = insert(key, mapped_type{});

        return it.get_value();
    }

}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::mapped_type* EUnorderedMap<K, V, H>::find_value(const key_type& key)
{
    bucket_type& bucket = get_bucket(key);

    for (entry_type& entry : bucket)
    {
        if (entry.entry_key == key)
        {
            return &entry.entry_value;
        }
    }

    return nullptr;
}

template <typename K, typename V, typename H>
const typename EUnorderedMap<K, V, H>::mapped_type* EUnorderedMap<K, V, H>::find_value(const key_type& key) const
{
    const bucket_type& bucket = get_bucket(key);

    for (const entry_type& entry : bucket)
    {
        if (entry.entry_key == key)
        {
            return &entry.entry_value;
        }
    }

    return nullptr;
}

template <typename K, typename V, typename H>
const typename EUnorderedMap<K, V, H>::key_type* EUnorderedMap<K, V, H>::find_key(const mapped_type& value)
{
    for (iterator it = begin(); it != end(); ++it)
    {
        if (it.get_value() == value)
        {
            return &it.get_key();
        }
    }

    return nullptr;
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::size_type EUnorderedMap<K, V, H>::bucket_index(const key_type& key) const
{
    return hash_function(key) % number_of_buckets;
}

template <typename K, typename V, typename H>
void EUnorderedMap<K, V, H>::rehash(size_type new_number_of_buckets)
{
    data_type new_container_of_buckets;
    new_container_of_buckets.resize(new_number_of_buckets);

    for (iterator it = begin(); it != end(); ++it)
    {
        size_type new_bucket_index = bucket_index(it.get_key());
        new_container_of_buckets[new_bucket_index].push_back(*it);
    }

    number_of_buckets = new_number_of_buckets;
    container_of_buckets = std::move(new_container_of_buckets);
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::bucket_type& EUnorderedMap<K, V, H>::get_bucket(const key_type& key)
{
    size_type index_of_bucket = bucket_index(key);
    return container_of_buckets[index_of_bucket];
}

template <typename K, typename V, typename H>
EUnorderedMap<K, V, H>::Entry::Entry(key_type key, mapped_type value)
    : entry_key(key)
    , entry_value(value)
{
}

template <typename K, typename V, typename H>
EUnorderedMap<K, V, H>::Iterator::Iterator()
    : current(nullptr)
    , current_bucket_index(no_bucket_index)
    , container(nullptr)
{
}

template <typename K, typename V, typename H>
EUnorderedMap<K, V, H>::Iterator::Iterator(
    entry_pointer_type curr,
    size_type buck_index,
    container_pointer_type cont
)
    : current(curr)
    , current_bucket_index(buck_index)
    , container(cont)
{
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::Iterator::reference EUnorderedMap<K, V, H>::Iterator::operator*() const
{
    if (current == nullptr)
    {
        throw std::out_of_range("out_of_range: Dereferencing a null iterator.");
    }

    return *current;
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::Iterator& EUnorderedMap<K, V, H>::Iterator::operator++()
{
    if (current == nullptr)
    {
        throw std::out_of_range("out_of_range: Cannot increment iterator past the ending of EUnorderedMap.");
    }

    bucket_type& current_bucket = container->container_of_buckets[current_bucket_index];
    bucket_type_iterator bucket_iterator = current_bucket.begin();

    for (; bucket_iterator != current_bucket.end(); ++bucket_iterator)
    {
        if (*bucket_iterator == *current)
        {
            break;
        }
    }

    if (bucket_iterator != current_bucket.end() && ++bucket_iterator != current_bucket.end())
    {
        current = &(*bucket_iterator);
    } else {
        current = nullptr;

        for (size_type index = current_bucket_index + 1; index < container->number_of_buckets; ++index)
        {
            bucket_type& next_bucket = container->container_of_buckets[index];

            if (next_bucket.size() != 0)
            {
                current_bucket_index = index;
                current = &(*next_bucket.begin());

                break;
            }
        }

        if (current == nullptr)
        {
            current_bucket_index = no_bucket_index;
        }
    }

    return *this;
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::Iterator EUnorderedMap<K, V, H>::Iterator::operator++(int)
{
    iterator temp = *this;
    ++(*this);

    return temp;
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::mapped_type& EUnorderedMap<K, V, H>::Iterator::get_value()
{
    return current->entry_value;
}

template <typename K, typename V, typename H>
const typename EUnorderedMap<K, V, H>::mapped_type& EUnorderedMap<K, V, H>::Iterator::get_value() const
{
    return current->entry_value;
}

template <typename K, typename V, typename H>
const typename EUnorderedMap<K, V, H>::key_type& EUnorderedMap<K, V, H>::Iterator::get_key() const
{
    return current->entry_key;
}