# CMake generated Testfile for 
# Source directory: /home/elena/myproyect
# Build directory: /home/elena/myproyect/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(UnitTests "runUnitTests")
set_tests_properties(UnitTests PROPERTIES  _BACKTRACE_TRIPLES "/home/elena/myproyect/CMakeLists.txt;14;add_test;/home/elena/myproyect/CMakeLists.txt;0;")
subdirs("ext/googletest")
