
# library
add_library(lib_r SHARED lib_r.cc)
target_link_libraries(lib_r PRIVATE Boost::regex)

# executable
add_executable(test_r main_r.cc)
target_link_libraries(test_r PRIVATE lib_r)

add_test(run_executable test_r)
