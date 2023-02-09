cmake_minimum_required(VERSION 3.5)

project(SmartCalculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cc
        ./view/calcView.cc
        ./view/calcView.h
        ./view/calcView.ui
        ./controller/calcController.cc
        ./model/calcModel.cc
        ./controller/calcController.h
        ./model/calcModel.h
        ./model/token.h
        ./model/token.cc
        ./model/tokenizator.cc
        ./model/tokenizator.h
        ./model/validator.h
        ./model/validator.cc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartCalculator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SmartCalculator APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SmartCalculator SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SmartCalculator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SmartCalculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(SmartCalculator PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalculator)
endif()
