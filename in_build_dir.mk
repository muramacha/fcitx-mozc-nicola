B_BIN    := ../src/bazel-bin
MSERVER  := $(B_BIN)/server/mozc_server
FMOZC_SO := $(B_BIN)/unix/fcitx5/fcitx5-mozc.so
FCONF    := ../src/unix/fcitx5

FCITX_PATH  := /usr/share/fcitx5
SERVER_PATH := /usr/lib/mozc

ID            := $(shell . /etc/os-release && echo $$ID)
VERSION_ID    := $(shell . /etc/os-release && echo $${VERSION_ID:-rolling})
OUT_FILES     := mozc_server nicola.so nicola.conf nicola-addon.conf Makefile
RELEASE_DIR   := fcitx_mozc_nicola-$(ID)-$(VERSION_ID)
RELEASE_FILES := $(addprefix $(RELEASE_DIR)/, $(OUT_FILES))

DETECTED_SO_DIR := $(firstword $(wildcard /usr/lib/x86_64-linux-gnu/fcitx5 /usr/lib64/fcitx5 /usr/lib/fcitx5))
SO_DIR          ?= $(DETECTED_SO_DIR)
SO_DEST         := $(SO_DIR)/nicola.so
SERVER_DEST     := $(SERVER_PATH)/mozc_server
CONF_DEST       := $(FCITX_PATH)/inputmethod/nicola.conf
ADDON_CONF_DEST := $(FCITX_PATH)/addon/nicola.conf
DESTS           := $(SO_DEST) $(SERVER_DEST) $(CONF_DEST) $(ADDON_CONF_DEST)

.PHONY: build install release so server all uninstall
.DEFAULT_GOAL := build

all: build release install

uninstall:
	sudo rm $(DESTS)

cleanrelease:
	rm -rf $(RELEASE_DIR).tar.gz $(RELEASE_DIR) Makefile

# BUILD

build: $(FMOZC_SO) $(MSERVER)
$(FMOZC_SO):
	cd ../src && bazelisk build -c opt --copt=-fPIC --config oss_linux --action_env=ANDROID_HOME="" --action_env=ANDROID_SDK_ROOT="" unix/fcitx5:fcitx5-mozc.so

$(MSERVER):
	cd ../src && bazelisk build -c opt --copt=-fPIC --config oss_linux --action_env=ANDROID_HOME="" --action_env=ANDROID_SDK_ROOT="" server:mozc_server

release: $(RELEASE_DIR).tar.gz

$(RELEASE_DIR).tar.gz: $(RELEASE_FILES)
	tar --owner 0 --group 0 -czf $@ $(RELEASE_DIR)
	# /BUILD

# INSTALL
install: so server conf

so:     $(SO_DEST) ## install addon
conf:   $(CONF_DEST) $(ADDON_CONF_DEST)
server: $(SERVER_DEST)

$(SO_DEST): $(FMOZC_SO)
	@if [ -z "$SO_DIR" ]; then echo "[ERROR]" fcitx path not found.; exit 1; fi
	sudo install -Dm755 $< $@

$(SERVER_DEST): $(MSERVER)
	sudo install -Dm755 $< $@

$(CONF_DEST): $(FCONF)/nicola.conf
	sudo install -Dm644 $< $@

$(ADDON_CONF_DEST): $(FCONF)/nicola-addon.conf
	sudo install -Dm644 $< $@

# COPY TO build/fcitx_mozc_nicola/
$(RELEASE_DIR)/Makefile:           ../release_install.mk
$(RELEASE_DIR)/nicola.so:         $(FMOZC_SO)
$(RELEASE_DIR)/mozc_server:       $(MSERVER)
$(RELEASE_DIR)/nicola.conf:       $(FCONF)/nicola.conf
$(RELEASE_DIR)/nicola-addon.conf :$(FCONF)/nicola-addon.conf

$(RELEASE_FILES):
	mkdir -p $(dir $@)
	cp $< $@
# /COPY TO build

