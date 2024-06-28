CFLAGS = -Wno-implicit-function-declaration
all: final

final: main.o init.o
	@echo "⛓ linking and producing final application"
	gcc $(CFLAGS) main.o init.o -o final 
	chmod +x final

main.o: main.c
	@echo "⚙ Compiling main file..."
	gcc $(CFLAGS) -c main.c 

hello.o: hello.c
	@echo "⚙ Compiling init file..."
	gcc $(CFLAGS) -c init.c gcc 

clean:
	@echo "🗑 Cleaning up..."
	rm main.o init.o final
