ifneq ($(wildcard /usr/lib/x86_64-linux-gnu/fcitx5/),)
	DETECTED_SO_DIR := /usr/lib/x86_64-linux-gnu/fcitx5
else ifneq ($(wildcard /usr/lib64/fcitx5/),)
	DETECTED_SO_DIR := /usr/lib64/fcitx5
else ifneq ($(wildcard /usr/lib/fcitx5/),)
	DETECTED_SO_DIR := /usr/lib/fcitx5
endif

SO_DIR ?= $(DETECTED_SO_DIR)
$(if $(SO_DIR),,$(error [ERROR] fcitx5 installation path not found. Abort.))

FCITX_DIR := /usr/share/fcitx5

DEST_SO        := $(SO_DIR)/nicola.so
DEST_CONF      := $(FCITX_DIR)/inputmethod/nicola.conf
DEST_SERVER    := /usr/lib/mozc/mozc_server
DEST_ADDONCONF := $(FCITX_DIR)/addon/nicola.conf
DESTS          := $(DEST_SO) $(DEST_CONF) $(DEST_ADDONCONF) $(DEST_SERVER)

.PHONY: install uninstall

install: $(DESTS)

$(DEST_SO):     nicola.so
$(DEST_SERVER): mozc_server
$(DEST_SO) $(DEST_SERVER):
	sudo install -Dm755 $< $@

$(DEST_CONF):      nicola.conf
$(DEST_ADDONCONF): nicola-addon.conf
$(DEST_CONF) $(DEST_ADDONCONF):
	sudo install -Dm644 $< $@

uninstall:
	sudo rm -f $(DESTS)
