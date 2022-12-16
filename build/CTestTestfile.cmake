# CMake generated Testfile for 
# Source directory: /home/antonio/Escritorio/is/p402
# Build directory: /home/antonio/Escritorio/is/p402/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(UnitTests "runUnitTests")
set_tests_properties(UnitTests PROPERTIES  _BACKTRACE_TRIPLES "/home/antonio/Escritorio/is/p402/CMakeLists.txt;13;add_test;/home/antonio/Escritorio/is/p402/CMakeLists.txt;0;")
subdirs("ext/googletest")
