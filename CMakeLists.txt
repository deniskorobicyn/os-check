cmake_minimum_required(VERSION 2.8.11)

project(OS_Check)
# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Declarative REQUIRED)
include_directories(${Qt5Widgets_INCLUDES})
add_definitions(${Qt5Widgets_DEFINITIONS})
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

SET(PROJECT_SOURCES main.cpp mainwindow.cpp)
SET(PROJECT_FORMS mainwindow.ui)
QT5_WRAP_CPP(helloworld_HEADERS_MOC ${PROJECT_SOURCES})
QT5_WRAP_UI(helloworld_FORMS_HEADERS ${PROJECT_FORMS})


set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

# Tell CMake to create the helloworld executable
add_executable(OS_Check ${PROJECT_SOURCES} )

# Use the Widgets module from Qt 5.
target_link_libraries(OS_Check ${Qt5Widgets_LIBRARIES})
