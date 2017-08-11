CC=gcc
DEPS= src/main.h src/engine.h src/term_1d_animate.h src/math_utils.h
SRC= src
OBJ= obj

$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) -c $< -o $@

main: $(OBJ)/main.o $(OBJ)/engine.o $(OBJ)/term_1d_animate.o $(OBJ)/math_utils.o
	$(CC) $(OBJ)/main.o $(OBJ)/engine.o $(OBJ)/term_1d_animate.o $(OBJ)/math_utils.o
