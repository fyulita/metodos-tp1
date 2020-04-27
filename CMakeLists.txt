# Mínima versión de CMake requerida.
cmake_minimum_required(VERSION 3.6)

# Nombre del proyecto. En general va a ser el mismo que el nombre
# del directorio en donde está el CMakeLists.txt.
project(tp01)

# Versión de C++ a utilizar. En Algoritmos 1 usamos C++11.
set(CMAKE_CXX_STANDARD 11)

# Dice cuáles son los archivos que van a tener el código
# de nuestro proyecto. Acá solo hace falta poner los .cpp.
# OJO: Hay que poner los .cpp con el directorio en el que están
# adentro del proyecto.
set(SOURCE_FILES main.cpp
        funciones-principales.cpp
        funciones-secundarias.cpp
        definiciones.h)

# Dice cuál va a ser el nombre del archivo ejecutable,
# y qué .cpp va a tener. Acá le decimos que se va a llamar solucion,
# y que va a tener los archivos .cpp
# que estén en la variable SOURCE_FILES, que seteamos en la línea anterior.
add_executable(tp01 ${SOURCE_FILES})

# Agrega más opciones a la compilación.
# -g: Hace que podamos debuggear el programa.
set(CMAKE_CXX_FLAGS "-g")
# Un temita de gcov que no se lleva tan bien con CMake,
# y entonces hay que poner esta línea.
# Para más información, ver https://texus.me/2015/09/06/cmake-and-gcov/.
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# Acá le decimos que ponga nuestro ejecutable en la misma
# carpeta en la que está el CMakeLists.txt.
# Esto es para que no lo ponga en la carpeta CMakeFiles.
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
