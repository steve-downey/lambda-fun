add_library(lambda_fun STATIC "")

target_sources(
  lambda_fun
  PRIVATE
  boolean.cpp)

include(GNUInstallDirs)

target_include_directories(lambda_fun PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_LOWER_PROJECT_NAME}>  # <prefix>/include/lambda_fun
  )

install(
  TARGETS lambda_fun
  EXPORT ${TARGETS_EXPORT_NAME}
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

string(TOLOWER ${CMAKE_PROJECT_NAME} CMAKE_LOWER_PROJECT_NAME)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_LOWER_PROJECT_NAME}
  FILES_MATCHING PATTERN "*.h"
  )


## Tests
add_executable(lambda_fun_test "")

target_sources(
  lambda_fun_test
  PRIVATE
  boolean.t.cpp)

target_link_libraries(lambda_fun_test lambda_fun)
target_link_libraries(lambda_fun_test gtest)
target_link_libraries(lambda_fun_test gtest_main)

include(GoogleTest)
gtest_discover_tests(lambda_fun_test)
