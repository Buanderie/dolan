include_directories( ${LIBDOLAN_SOURCE_DIR}/include )

add_executable( example1 main.cc )
target_link_libraries( example1 dolan )
