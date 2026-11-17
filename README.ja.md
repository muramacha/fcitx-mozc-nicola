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

その他（Ubuntu 24.04用を使用する）
```bash
curl -OL https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-ubuntu-24.04.tar.gz | tar -zf
```

### 2 インストール
```bash
cd fcitx-mozc-nicola && make install
```

ビルド
------------------
```bash
git clone https://github.com/muramacha/fcitx-mozc-nicola
cd fcitx-mozc-nicola
make
make install
```
