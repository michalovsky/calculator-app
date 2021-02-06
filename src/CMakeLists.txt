set(SOURCES
        Buffer.cpp
        Calculator.cpp
        UserInputReader.cpp
        Interaction.cpp
        OperationSolver.cpp
        Tile.cpp
        Tiles.cpp
        Main.cpp
        )

add_executable(calculator-app ${SOURCES})
target_link_libraries(calculator-app PRIVATE ${SFML_LIBRARIES})
target_include_directories(calculator-app PUBLIC src)