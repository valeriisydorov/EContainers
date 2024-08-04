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

    using entry_pointer_type = Entry*;
public:
    class Iterator;

    using key_type = K;
    using mapped_type = V;
    using size_type = std::size_t;
    using value_type = Entry;
    using iterator = Iterator;

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
    EUnorderedMap(const EUnorderedMap& other);
    EUnorderedMap(EUnorderedMap&& other) noexcept;
    EUnorderedMap& operator=(const EUnorderedMap& rhs);
    EUnorderedMap& operator=(EUnorderedMap&& rhs) noexcept;

    ~EUnorderedMap();

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

};

