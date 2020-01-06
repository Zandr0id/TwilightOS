
OBJS_DIR := ./objects
BIN_DIR := ./bin
SRC_DIR := ./src
TOOLS_DIR := ./tools

all:
	cd $(SRC_DIR) && $(MAKE) build

make-tools:
	cd $(TOOLS_DIR) && $(MAKE)

clean:
	echo "Clean up..."
	rm -rf $(OBJS_DIR)

	rm -f $(BIN_DIR)/*~ $(BIN_DIR)/*.bin

print:
	if which figlet >/dev/null; then figlet -c Twilight; else echo "                        ##### Twilight #####"; fi

run:
	echo "Starting QEMU"
	#qemu-system-i386 -kernel $(OUTPUT_FILE) -serial stdio
	cmd.exe /C "scripts\run_qemu.bat"
