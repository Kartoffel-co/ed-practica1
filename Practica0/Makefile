# --- Configuración general ---
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/programa

# --- Archivos fuente y objeto ---
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# --- Regla principal ---
all: $(TARGET)

# --- Cómo generar el ejecutable ---
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
	@echo "Compilación completa. Ejecutable en $(TARGET)"

# --- Cómo compilar cada .cpp a .o ---
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Limpieza ---
clean:
	rm -rf $(OBJ_DIR)/*.o
	@echo "Archivos objeto eliminados."

mrproper: clean
	rm -rf $(BIN_DIR)/*
	@echo "Ejecutables eliminados."

# --- Ejecución rápida ---
run: all
	./$(TARGET)

