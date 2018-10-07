QT -= gui
QT += serialport

CONFIG += c++14 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basealgo/arraytype.cpp \
    basealgo/fileio.cpp \
    basealgo/fitmethod.cpp \
    basealgo/matrix.cpp \
    basealgo/matrixsolver.cpp \
    basealgo/point2d.cpp \
    basealgo/point2dprocess.cpp \
    connect/connect.cpp \
    mapmethod/mapmethod.cpp \
    sim/deadzone.cpp \
    sim/diff.cpp \
    sim/gain.cpp \
    sim/integrate.cpp \
    sim/limit_integrate.cpp \
    sim/step.cpp \
    sim/sturation.cpp \
    sim/sum.cpp \
    sim/switch_sturation.cpp \
    sim/test_sim.cpp \
    simcurve/algo.cpp \
    simcurve/model.cpp \
    simcurve/simrun.cpp \
    test/test.cpp \
    test/test_fit_method.cpp \
    test/test_mapmethod.cpp \
    test/test_matrix_solver.cpp \
    test/test_point2d.cpp \
    main.cpp \
    sim32process.cpp \
    connect/serial_connect.cpp \
    basealgo/my_deque.cpp

HEADERS += \
    basealgo/arraytype.h \
    basealgo/fileio.h \
    basealgo/fitmethod.h \
    basealgo/matrix.h \
    basealgo/matrixsolver.h \
    basealgo/point2d.h \
    basealgo/point2dprocess.h \
    basealgo/typedef.h \
    connect/connect.h \
    mapmethod/mapmethod.h \
    sim/deadzone.h \
    sim/diff.h \
    sim/gain.h \
    sim/integrate.h \
    sim/limit_integrate.h \
    sim/sim.h \
    sim/step.h \
    sim/sturation.h \
    sim/sum.h \
    sim/switch_sturation.h \
    sim/typedefine.h \
    simcurve/algo.h \
    simcurve/include.h \
    simcurve/model.h \
    simcurve/simrun.h \
    test/test.h \
    test/test_fit_method.h \
    test/test_mapmethod.h \
    test/test_matrix_solver.h \
    test/test_point2d.h \
    sim32process.h \
    connect/serial_connect.h \
    basealgo/my_deque.h
