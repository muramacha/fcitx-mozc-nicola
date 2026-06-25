BUILD_DIR := build

.DEFAULT_GOAL = build

.PHONY: all

%: $(BUILD_DIR)/Makefile
	$(MAKE) -C build $@

$(BUILD_DIR)/Makefile:
	@mkdir -p build
	cp in_build_dir.mk $@
