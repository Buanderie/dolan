#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

// Dolan
#include "dolan.h"

// Catch
#include "catch.hpp"

TEST_CASE( "Volumes can be created and destroyed", "[Volume]" ) {

    dolan::Volumef* vol = 0;

    SECTION( "Volumes can be created" )
    {
        REQUIRE_NOTHROW( vol = new dolan::Volumef(10,10,10) );
    }

    SECTION( "Volumes can be destroyed" )
    {
        REQUIRE_NOTHROW( delete vol );
    }

    vol = 0;
}

TEST_CASE( "You can't create a Volume of size 0 (any dimension)", "[Volume]" )
{
    dolan::Volumef* vol;
    REQUIRE_THROWS( vol = new dolan::Volumef(0,0,0) );
}
