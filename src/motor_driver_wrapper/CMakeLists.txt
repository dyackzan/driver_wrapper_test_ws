cmake_minimum_required(VERSION 3.8)
project(motor_driver_wrapper)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
  add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Werror=unused-but-set-variable
    -Werror=return-type
    -Werror=shadow
    -Werror=format)
endif()

set(THIS_PACKAGE_INCLUDE_DEPENDS rclcpp)

find_package(ament_cmake REQUIRED)
find_package(backward_ros REQUIRED)
foreach(dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
  find_package(${dependency} REQUIRED)
endforeach()

# Motor driver library.
add_library(motor_driver SHARED src/motor_driver.cpp)
target_compile_features(motor_driver PUBLIC cxx_std_17)
target_include_directories(motor_driver PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/motor_driver_wrapper>)
# target_link_libraries(motor_driver PUBLIC Eigen3::Eigen)
ament_target_dependencies(motor_driver PUBLIC ${THIS_PACKAGE_INCLUDE_DEPENDS})

add_executable(motor_driver_node src/motor_driver_node.cpp)
target_compile_features(motor_driver_node PUBLIC cxx_std_17)
ament_target_dependencies(
  motor_driver_node
  "rclcpp"
)
target_include_directories(motor_driver_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(motor_driver_node motor_driver)

install(TARGETS motor_driver_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
