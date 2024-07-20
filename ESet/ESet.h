#pragma once


template <typename K>
class ESet {

public:

    class Iterator {

    public:

    private:

    };

    ESet();
    ESet(const ESet& other);
    ESet(ESet&& other) noexcept;
    ESet& operator=(const ESet& rhs);
    ESet& operator=(ESet&& rhs) noexcept;
    ~ESet();

    // iterator begin();
    // iterator end();

    bool empty() const;
    // size_type size();

    void clear();
    // bool insert(const key_type& key);
    // size_type remove(const key_type& key);
    // iterator remove_at(iterator pos);

    // iterator find(const key_type& key);
    // bool contains(const key_type& key) const;

private:

    class Node {

    public:

    private:

    };

};