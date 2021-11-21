#include "../cs225/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

using namespace cs225;

TEST_CASE("Twitch::Makefile", "[weight=1][part=1][valgrind]") {

    std::cout << "\n if this message is showing, our makefile works!" << std::endl;

    REQUIRE( 10 == 10 );
}