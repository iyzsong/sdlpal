# Copyright (c) 2024, SDLPAL development team.
# All rights reserved.
#
# This file is part of SDLPAL.
#
# SDLPAL is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License, version 3
# as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.9)
project(sdlpal C CXX)


file(GLOB SOURCES
  *.c
  ../*.c ../*.cpp
  ../adplug/*.c ../adplug/*.cpp
  ../timidity/*.c
)

add_executable(sdlpal ${SOURCES})
target_include_directories(sdlpal PRIVATE
  .
  ..
  ../timidity
  /opt/miyoo/arm-miyoo-linux-musleabi/sysroot/usr/include/SDL
)
target_link_libraries(sdlpal SDL)
