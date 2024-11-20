# the source of driver_testing basically comes from meekrosoft/fff/examples

set(DRIVER_TESTING_DIR driver_testing)

add_executable(driver_test ${DRIVER_TESTING_DIR}/test/ut_driver_test.c
                           ${DRIVER_TESTING_DIR}/src/driver.c)
target_include_directories(driver_test PUBLIC ${DRIVER_TESTING_DIR}/include)
target_link_libraries(driver_test Unity fff)
target_compile_definitions(driver_test PUBLIC TESTING)

add_test(NAME driver_test COMMAND $<TARGET_FILE:driver_test>)
