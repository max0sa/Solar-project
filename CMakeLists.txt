cmake_minimum_required(VERSION 3.19)
project(pruebaproyecysolar LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(pruebaproyecysolar
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    calculadora_c++.h
    funciones_c++.cpp
)

target_link_libraries(pruebaproyecysolar
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS pruebaproyecysolar
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET pruebaproyecysolar
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
