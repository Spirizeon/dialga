CFLAGS = -Wno-implicit-function-declaration
all: dialga

dialga: main.o init.o hashing.o
	@gcc $(CFLAGS) main.o hashing.o -lcrypto init.o -o dialga
	@chmod +x dialga
	@echo "🔗 Linking...✅"

main.o: main.c
	@gcc $(CFLAGS) -c main.c 
	@echo "⚙ Compiling main file...✅"

init.o: init.c
	@gcc $(CFLAGS) -c init.c
	@echo "⚙ Compiling init file...✅"

hashing.o: hashing.c
	@gcc $(CFLAGS) -lcrypto -c hashing.c 
	@echo "⚙ Compiling hashing file...✅"

clean:
	@rm main.o hashing.o init.o dialga
	@rm -rf .dlgx
	@echo "🗑 Cleaning up..."


test: 
	@./dialga init
	@./dialga add init.c
	@./dialga add main.c
	@./dialga status
	@./dialga commit 
