#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "complex.h"

TEST_CASE("Complex default ctor") {
    Complex z;

    REQUIRE(z.real() == 0.0);
    REQUIRE(z.imag() == 0.0);
}

TEST_CASE("Complex single value ctor") {
    SECTION("z = 0.0") {
        Complex z(0.0);

        REQUIRE(z.real() == 0.0);
        REQUIRE(z.imag() == 0.0);
    }

    SECTION("z = 1.0") {
        Complex z(1.0);

        REQUIRE(z.real() == 1.0);
        REQUIRE(z.imag() == 0.0);
    }
}

TEST_CASE("Complex double value ctor") {
    SECTION("z = 0.0") {
        Complex z(0.0, 0.0);

        REQUIRE(z.real() == 0.0);
        REQUIRE(z.imag() == 0.0);
    }

    SECTION("z = 1.0") {
        Complex z(1.0, 0.0);

        REQUIRE(z.real() == 1.0);
        REQUIRE(z.imag() == 0.0);
    }

    SECTION("z = 1.0i") {
        Complex z(0.0, 1.0);

        REQUIRE(z.real() == 0.0);
        REQUIRE(z.imag() == 1.0);
    }

    SECTION("z = 1.0 + 1.0i") {
        Complex z(1.0, 1.0);

        REQUIRE(z.real() == 1.0);
        REQUIRE(z.imag() == 1.0);
    }

    SECTION("z = 2.0 + 1.0i") {
        Complex z(2.0, 1.0);

        REQUIRE(z.real() == 2.0);
        REQUIRE(z.imag() == 1.0);
    }
}
