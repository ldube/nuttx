# ##############################################################################
# fs/CMakeLists.txt
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

if(NOT "${CONFIG_FS_HEAPBUF_SECTION}" STREQUAL "")
  target_compile_definitions(
    fs PRIVATE FS_HEAPBUF_SECTION=${CONFIG_FS_HEAPBUF_SECTION})
endif()

nuttx_add_kernel_library(fs fs_initialize.c fs_heap.c)
nuttx_add_subdirectory()
target_include_directories(fs PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                                      ${NUTTX_DIR}/sched)
