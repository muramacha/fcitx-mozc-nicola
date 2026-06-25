.PHONY: install

ifndef SO_DEST
	ifneq ($(wildcard /usr/lib/x86_64-linux-gnu/fcitx5/),)
		SO_DEST := /usr/lib/x86_64-linux-gnu/fcitx5
	else ifneq ($(wildcard /usr/lib64/fcitx5/),)
		SO_DEST := /usr/lib64/fcitx5
	else ifneq ($(wildcard /usr/lib/fcitx5/),)
		SO_DEST := /usr/lib/fcitx5
	else
		$(error [ERROR] fcitx5 instalation path not found. Abort.)
	endif
endif

FCITX_DIR = /usr/share/fcitx5

install: 
	sudo install -Dm644 nicola.conf $(FCITX_DIR)/inputmethod/nicola.conf
	sudo install -Dm644 nicola-addon.conf $(FCITX_DIR)/addon/nicola.conf
	sudo install -D nicola.so $(SO_DEST)/nicola.so

