all:
	gcc *.c *.h -o main -lallegro -lallegro_font -lallegro_primitives

clean:
	rm main
