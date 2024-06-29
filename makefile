CFLAGS = -Wno-implicit-function-declaration
all: final

final: main.o init.o hashing.o
	gcc $(CFLAGS) main.o hashing.o -lcrypto init.o -o final 
	chmod +x final
	@echo "⛓ linking and producing final application ✅"

main.o: main.c
	gcc $(CFLAGS) -c main.c 
	@echo "⚙ Compiling main file...✅"

init.o: init.c
	gcc $(CFLAGS) -c init.c
	@echo "⚙ Compiling init file...✅"

hashing.o: hashing.c
	gcc $(CFLAGS) -lcrypto -c hashing.c 
	@echo "⚙ Compiling hashing file...✅"

clean:
	@echo "🗑 Cleaning up..."
	rm main.o hashing.o init.o final
