CC=gcc

INCDIR = include
CFLAGS = -I $(INCDIR)

SRC= src

OBJDIR = src/obj

_DEPS= main.h engine.h term_1d_animate.h math_utils.h cJSON.h
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ= main.o engine.o term_1d_animate.o math_utils.o cJSON.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))


$(OBJDIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

sim: $(OBJ)
	$(CC) $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o
