#include "EStringHash.h"


std::size_t hash(const EString& e_string) noexcept
{
    std::size_t hash_value = 0;

    for (char ch : e_string) {
        hash_value = ch + hash_value * 31;
    }

    return hash_value;
}