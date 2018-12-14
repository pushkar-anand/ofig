#include <catch2/catch.hpp>
#include <core/core.h>

TEST_CASE("PHP INSTALLED", "[isPHPInstalled]") {
    REQUIRE(isPHPInstalled());
}