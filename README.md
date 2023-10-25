# An attempt to link boost statically into dynamic library

compile on: Debian 12.1 (bookworm)

This example works well with `set(Boost_USE_STATIC_LIBS OFF)`.
It compile library `liblib_r.so` and executable `test_r`.
However compilation fails for the settings set(Boost_USE_STATIC_LIBS ON) with error:

```console
# /usr/bin/cmake --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++ -S. -Bbuild -G "Unix Makefiles"
Not searching for unused variables given on the command line.
-- The CXX compiler identification is GNU 12.2.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/g++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Boost 1.74.0 at /usr/lib/x86_64-linux-gnu/cmake/Boost-1.74.0
--   Requested configuration: QUIET REQUIRED COMPONENTS regex
-- Found boost_headers 1.74.0 at /usr/lib/x86_64-linux-gnu/cmake/boost_headers-1.74.0
-- Found boost_regex 1.74.0 at /usr/lib/x86_64-linux-gnu/cmake/boost_regex-1.74.0
--   [ ] libboost_regex.so.1.74.0
--   [x] libboost_regex.a
-- Adding boost_regex dependencies: headers
-- Found Boost: /usr/lib/x86_64-linux-gnu/cmake/Boost-1.74.0/BoostConfig.cmake (found version "1.74.0") found components: regex 
-- Configuring done
-- Generating done
-- Build files have been written to: /workspace/github/boost-static/build
```
```
# /usr/bin/cmake --build build --config Debug --target all
[ 25%] Building CXX object src/CMakeFiles/lib_r.dir/lib_r.cc.o
[ 50%] Linking CXX shared library liblib_r.so
/usr/bin/ld: /usr/lib/x86_64-linux-gnu/libboost_regex.a(regex.o): warning: relocation against `_ZTVN5boost10wrapexceptISt11logic_errorEE' in read-only section `.text.unlikely'
/usr/bin/ld: /usr/lib/x86_64-linux-gnu/libboost_regex.a(instances.o): relocation R_X86_64_PC32 against symbol `_ZTVSt15basic_streambufIcSt11char_traitsIcEE@@GLIBCXX_3.4' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: final link failed: bad value
collect2: error: ld returned 1 exit status
gmake[2]: *** [src/CMakeFiles/lib_r.dir/build.make:98: src/liblib_r.so] Error 1
gmake[1]: *** [CMakeFiles/Makefile2:856: src/CMakeFiles/lib_r.dir/all] Error 2
gmake: *** [Makefile:101: all] Error 2
```
