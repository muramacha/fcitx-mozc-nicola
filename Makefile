BUILD_DIR := build

.DEFAULT_GOAL = build

.PHONY: clean build

%: $(BUILD_DIR)/Makefile
	$(MAKE) -C build $@

$(BUILD_DIR)/Makefile:
	@mkdir -p build
	cp in_build_dir.mk $@

clean:
	rm -rf $(BUILD_DIR)
