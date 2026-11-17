このソフトについて
=====================
言語: [English](README.md) | [日本語]

親指シフト(Nicola 配列)の機能を加えた、[fcitx5-mozc](https://github.com/fcitx/mozc)のフォークです。
> **警告**
> このアドオンは独自のmozc_serverを含んでおり、そのバージョンの違いからパッケージマネージャなどでインストールした本家fcitx5-mozcと競合します。

インストール
----------------------
### 1 [最新のリリース](https://github.com/muramacha/fcitx-mozc-nicola/releases)からファイルたちをダウンロードし展開
Ubuntu / Debian
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-ubuntu-26.04.tar.gz | tar -xz
cd fcitx_mozc_nicola-ubuntu-26.04
```

Fedora
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-fedora-44.tar.gz | tar -xz
cd fcitx_mozc_nicola-fedora-44
```

Arch
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-arch-rolling.tar.gz | tar -xz
cd fcitx_mozc_nicola-arch-rolling
```

その他（Ubuntu 24.04用を使用する）
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-ubuntu-24.04.tar.gz | tar -xz
cd fcitx_mozc_nicola-ubuntu-24.04
```

### 2 インストール
```bash
make install
```

ビルド
------------------
```bash
git clone https://github.com/muramacha/fcitx-mozc-nicola
cd fcitx-mozc-nicola
make
make install
```
