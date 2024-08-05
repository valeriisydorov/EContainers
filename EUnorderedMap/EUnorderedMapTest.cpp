#include "EUnorderedMapTest.h"
#include "EUnorderedMap.h"
#include <cassert>
#include "../EString/EString.h"
#include "EStringHash.h"


void EUnorderedMapTest()
{
    auto e_string_hash = [](const EString& e_string) noexcept
    {
        return hash(e_string);
    };

    // EUnorderedMap(), EUnorderedMap(const hash_function_type& hash)
    EUnorderedMap<int, EString> un_map_0_1;
    EUnorderedMap<EString, EString, decltype(e_string_hash)> un_map_0_2(e_string_hash);
    assert(un_map_0_1.size() == 0);
    assert(un_map_0_2.size() == 0);



}