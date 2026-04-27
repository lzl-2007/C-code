# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/code/week08/lab4/build/_deps/google_benchmark-src"
  "C:/code/week08/lab4/build/_deps/google_benchmark-build"
  "C:/code/week08/lab4/build/_deps/google_benchmark-subbuild/google_benchmark-populate-prefix"
  "C:/code/week08/lab4/build/_deps/google_benchmark-subbuild/google_benchmark-populate-prefix/tmp"
  "C:/code/week08/lab4/build/_deps/google_benchmark-subbuild/google_benchmark-populate-prefix/src/google_benchmark-populate-stamp"
  "C:/code/week08/lab4/build/_deps/google_benchmark-subbuild/google_benchmark-populate-prefix/src"
  "C:/code/week08/lab4/build/_deps/google_benchmark-subbuild/google_benchmark-populate-prefix/src/google_benchmark-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/code/week08/lab4/build/_deps/google_benchmark-subbuild/google_benchmark-populate-prefix/src/google_benchmark-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/code/week08/lab4/build/_deps/google_benchmark-subbuild/google_benchmark-populate-prefix/src/google_benchmark-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
