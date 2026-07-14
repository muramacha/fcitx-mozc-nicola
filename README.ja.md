このソフトについて
=====================
言語: [English](README.md) | [日本語]

親指シフト(Nicola 配列)の機能を加えた、[fcitx5-mozc](https://github.com/fcitx/mozc)のフォークです。
> **警告**
> このアドオンは独自のmozc_serverを含んでおり、そのバージョンの違いからパッケージマネージャなどでインストールした本家fcitx5-mozcと競合します。

機能
----
- IMEの挙動のみを上書きするので、Ctrl-cがCtrl-suになったりはしない
- IMEが有効でもアプリが入力を受けつていなければ変換されない
  - Youtubeで、IMEがオンでもlで10秒スキップできる
- US配列のみ、JP配列には未対応（いつかやる）
- 左シフトキーはスペース、右シフトは変換キー（いつか変更できるようにする）
- fcitx5-mozcの入力を直接上書きするのでローマ字、かな入力は使えなくなる（そのうち対応）
  - しかも本家mozcとも競合する（いつか対応）
- Fcitx5のみ（ibusには対応しない）

インストール
----------------------
Ubuntu/Debian:
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-ubuntu-26.04.tar.gz | tar xzf -
cd fcitx_mozc_nicola-ubuntu-26.04
sudo make install
```
Fedora:
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-fedora-44.tar.gz | tar xzf -
cd fcitx_mozc_nicola-fedora-44
sudo make install
```
Arch:
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-arch-rolling.tar.gz | tar xzf -
cd fcitx_mozc_nicola-arch-rolling
sudo make install
```
その他（ubuntu22.04用を使ってください）:
```bash
curl -L https://github.com/muramacha/fcitx-mozc-nicola/releases/latest/download/fcitx_mozc_nicola-ubuntu-24.04.tar.gz | tar xzf -
cd fcitx_mozc_nicola-ubuntu-22.04
sudo make install
```

### その他のディストロのトラブルシューティング
#### make installが失敗した場合
1. ご自身のシステムの`mozc_server`と`fcitx5-mozc.so`のインストール先パスを確認してください。
例えば、
Arch Linuxは`/usr/lib/mozc/mozc_server`と`/usr/lib/fcitx5/fcitx5-mozc.so`です。 
2. Ubuntu24.04用のファイルをダウンロードして解答してください。
3. 以下のようなコマンドを使って正しいパスに手動でインストールしてください。
```bash
# fcitx5プラグインをインストールする
sudo install -Dm755 nicola.so /your/fcitx5-mozc.so/directory/nicola.so

# mozc_serverを設置（または上書き）する
sudo install -Dm755 mozc_server /your/mozc_server/directory/mozc_server

# 設定ファイルをインストールする
sudo install -Dm644 nicola-addon.conf /usr/share/fcitx5/addon/nicola.conf
sudo install -Dm644 nicola.conf /usr/share/fcitx5/inputmethod/nicola.conf
```
#### インストールは成功したが、動かない場合
1. **Fcitx5を再起動する**
```bash
fcitx5 -r
```
2. **システムを再起動する**<BR>
たまにこれで直ることがありました。
3. **アプリを再起動する**<BR>
  インプットメソッドを使いたいアプリを再起動してみてください
4. **ソースからビルド**<BR>
  それでも動かない場合はソースからビルドしてください。ソースからビルドのセクションに従ってください。

ソースからビルド
---
依存関係:
- **c++ コンパイラ**
- **python3**
- **bazelisk**
- **pkg-config**
- **fcitx5開発パッケージ**
  - Ubuntu/Debian `fcitx5-modules-dev` `libfcitx5core-dev` `libfcitx5config-dev` `libfcitx5utils-dev`
  - Arch: `fcitx5` (開発パッケージを含んでいます)
  - Fedora: `fcitx5-devel.x86_64`

#### 依存関係をインストール
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

#### ビルドしてインストール
```bash
# リポジトリをクローン
git clone https://github.com/muramacha/fcitx-mozc-nicola.git
cd fcitx-mozc-nicola
# ビルド
make
# インストール
make install
```
