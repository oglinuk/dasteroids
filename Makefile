BIN=asteroids
SRC=src/*
FLAGS=-lallegro -lallegro_font -lallegro_primitives

all:
	gcc ${SRC} -o ${BIN} ${FLAGS}

clean:
	rm ${BIN}
