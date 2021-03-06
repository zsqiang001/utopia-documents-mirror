###############################################################################
#   
#    This file is part of the Utopia Documents application.
#        Copyright (c) 2008-2014 Lost Island Labs
#            <info@utopiadocs.com>
#    
#    Utopia Documents is free software: you can redistribute it and/or modify
#    it under the terms of the GNU GENERAL PUBLIC LICENSE VERSION 3 as
#    published by the Free Software Foundation.
#    
#    Utopia Documents is distributed in the hope that it will be useful, but
#    WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
#    Public License for more details.
#    
#    In addition, as a special exception, the copyright holders give
#    permission to link the code of portions of this program with the OpenSSL
#    library under certain conditions as described in each individual source
#    file, and distribute linked combinations including the two.
#    
#    You must obey the GNU General Public License in all respects for all of
#    the code used other than OpenSSL. If you modify file(s) with this
#    exception, you may extend this exception to your version of the file(s),
#    but you are not obligated to do so. If you do not wish to do so, delete
#    this exception statement from your version.
#    
#    You should have received a copy of the GNU General Public License
#    along with Utopia Documents. If not, see <http://www.gnu.org/licenses/>
#   
###############################################################################

project(ambrosia)

set(SOURCES
  ambrosia.cpp
  ambrosiawidget.cpp
  bond.cpp
  buffer.cpp
  buffermanager.cpp
  colour.cpp
  colourscheme.cpp
  renderable.cpp
  selection.cpp
  shader.cpp
  token.cpp
  utils.cpp
  )

set(MOC_HEADERS
  ambrosiawidget.h
  )

if(WIN32)
    add_definitions(-DBUILD_LIBAMBROSIA=1)
    add_definitions(-DGLEW_STATIC=1)
endif()

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${QGLViewer_INCLUDE_DIR}
  ${gtl_INCLUDE_DIR}
  ${utopia2_INCLUDE_DIR}
  ${utopia2_qt_INCLUDE_DIR}
  ${GLEW_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  )

QT4_WRAP_CPP(MOC_SOURCES ${MOC_HEADERS} )
QT4_ADD_RESOURCES(RES_SOURCES ${RESOURCES})

add_utopia_library( ${PROJECT_NAME} SHARED ${SOURCES} ${MOC_SOURCES} ${RES_SOURCES})

target_link_libraries(${PROJECT_NAME} utopia2 utopia2_qt gtl ${QT_LIBRARIES} ${GLEW_LIBRARIES} ${QGLViewer_LIBRARIES} ${Boost_LIBRARIES} )

install_utopia_library(${PROJECT_NAME} "${COMPONENT}")
