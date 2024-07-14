cmake_minimum_required(VERSION 3.0)
project(ASFML)

# Aggiungi la directory di SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Imposta l'eseguibile del progetto e aggiungi i file sorgente
add_executable(ASFML
        main.cpp
        Node.h
        Node.cpp
        Grid.h
        Grid.cpp
        Character.h
        Character.cpp
        Astar.h
        Astar.cpp
        Game.h
        Game.cpp
)

# Collega SFML alle librerie del progetto
target_link_libraries(ASFML sfml-graphics sfml-window sfml-system)