cmake_minimum_required(VERSION 3.16)
project(SFMLProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the executable name (change to "pong" or any name for pong.exe, etc.)
set(EXECUTABLE_NAME SFMLTemplate)

# Set output directory for executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create the bin directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Path to SFML (bundled inside your project)
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/external/sfml")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIB_DIR "${SFML_ROOT}/lib")

# Add include and library paths
include_directories(${SFML_INCLUDE_DIR})
include_directories(${SFML_ROOT}/include)
link_directories(${SFML_LIB_DIR})

# Source files
add_executable(${EXECUTABLE_NAME} src/main.cpp)

# Link SFML libraries
target_link_libraries(${EXECUTABLE_NAME}
    sfml-graphics
    sfml-window
    sfml-system
)

# Copy only changed DLLs to build/bin after build
file(GLOB DLL_FILES "${SFML_ROOT}/bin/*.dll")
foreach(DLL ${DLL_FILES})
    add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${DLL}"
        "${CMAKE_BINARY_DIR}/bin"
    )
endforeach()