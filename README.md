Fcitx-mozc-nicola
============================
Language: [English] | [日本語](README.ja.md)

An addon for fcitx5 that provides new features for Oyayubi-shift (Nicola) layout, forked from [fcitx-mozc](https://github.com/fcitx/mozc).
> **Warning**
> It conflicts with the fcitx-mozc installed via package managers due to differences in the `mozc_server` version.


Install
-------------
Ubuntu:
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-ubuntu-26.04.tar.gz | tar xzf -
cd fcitx_mozc_nicola-ubuntu-26.04
sudo make install
```
Fedora:
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-fedora-44.tar.gz | tar xzf -
cd fcitx_mozc_nicola-ubuntu-26.04
sudo make install
```
Arch:
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-arch-rolling.tar.gz | tar xzf -
cd fcitx_mozc_nicola-ubuntu-26.04
sudo make install
```
Other distros:
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-ubuntu-24.04.tar.gz | tar xzf -
cd fcitx_mozc_nicola-ubuntu-24.04
sudo make install
```
### Troubleshooting for Other Distributions.
#### If make install was failed.
1. Check your installation path for `mozc_server` and `fcitx5-mozc.so` on your system.
Example:
Arch Linux: `/usr/lib/mozc/mozc_server` and `/usr/lib/fcitx5/fcitx5-mozc.so` 
2. Download and extract binaries for Ubuntu24.04.
3. Install the files manually to correct paths using commands below:
```bash
# Install the fcitx5 plugin.
sudo install -Dm755 nicola.so /your/fcitx5-mozc.so/directory/nicola.so

# Overwrite or place the mozc_server
sudo install -Dm755 mozc_server /your/mozc_server/directory/mozc_server

# Install the configuraion files
sudo install -Dm644 nicola-addon.conf /usr/share/fcitx5/addon/nicola.conf
sudo install -Dm644 nicola.conf /usr/share/fcitx5/inputmethod/nicola.conf
```
#### If the installation succeeds but the addon does not work.
1. **Restart Fcitx5**
```bash
fcitx5 -r
```
2. **Reboot your systemse**
3. **Restart your application**<BR>
  Close and reopen the application(e.g., your browser or text editor) where you want to use the input method.
4. **Build from Source**<BR>
  If it still does'nt work,the pre-compiled binaries are likely incompatible with yourr system's library version (e.g., `glibc`). Remove them and fllow the "Buid from Source" section.

Build from Source
---
Dependencies:
- **c++ compiler**
- **python3**
- **bazelisk**
- **pkg-config**
- **fcitx5 development package**
  - Ubuntu/Debian `fcitx5-modules-dev` `libfcitx5core-dev` `libfcitx5config-dev` `libfcitx5utils-dev`
  - Arch: `fcitx5` (includes devlelopment headers)
  - Fedora: `fcitx5-devel.x86_64`
#### Install dependencies
Ubuntu/Debian
```bash
sudo apt update
sudo apt install -y curl pkg-config build-essential python3 fcitx5-modules-dev libfcitx5{config,core,utils}-dev
sudo curl -Lo /usr/local/bin/bazelisk https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64
sudo chmod +x /usr/local/bin/bazelisk
```

Arch:
```bash
sudo pacman -Syu --needed base-devel bazelisk fcitx5
```

Fedora:
```bash
sudo dnf install @development-tools
sudo dnf install -y python3 fcitx5-devel.x86_64 curl g++
sudo curl -Lo /usr/local/bin/bazelisk https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64
sudo chmod +x /usr/local/bin/bazelisk
```

#### Build and Install
```bash
# Clone repository
git clone https://github.com/muramacha/fcitx-mozc-nicola.git
cd fcitx-mozc-nicola
# Build the binaries
make
# Install
make install
```
