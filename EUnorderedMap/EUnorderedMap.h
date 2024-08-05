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
    using value_type = Entry;
    using iterator = Iterator;
    using entry_type = Entry;
    using entry_pointer_type = entry_type*;
    using bucket_type = EList<entry_type>;
    using data_type = EVector<bucket_type>;
    using hash_function_type = H;


    class Iterator
    {
        friend class EUnorderedMap;
        // friend bool operator==(const Iterator& lhs, const Iterator& rhs);
        // friend bool operator!=(const Iterator& lhs, const Iterator& rhs);

    public:
        using reference = value_type&;
        using container_pointer_type = const EUnorderedMap<key_type, mapped_type>*;

        Iterator();
        Iterator(entry_pointer_type curr, container_pointer_type cont);
        Iterator(const Iterator& other) = default;
        Iterator(Iterator&& other) noexcept = default;
        Iterator& operator=(const Iterator& rhs) = default;
        Iterator& operator=(Iterator&& rhs) noexcept = default;

        ~Iterator() = default;

        reference operator*() const;

        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);

    private:
        entry_pointer_type current;
        container_pointer_type container;
    };

    EUnorderedMap();
    explicit EUnorderedMap(const hash_function_type& hash);
    EUnorderedMap(const EUnorderedMap& other);
    EUnorderedMap(EUnorderedMap&& other) noexcept;
    EUnorderedMap& operator=(const EUnorderedMap& rhs);
    EUnorderedMap& operator=(EUnorderedMap&& rhs) noexcept;

    ~EUnorderedMap() = default;

    iterator begin() noexcept;
    iterator begin() const noexcept;
    iterator end() noexcept;
    iterator end() const noexcept;

    size_type size() const;

    void clear();
    iterator insert(key_type key, mapped_type value, bool* is_in_map = nullptr);
    iterator remove_by_value(const mapped_type& value);
    size_type remove_by_key(const key_type& key);

    mapped_type& operator[](const key_type& key);
    mapped_type* find_value(const key_type& key) const;
    const key_type* find_key(const mapped_type& value) const;

private:
    class Entry
    {
        friend class EUnorderedMap;

    public:
        Entry() = delete;
        explicit Entry(key_type key, mapped_type value);
        Entry(const Entry& other) = default;
        Entry(Entry&& other) noexcept = default;
        Entry& operator=(const Entry& rhs) = default;
        Entry& operator=(Entry&& rhs) noexcept = default;

        ~Entry() = default;

        void set_key(key_type key);
        void set_value(mapped_type value);
        key_type get_key() const;
        mapped_type get_value() const;

    private:
        key_type entry_key;
        mapped_type entry_value;

    };

    data_type container_of_buckets;
    hash_function_type hash_function;
    size_type number_of_buckets;
    size_type number_of_entries;

    static constexpr size_type start_number_of_buckets = 7;
    static constexpr double min_load_factor = 0.25;
    static constexpr double max_load_factor = 0.75;

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
EUnorderedMap<K, V, H>::EUnorderedMap(const hash_function_type& hash)
    : container_of_buckets()
    , hash_function(hash)
    , number_of_buckets(start_number_of_buckets)
    , number_of_entries(0)
{
    container_of_buckets.resize(start_number_of_buckets);
}

template <typename K, typename V, typename H>
typename EUnorderedMap<K, V, H>::size_type
EUnorderedMap<K, V, H>::size() const
{
    return number_of_entries;
}