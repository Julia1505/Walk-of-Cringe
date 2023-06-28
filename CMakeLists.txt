cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Set project name and version
project(War_of_Crinje_prev)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug 
    CACHE STRING 
      "Choose the type of build (Debug or Release)" 
      FORCE
    )
endif()


# Find SFML shared libraries
find_package(SFML
  COMPONENTS 
    system window graphics network audio REQUIRED
  )

# Compile executable
add_executable(SFMLBoilerplate src/main.cpp src/map.cpp src/player.cpp src/camera.cpp)

# Set include directory search paths
target_include_directories(SFMLBoilerplate 
  PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Link executable to required SFML libraries
target_link_libraries(SFMLBoilerplate sfml-graphics sfml-window sfml-system)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

include(GNUInstallDirs)
install(
    TARGETS SFMLBoilerplate
    RUNTIME_DEPENDENCIES
        DIRECTORIES
)

# Install target
install(TARGETS SFMLBoilerplate DESTINATION bin)