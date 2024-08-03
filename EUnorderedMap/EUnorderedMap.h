#pragma once

#include <cstddef>
#include <stdexcept>
#include <functional>


template<typename K, typename V, typename H = std::hash<K>>
class EUnorderedMap
{
public:
    class Iterator;

    using key_type = K;
    using size_type = std::size_t;
    using iterator = Iterator;

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

// insert(Key, Value)
// remove by key
// remove by value

// Value& operator[](const Key&) - adds new element if not present. Investigate possible issues with this approach.
// Value* find(const Key&) - may return nullptr
// findByValue - find key by value

private:

};

