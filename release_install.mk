FCITX_DIR := /usr/share/fcitx5

DETECTED_SO_DIR := $(firstword $(wildcard /usr/lib/x86_64-linux-gnu/fcitx5 /usr/lib64/fcitx5 /usr/lib/fcitx5))
SO_DIR          ?= $(DETECTED_SO_DIR)
DEST_SO         := $(SO_DIR)/nicola.so
DEST_CONF       := $(FCITX_DIR)/inputmethod/nicola.conf
DEST_SERVER     := /usr/lib/mozc/mozc_server
DEST_ADDONCONF  := $(FCITX_DIR)/addon/nicola.conf
DESTS           := $(DEST_SO) $(DEST_CONF) $(DEST_ADDONCONF) $(DEST_SERVER)

.PHONY: install uninstall

install: $(DESTS)

$(DEST_SO): nicola.so
	@if [ -z $(SO_DIR) ]; then echo 'path for "nicola.so" was not found.'; exit 1; fi
	sudo install -Dm755 $< $@

$(DEST_SERVER): mozc_server
	sudo install -Dm755 $< $@

$(DEST_CONF):      nicola.conf
$(DEST_ADDONCONF): nicola-addon.conf
$(DEST_CONF) $(DEST_ADDONCONF):
	sudo install -Dm644 $< $@

uninstall:
	sudo rm $(DESTS)
