CUB3D = ../cub3d
MAPS_DIR = ./test_map
OUTPUT_DIR = ./output

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m

.PHONY: all clean run

# Liste dynamique des maps existantes
MAPS := $(wildcard $(MAPS_DIR)/*.cub)
OUTPUTS := $(patsubst $(MAPS_DIR)/%.cub,$(OUTPUT_DIR)/%.txt,$(MAPS))

all: run

$(OUTPUT_DIR)/%.txt: $(MAPS_DIR)/%.cub
	@mkdir -p $(OUTPUT_DIR)
	@echo "$(YELLOW)Test $< ...$(RESET)"
	@bash -c '\
		$(CUB3D) "$<" 2>&1 | sed "s/\x1b\[[0-9;]*m//g" > "$@"; \
		valgrind --leak-check=full $(CUB3D) "$<" > valgrind_tmp.txt 2>&1; \
		if grep -q "in use at exit: 0 bytes in 0 blocks" valgrind_tmp.txt; then \
			echo >> "$@"; \
			echo "✅ NO LEAK ✅" >> "$@"; \
		else \
			echo >> "$@"; \
			echo "❌ LEAK ❌" >> "$@"; \
		fi; \
		rm -f valgrind_tmp.txt; \
	'

run: $(OUTPUTS)


clean:
	@rm -rf $(OUTPUT_DIR)/*
	@echo "$(YELLOW)All test outputs cleaned. 🧹$(RESET)"
