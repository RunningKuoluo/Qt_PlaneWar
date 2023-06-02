cmake_minimum_required(VERSION 3.5)

project(PlaneWar LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

#add multimedia package
find_package(Qt5 COMPONENTS Multimedia REQUIRED)

if(ANDROID)
  add_library(PlaneWar SHARED
    main.cpp
    mainscene.cpp
    mainscene.h
    config.h
    Map.cpp
    Map.h
    heroplane.cpp
    heroplane.h
    bullet.cpp
    bullet.h
    enemyplane.cpp
    enemyplane.h
    bomb.cpp
    bomb.h
  )
else()
  add_executable(PlaneWar
    main.cpp
    mainscene.cpp
    mainscene.h
    config.h
    Map.cpp
    Map.h
    heroplane.cpp
    heroplane.h
    bullet.cpp
    bullet.h
    enemyplane.cpp
    enemyplane.h
    bomb.cpp
    bomb.h
  )
endif()

target_link_libraries(PlaneWar PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_link_libraries(PlaneWar  PRIVATE Qt5::Multimedia)
