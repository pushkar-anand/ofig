#include <catch2/catch.hpp>
#include <core/core.h>

TEST_CASE("Test PHP detector functions", "[php-detector]") {
    WHEN("PHP is installed") {
        REQUIRE(isPHPInstalled());
        THEN("get PHP config dir") {
            REQUIRE(!getPhpConfigDir().empty());
        }

    }
}
