# Dossiers
SRC = src
INCLUDE = include
BUILD = build

# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(INCLUDE)

# Liste des fichiers sources et objets
SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(patsubst $(SRC)/%.cpp, $(BUILD)/%.o, $(SOURCES))

# Exécutable final
EXEC = main

# Compilation de l'exécutable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS) -lX11 -lpthread

# Compilation des fichiers objets (la dépendance à l'en-tête est supprimée)
$(BUILD)/%.o: $(SRC)/%.cpp
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(BUILD)/*.o $(EXEC)
