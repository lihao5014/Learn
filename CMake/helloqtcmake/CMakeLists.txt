#（1）QtCreator4.8只是试验性支持cmake，没有提供“Build System”页面，所以不能在新建项目时直接选择cmake构建系统。
#（2）如果想在QtCreator4.8中使用CMake构建项目，那么需要手动创建CMakeLists.txt文件，再使用QtCreator打开CMakeLists.txt文件。
#（3）QtCreator4.8没有CMake项目模板，因此向导里看不到“Build System”下拉框；这是历史原因，不是安装损坏。
#（4）QtCreator4.8对CMake的支持已可用，但需要CMake≥3.5且Qt5以上。
#（5）若想让QtCreator4.8自动识别CMake项目，必须通过“Open CMakeLists.txt”方式；新建向导永远走qmake。
#（6）Qt Creator4.8没有“Build System选CMake”的向导页；直接把写好的CMakeLists.txt拖进Qt Creator打开，
#     就能进入CMake工程模式，无需任何插件升级。

cmake_minimum_required(VERSION 3.10)

#相当于qmake中的TARGET = helloqtcmake
project(helloqtcmake VERSION 1.0 LANGUAGES CXX)

#相当于qmake中config += CONFIG
SET(CMAKE_CXX_STANDARD 11)

#Qt官方推荐的moc、uic和rcc编译器“三自动”写法
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#相当于qmake中的下面三条语句：
#   HEADERS +=  widget.h
#   SOURCES += main.cpp widget.cpp
#   FORMS += widget.ui
add_executable(helloqtcmake
    main.cpp
    widget.h
    widget.cpp
    widget.ui
)

#相当于qmake中的QT += core widgets
find_package(Qt5 REQUIRED COMPONENTS core widgets)

#相当于qmake中的LIBS += -lQt5Core -lQt5Widgets
target_link_libraries(helloqtcmake
    PRIVATE
    Qt5::Core
    Qt5::Widgets
)
