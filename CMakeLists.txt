cmake_minimum_required(VERSION 3.10)
project(solid_monitor)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Bin)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "PATH_TO_QT/QT_VERSION/QT_ARCH/lib/cmake")

include_directories(
        Src/
        Src/Graphic
        Src/Modules)

add_subdirectory(Src/Graphic/Qt)
add_subdirectory(Src/Modules/Clock)
add_subdirectory(Src/Modules/User)
add_subdirectory(Src/Modules/System)
add_subdirectory(Src/Modules/CPU)
add_subdirectory(Src/Modules/Network)
add_executable(${PROJECT_NAME}
        Src/main.cpp
        Src/Core.cpp
        Src/Core.hpp
        Src/Graphic/IDisplayManager.hpp
        Src/Modules/IModule.hpp
        Src/DLLoader.hpp Src/DLManager.cpp Src/DLManager.hpp Src/types.hpp Src/DataTypes.cpp Src/DataTypes.hpp Src/Data.cpp Src/Data.hpp)



target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} "stdc++fs")

