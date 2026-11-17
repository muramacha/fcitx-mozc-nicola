Fcitx-mozc-nicola
============================
Language: [English] | [日本語](README.ja.md)

A fork of [fcitx5-mozc](https://github.com/fcitx/mozc) that adds support for Oyayubi-shift (Nicola) layout.
> **Warning**
> This addon ships its own `mozc_server`, which conflicts with the upstream fcitx5-mozc installed via package managers due to differences in the `mozc_server` version.

Install
-------------
### 1. Download and extract the files from the [latest release](https://github.com/muramacha/fcitx-mozc-nicola/releases)
Ubuntu / Debian
```bash
curl -OL https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-ubuntu-26.04.tar.gz | tar -zf
```

Fedora
```bash
curl -OL https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-fedora-44.tar.gz | tar -zf
```

Arch
```bash
curl -OL https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-arch-rolling.tar.gz | tar -zf
```

Others (use the Ubuntu 24.04 build)
```bash
curl -OL https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-ubuntu-24.04.tar.gz | tar -zf
```

### 2. Install
```bash
cd fcitx-mozc-nicola && make install
```

Build
------------------
```bash
git clone https://github.com/muramacha/fcitx-mozc-nicola
cd fcitx-mozc-nicola
make
make install
```
