cmake_minimum_required(VERSION 3.8)
project(TPs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        tools/fileUtils.c
        tools/fileUtils.h
        tools/matrix.c
        tools/matrix.h
        tools/point.c
        tools/point.h
        tp1-bezierEval/bezier2d.c
        tp1-bezierEval/bezier2d.h
        tp2-bezierSubdiv/bezier2d.c
        tp2-bezierSubdiv/bezier2d.h
        tp2-bezierSubdiv/bezierSubdivision.c
        tp2-bezierSubdiv/bezierSubdivision.h
        tp3-interpolation/interpolation.c
        tp6-CarreauBezier/bezierPatch.c
        tp6-CarreauBezier/bezierPatch.h
        tp6-CarreauBezier/controlNetwork.c
        tp6-CarreauBezier/controlNetwork.h)

set(CARREAU_BEZIER_SOURCES_FILES
        tools/fileUtils.c
        tools/fileUtils.h
        tools/matrix.c
        tools/matrix.h
        tools/point.c
        tools/point.h
        tp6-CarreauBezier/bezierPatch.c
        tp6-CarreauBezier/bezierPatch.h
        tp6-CarreauBezier/controlNetwork.c
        tp6-CarreauBezier/controlNetwork.h )

add_executable(carreauBezier ${CARREAU_BEZIER_SOURCES_FILES})