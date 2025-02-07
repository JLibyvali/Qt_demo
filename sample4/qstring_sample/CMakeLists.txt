cmake_minimum_required ( VERSION 3.5 )

project ( qstring_sample VERSION 0.1 LANGUAGES CXX )

# ---------------------------------------------------------------------------------------------------------------------------
# include modules
# ---------------------------------------------------------------------------------------------------------------------------
include ( cmake/api.cmake )

# include ( cmake/toolchain.cmake )

# ---------------------------------------------------------------------------------------------------------------------------
# Set Qt
# ---------------------------------------------------------------------------------------------------------------------------
set ( CMAKE_AUTOUIC ON )
set ( CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR} ) # For custom ui_xxxx.h found
set ( CMAKE_AUTOMOC ON )
set ( CMAKE_AUTORCC ON )

set ( QT_DEBUG_FIND_PACAKGE ON )
find_package ( QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets )
find_package ( Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets )

set ( Docorator_SRCS
    Docorators/SetTop.hpp
)

set ( Action_SRCS
    Actions/InputGroup.hpp
    Actions/TestGroup.hpp
)

set ( PROJECT_SOURCES
        ${Docorator_SRCS}
        ${Action_SRCS}
        main.cpp
        mainwindow.cpp
        mainwindow.hpp
        TopWindow.ui
)

# ---------------------------------------------------------------------------------------------------------------------------
# Add executable, non platform dependent settings.
# ---------------------------------------------------------------------------------------------------------------------------
add_executable ( qstring_sample
    ${PROJECT_SOURCES}
)
target_link_libraries ( qstring_sample PRIVATE Qt${QT_VERSION_MAJOR}::Widgets )
