cmake_minimum_required(VERSION 3.28)

project(untitled1)

include_directories(".")

set(SFML_STATIC_LIBRARIES TRUE )
set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "C:/Users/SystemX/Documents/Libraries/SFML-2.6.1/lib/cmake/SFML" )

find_package(SFML 2.5 COMPONENTS graphics audio system window network REQUIRED)

add_executable(untitled1 main.cpp
        Headers/Includes.h
        Exec/Managers/TextureManager.cpp
        Headers/Managers/TextureManager.h
        Exec/AbstractClasses/Entity.cpp
        Headers/Abstracts/Entity.h
        Exec/Managers/EntityManager.cpp
        Headers/Managers/EntityManager.h
        Exec/GameClasses/ChessPeace.cpp
        Headers/GameClasses/ChessPeace.h
        Headers/StandartLibraries.h
        Headers/SFML.h
        Exec/AbstractClasses/Window.cpp
        Headers/GameClasses/Window.h
        Headers/Logic/Logic.h
        Exec/Logic/Systems/EventSystem.cpp
        Headers/Logic/Systems/EventSystem.h
        Exec/Logic/Systems/RenderSystem.cpp
        Headers/Logic/Systems/RenderSystem.h
        Headers/Logic/GameFunctions/GameFunctions.h
        Exec/Logic/GameFunctions/CreateChessBoard.cpp
        Exec/Logic/GameFunctions/LoadChessTileTexturesToWindow.cpp
        Headers/Constants.h
        Exec/Logic/GameFunctions/LoadChessPeacesTexturesToWindow.cpp
        Exec/Logic/GameFunctions/CreateChessPeaces.cpp
        Exec/Logic/GameFunctions/CreateVirtualChessMap.cpp

)

target_link_libraries(untitled1 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

