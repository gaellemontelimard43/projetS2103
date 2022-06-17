cmake_minimum_required(VERSION 3.10)

project(nomprojet VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
add_executable(main src/view/main.cpp src/view/MyControlPanel.cpp src/view/MyDrawingPanel.cpp src/view/MyFrame.cpp src/model/Dessin.cpp src/model/Forme.cpp src/model/Cercle.cpp src/model/Ligne.cpp src/model/Point.cpp src/model/Rectangle.cpp)
target_link_libraries(main ${wxWidgets_LIBRARIES})
