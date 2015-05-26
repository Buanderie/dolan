cmake_minimum_required(VERSION 2.8)
project (LIBDOLAN)

# Set custom cmake scripts directory
set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${LIBDOLAN_SOURCE_DIR}/cmake")

# Set include directories
include_directories( ${LIBDOLAN_SOURCE_DIR}/include )

# Add Dynamic Library Loader dependency (if UNIX-based)
#if( ${MAROILLES_CURRENT_SYSTEM} STREQUAL "LINUX" )
#	set( DEPS "${DEPS};dl" )
#endif()

file ( GLOB_RECURSE DOLAN_CPP ./src/*.cc )

set( ALL_CPP ${DOLAN_CPP} )

if( ${DOLAN_CURRENT_SYSTEM} STREQUAL "WINDOWS" )
  add_library( dolan ${ALL_CPP} )
else()
  add_library( dolan SHARED ${ALL_CPP} )
endif()

# Link libraries
target_link_libraries( dolan ${DEPS} )
