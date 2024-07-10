#pragma once


#include <memory>
#include <utility>


template <typename T>
class NStandard {
public:
    NStandard() = delete;
    explicit NStandard(const T& val);
    explicit NStandard(T&& val) noexcept;
    NStandard(const NStandard& other) = delete;
    NStandard(NStandard&& other) = delete;
    NStandard& operator=(const NStandard& other) = delete;
    NStandard& operator=(NStandard&& other) = delete;
    ~NStandard() = default;

    const T& get_value() const;

private:
    std::unique_ptr<T> value;
};

template <typename T>
NStandard<T>::NStandard(const T &val) : value(std::make_unique<T>(val)) {}

template <typename T>
NStandard<T>::NStandard(T&& val) noexcept : value(std::make_unique<T>(std::move(val))) {}

template <typename T>
const T& NStandard<T>::get_value() const {
    return *value;
}