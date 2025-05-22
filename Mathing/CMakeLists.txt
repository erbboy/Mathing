# CMakeList.txt: Mathing 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (Mathing "Mathing.cpp" "Mathing.h" "MathAgentDXM.h" "MathType.h" "SphericalHarmonic.h" "SphericalHarmonicImpl.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Mathing PROPERTY CXX_STANDARD 20)
endif()


