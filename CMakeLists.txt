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
        Headers/Abstracts/Window.h
        Headers/Logic/Logic.h
        Exec/Logic/Systems/EventSystem.cpp
        Headers/Logic/Systems/EventSystem.h
        Exec/Logic/Systems/RenderSystem.cpp
        Headers/Logic/Systems/RenderSystem.h
        Headers/Logic/GameFunctions/GameFunctions.h
        Exec/Logic/GameFunctions/CreateChessBoard.cpp
        Exec/Logic/GameFunctions/LoadChessTileTexturesToTextureManager.cpp
        Headers/Constants.h
        Exec/Logic/GameFunctions/LoadChessPeacesTexturesToTextureManager.cpp
        Exec/Logic/GameFunctions/CreateChessPeaces.cpp
        Exec/Logic/GameFunctions/CreateVirtualChessMap.cpp
        Headers/GameClasses/GameWindow.h
        Headers/Abstracts/TileMap.h
        Headers/GameClasses/Peaces/Pawn.h
        Headers/GameClasses/Peaces/Rook.h
        Headers/GameClasses/Peaces/Knight.h
        Headers/GameClasses/Peaces/Bishop.h
        Headers/GameClasses/Peaces/King.h
        Headers/GameClasses/Peaces/Queen.h
        Headers/GameClasses/ChessBoard.h
        Exec/AbstractClasses/TileMap.cpp
        Exec/GameClasses/ChessBoard.cpp
        Exec/GameClasses/GameWindow.cpp
        Exec/GameClasses/Peaces/Pawn.cpp
        Exec/GameClasses/Peaces/Rook.cpp
        Exec/GameClasses/Peaces/Knight.cpp
        Exec/GameClasses/Peaces/Bishop.cpp
        Exec/GameClasses/Peaces/King.cpp
        Exec/GameClasses/Peaces/Queen.cpp
        Headers/Abstracts/Tile.h
        Exec/AbstractClasses/Tile.cpp
        Headers/GameClasses/PeaceMap.h
        Exec/GameClasses/PeaceMap.cpp
        Headers/GameClasses/Peaces/Peaces.h

)

target_link_libraries(untitled1 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

