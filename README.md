Fcitx-mozc-nicola
============================
Language: [English] | [日本語](README.ja.md)

An addon for fcitx5 that provides new features for Oyayubi-shift (Nicola) layout, forked from [fcitx-mozc](https://github.com/fcitx/mozc).
> **Warning**
> It conflicts with the fcitx-mozc installed via package managers due to differences in the `mozc_server` version.


Install
-------------
1. Download and extract the latest binaries from the [Release](https://github.com/muramacha/fcitx-mozc-nicola/releases) pages.

2. Check the installation paths for `fcitx5-mozc.so` and `mozc_server` on your system.
**Example:**
**Ubuntu / Debian:** `/usr/lib/x86_64-linux-gnu/fcitx5/` and `/usr/lib/mozc/`
**Arch Linux:** `/usr/lib/fcitx5/` and `/usr/lib/mozc/`

3. Rename and copy the files to correct paths like below:
```bash
# Copy and rename the fcitx5 plugin.
sudo cp fcitx5-mozc.so /usr/lib/x86_64-linux-gnu/fcitx5/nicola.so

# Overwrite or place the mozc_server
sudo cp mozc_server /usr/lib/mozc

# Copy the configuraion files
sudo cp nicola-addon.conf /usr/share/fcitx5/addon/nicola.addon
sudo cp nicola.conf /usr/share/fcitx5/inputmethod/
```

