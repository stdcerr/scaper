cmake_minimum_required(VERSION 3.1.0)

project(scaper)
set (CMAKE_CXX_STANDARD 11)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
#set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5 COMPONENTS Widgets REQUIRED)
#copy the resource file that specifies the splint options
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/scaper.conf
     DESTINATION $ENV{HOME}/.config/GNU/)

# Populate a CMake variable with the sources
set(SRCS
            main.cpp
            dialog.cpp
            scaper.cpp
            )
#add  Qt .ui form data
qt5_wrap_ui(SRCS scaper.ui)
# Tell CMake to create the multiSCA executable
add_executable(scaper WIN32 ${SRCS})
# Use the Widgets module from Qt 5
target_link_libraries(scaper Qt5::Widgets)
