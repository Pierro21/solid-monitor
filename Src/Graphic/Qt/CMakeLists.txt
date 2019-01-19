cmake_minimum_required(VERSION 3.10)
project(QtDisplayManager)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Libs/Graphic)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "PATH_TO_QT/QT_VERSION/QT_ARCH/lib/cmake")

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(..)

add_library(${PROJECT_NAME} SHARED
        ../IDisplayManager.hpp DisplayManager.cpp DisplayManager.hpp Entrypoint.cpp ../../types.hpp AddWidget.cpp AddWidget.hpp Menu.cpp Menu.hpp TabManager.cpp TabManager.hpp ../../DataTypes.cpp ../../DataTypes.hpp WidgetItem.cpp WidgetItem.hpp TabView.cpp TabView.hpp Tab.cpp Tab.hpp ../../Data.cpp ../../Data.hpp)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)