#include <catch2/catch.hpp>
#include <core/php-detector.h>

TEST_CASE("PHP INSTALLED", "[isPHPInstalled]") {
    REQUIRE(isPHPInstalled());
}