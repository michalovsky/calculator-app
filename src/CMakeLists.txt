set(SOURCES
        StringHelper.cpp
        GetExecutablePath.cpp
        GetProjectPath.cpp
        UserInputReader.cpp
        FontLoader.cpp
        FontStorage.cpp
        TextSfml.cpp
        RectangleSfml.cpp
        Tile.cpp
        TileCreator.cpp
        TilesLayout.cpp
        InteractionHandler.cpp
        Buffer.cpp
        IntersectedTileInformationInterpreter.cpp
        OperationSolver.cpp
        Calculator.cpp
        CalculatorFactory.cpp
        Main.cpp
        )

add_executable(calculator-app ${SOURCES})
target_compile_options(calculator-app PUBLIC ${FLAGS})
target_link_libraries(calculator-app PRIVATE ${SFML_LIBRARIES})
target_include_directories(calculator-app PUBLIC src)