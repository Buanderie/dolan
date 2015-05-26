
# Set include directories
include_directories( ${DOLAN_SOURCE_DIR}/lib/include )
include_directories( ${DOLAN_SOURCE_DIR}/extdeps/Catch/include/ )

set( DEPS "${DEPS};dolan" )

file ( GLOB_RECURSE LIBDOLAN_TEST_CPP ./*.cc )

add_executable( dolan_test ${LIBDOLAN_TEST_CPP} )

# Link libraries
target_link_libraries( dolan_test ${DEPS} )

