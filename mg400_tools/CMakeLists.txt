cmake_minimum_required(VERSION 3.8)
project(mg400_tools)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()
find_package(yaml-cpp REQUIRED)

# command_queue_client ============================
set(TARGET command_queue_client)
ament_auto_add_executable(${TARGET} src/${TARGET}.cpp)
target_link_libraries(${TARGET} yaml-cpp)
unset(TARGET)

# validate_kinematics_with_solutions =============
set(TARGET validate_kinematics_with_solutions)
ament_auto_add_executable(${TARGET} src/${TARGET}.cpp)
ament_target_dependencies(${TARGET} mg400_common)
unset(TARGET)

# install config files ============================
install(
  DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package()
