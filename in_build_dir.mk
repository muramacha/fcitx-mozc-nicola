B_BIN := ../src/bazel-bin
FMOZC_SO := $(B_BIN)/unix/fcitx5/fcitx5-mozc.so
MSERVER := $(B_BIN)/server/mozc_server
FCONF := ../src/unix/fcitx5

FCITX_PATH := /usr/share/fcitx5
SERVER_PATH := /usr/lib/mozc

OUT_FILES := mozc_server nicola.so nicola.conf nicola-addon.conf Makefile
RELEASE_DIR := fcitx_mozc_nicola
RELEASE_FILES := $(addprefix $(RELEASE_DIR)/, $(OUT_FILES))

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

.PHONY: build install release so server all
.DEFAULT_GOAL := all

build_dir:
	mkdir -p build

all: build release install

clean:
	rm -rf *

cleanrelease:
	rm -rf fcitx_mozc_nicola.tar.gz

# BUILD
$(FMOZC_SO) $(MSERVER): build

build: 
	cd ../src && \
		bazelisk build -c opt --copt=-fPIC --config oss_linux --action_env=ANDROID_HOME="" --action_env=ANDROID_SDK_ROOT="" unix/fcitx5:fcitx5-mozc.so server:mozc_server

release: fcitx_mozc_nicola.tar.gz

fcitx_mozc_nicola.tar.gz: $(RELEASE_FILES)
	tar --owner 0 --group 0 -czf $@ $(RELEASE_DIR)
	# /BUILD

# INSTALL
install: so server conf

so: $(SO_DEST)/nicola.so ## install addon
$(SO_PATH)/nicola.so : fcitx5-mozc.so
	sudo mkdir -p $(dir $@)
	sudo cp $< $(SO_DEST)/nicola.so

server: $(SERVER_PATH)/mozc_server
$(SERVER_PATH)/mozc_server : mozc_server
	sudo mkdir -p $(dir $@)
	sudo cp $< $(SERVER_PATH)/mozc_server

conf: $(FCITX_PATH)/addon/nicola.conf $(FCITX_PATH)/inputmethod/nicola.conf

$(FCITX_PATH)/addon/nicola.conf: nicola-addon.conf 
	sudo mkdir -p $(dir $@)
	sudo cp nicola-addon.conf $(FCITX_PATH)/addon/nicola.conf

$(FCITX_PATH)/inputmethod/nicola.conf: nicola.conf 
	sudo mkdir -p $(dir $@)
	sudo cp nicola.conf $(FCITX_PATH)/inputmethod/nicola.conf
	# /INSTALL

# COPY TO build/fcitx_mozc_nicola/
$(RELEASE_DIR)/nicola.so: $(FMOZC_SO)
$(RELEASE_DIR)/mozc_server: $(MSERVER)
$(RELEASE_DIR)/nicola-addon.conf :$(FCONF)/nicola-addon.conf
$(RELEASE_DIR)/nicola.conf :$(FCONF)/nicola.conf
$(RELEASE_DIR)/Makefile: ../release_install.mk

$(RELEASE_FILES):
	mkdir -p $(dir $@)
	cp $< $@
# /COPY TO build

