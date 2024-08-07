#include "EUnorderedMapTest.h"
#include "EUnorderedMap.h"
#include <cassert>
#include "../EString/EString.h"
#include "EStringHash.h"


void EUnorderedMapTest()
{
    // EUnorderedMap(), begin(), end()
    EUnorderedMap<EString, EString> eum_1;
    assert(eum_1.size() == 0);
    assert(eum_1.begin() == eum_1.end());


}