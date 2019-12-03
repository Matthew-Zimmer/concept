cmake_minimum_required(VERSION 3.13)

project(concept)

add_library(concept INTERFACE)

add_subdirectory(src)
add_subdirectory(include)

target_compile_features(concept INTERFACE cxx_std_17)
	
#Set(CMAKE_CXX_FLAGS "-Wall" "-Wextra")

install(TARGETS concept EXPORT concept DESTINATION lib/concept)
install(EXPORT concept DESTINATION lib/concept)
install(FILES concept-config.cmake DESTINATION lib/concept)