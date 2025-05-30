/****************************************************************************
 * libs/libc/unistd/lib_chdir.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "libc.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: chdir
 *
 * Description:
 *   The chdir() function causes the directory named by the pathname pointed
 *   to by the 'path' argument to become the current working directory; that
 *   is, the starting point for path searches for pathnames not beginning
 *   with '/'.
 *
 * Input Parameters:
 *   path - A pointer to a directory to use as the new current working
 *     directory
 *
 * Returned Value:
 *   0(OK) on success; -1(ERROR) on failure with errno set appropriately:
 *
 *   EACCES
 *     Search permission is denied for any component of the pathname.
 *   ELOOP
 *     A loop exists in symbolic links encountered during resolution of the
 *     'path' argument OR more that SYMLOOP_MAX symbolic links in the
 *     resolution of the 'path' argument.
 *   ENAMETOOLONG
 *     The length of the path argument exceeds PATH_MAX or a pathname
 *     component is longer than NAME_MAX.
 *   ENOENT
 *     A component of 'path' does not name an existing directory or path is
 *     an empty string.
 *   ENOTDIR
 *     A component of the pathname is not a directory.
 *
 ****************************************************************************/

int chdir(FAR const char *path)
{
  FAR char *oldpwd = NULL;
  FAR char *abspath;
  struct stat buf;
  int ret;

  /* Verify that 'path' refers to a directory */

  ret = stat(path, &buf);
  if (ret < 0)
    {
      return ret;
    }

  /* Something exists here... is it a directory? */

  if (!S_ISDIR(buf.st_mode))
    {
      set_errno(ENOTDIR);
      return ERROR;
    }

  /* Yes, it is a directory.
   * Remove any trailing '/' characters from the path
   */

  abspath = lib_get_pathbuffer();
  if (abspath != NULL)
    {
      oldpwd = realpath(path, abspath);
    }

  if (abspath == NULL || oldpwd == NULL)
    {
      lib_put_pathbuffer(abspath);
      return ERROR;
    }

#ifndef CONFIG_DISABLE_ENVIRON

  /* Replace any preceding OLDPWD with the current PWD (this is to
   * support 'cd -' in NSH)
   */

  oldpwd = getenv("PWD");
  if (!oldpwd)
    {
      oldpwd = CONFIG_LIBC_HOMEDIR;
    }

  setenv("OLDPWD", oldpwd, TRUE);

  /* Set the cwd to the input 'path' */

  ret = setenv("PWD", abspath, TRUE);
#endif /* !CONFIG_DISABLE_ENVIRON */

  lib_put_pathbuffer(abspath);

  return ret;
}
