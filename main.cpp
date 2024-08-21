#include "EString/EStringTest.h"
#include "EList/EListTest.h"
#include "EVector/EVectorTest.h"
#include "ESet/ESetTest.h"
#include "EUnorderedMap/EUnorderedMapTest.h"


int main() {
    EStringTest();
    EListTest();
    EVectorTest();
    ESetTest();
    EUnorderedMapTest();

    return 0;
}