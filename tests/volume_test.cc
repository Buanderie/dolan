#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

// Dolan
#include "dolan.h"

// Catch
#include "catch.hpp"

//
#include <iostream>

using namespace std;

TEST_CASE( "Volumes can be created and destroyed", "[Volume]" ) {

    dolan::Tensor<double> t(7,5,3);
    cout << t.sizes()[0] << endl;
    dolan::Tensor<double> t2 = t[0][1];
    cout << "t offset=" << t.sotrageOffset() << endl;
    cout << "t2 offset=" << t2.sotrageOffset() << endl;

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
