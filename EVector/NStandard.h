#include <memory>

template <typename T>
class NStandard {
public:
    NStandard() = delete;
    explicit NStandard(const T& val);
    explicit NStandard(T&& val) noexcept;
    NStandard(const NStandard& other);
    NStandard& operator=(const NStandard& other);
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
NStandard<T>::NStandard(const NStandard& other) : value(other.value ? std::make_unique<T>(*other.value) : nullptr) {}

template <typename T>
NStandard<T>& NStandard<T>::operator=(const NStandard& other) {
    if (this != &other) {
        value = other.value ? std::make_unique<T>(*other.value) : nullptr;
    }
    return *this;
}

template <typename T>
const T& NStandard<T>::get_value() const {
    return *value;
}
