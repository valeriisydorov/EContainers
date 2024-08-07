#pragma once

#include <functional>
#include "../EString/EString.h"


namespace std {
    template <>
    struct hash<EString>
    {
        std::size_t operator()(const EString& e_string) const noexcept
        {
            std::size_t hash_value = 0;
            for (char ch : e_string)
            {
                hash_value = ch + hash_value * 31;
            }

            return hash_value;
        }
    };
}
