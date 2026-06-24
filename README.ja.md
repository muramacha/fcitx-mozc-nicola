このソフトについて
=====================
言語: [English](README.md) | [日本語]

親指シフト(Nicola 配列)の機能を加えた、[fcitx5-mozc](https://github.com/fcitx/mozc)のフォークです。
> **警告**
> このアドオンは独自のmozc_serverを含んでおり、そのバージョンの違いからパッケージマネージャなどでインストールした本家fcitx5-mozcと競合します。

インストール
----------------------
1. [最新のリリース](https://github.com/muramacha/fcitx-mozc-nicola/releases)からファイルたちをダウンロードし、展開してください。

2. ご自身のシステムにおける`fcitx5-mozc.so`と`mozc_server`のインストール先を確認してください。
例えば、，
**Ubuntu / Debian:** `/usr/lib/x86_64-linux-gnu/fcitx5/` と `/usr/lib/mozc/`
**Arch Linux:** `/usr/lib/fcitx5/` と `/usr/lib/mozc/`

3. 必要に応じて名前を変更し、ご自身のシステムにあったパスにファイルを配置してください。
```bash
# プラグイン（.so）をリネームしてコピー
sudo cp fcitx5-mozc.so /usr/lib/x86_64-linux-gnu/fcitx5/nicola.so

# mozc_server を上書きまたは配置
sudo cp mozc_server /usr/lib/mozc

# 設定ファイルをリネームしてコピー
sudo cp nicola.conf /usr/share/fcitx5/inputmethod/
sudo cp nicola-addon.conf /usr/share/fcitx5/addon/nicola.addon
```
