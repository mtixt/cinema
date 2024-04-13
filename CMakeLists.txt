cmake_minimum_required(VERSION 3.5)

project(Cinema VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(SQLite::SQLite3)
find_package(Qt6 REQUIRED COMPONENTS Sql)

set(PROJECT_SOURCES
        main.cpp
        cinema.cpp
        cinema.h
        cinema.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Cinema
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        date.h date.cpp
        time.h time.cpp
        human.h human.cpp
        client.h client.cpp
        ticket.h ticket.cpp
        director.h director.cpp
        film.h film.cpp
        actor.h actor.cpp
        seat.h seat.cpp
        session.h session.cpp
        hall.h hall.cpp
        saveandload.h saveandload.cpp
        filmspage.h filmspage.cpp
        filmview.h filmview.cpp filmview.ui
        filmedit.h filmedit.cpp filmedit.ui
        actorspage.h actorspage.cpp
        actorview.h actorview.cpp actorview.ui


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Cinema APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Cinema SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Cinema
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Cinema PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Cinema)
endif()
set_target_properties(Cinema PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Cinema
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Cinema)
endif()

if(SQLite3_FOUND)
    include_directories(${SQLITE_INCLUDE_DIRS})
    target_link_libraries(Cinema, ${SQLITE3_LIBRARIES})
endif(SQLite3_FOUND)

target_link_libraries(Cinema PRIVATE Qt6::Sql)
