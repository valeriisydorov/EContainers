#include "EUnorderedMapTest.h"
#include "EUnorderedMap.h"
#include <cassert>
#include "../EString/EString.h"
#include "EStringHash.h"


void EUnorderedMapTest()
{
    auto HashEString = [](const EString& e_string) noexcept
    {
        return hash(e_string);
    };

    // EUnorderedMap(), EUnorderedMap(const hash_function_type& hash)
    EUnorderedMap<int, EString> eum_1_1;
    EUnorderedMap<EString, EString, decltype(HashEString)> eum_1_2(HashEString);
    assert(eum_1_1.size() == 0);
    assert(eum_1_2.size() == 0);



}