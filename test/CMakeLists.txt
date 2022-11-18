enable_testing()

file(GLOB_RECURSE BPLIB_TEST_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp)

add_executable(
    benchpress_tests
    ${BPLIB_TEST_SOURCE_FILES}
)

target_link_libraries(benchpress_tests GTest::gtest_main bplib)

add_test(
    NAME benchpress_ctest
    COMMAND benchpress_tests
)