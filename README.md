# **Dotfiles**

## ⚠️ Important
Back up your `~/.config` if you already have existing configurations.

---

## 🚀 Auto Install with [Dotflow Script](https://github.com/phucisstupid/dotflow)
```sh
curl -fsSL https://raw.githubusercontent.com/phucisstupid/dotflow/main/stow.sh | sh -s
````

This will:

* Clone the dotfiles
* Reset your `~/.zshrc` and `~/.config`
* Install Homebrew, Zinit, Starship, Stow (if missing)
* Apply all dotfiles with GNU Stow
* Ask if you want to install SketchyBar + dependencies

---

## 🎨 Only Install SketchyBar Setup

```sh
curl -fsSL https://raw.githubusercontent.com/phucisstupid/dotflow/main/stow.sh | sh -s -- sketchybar
```

This will:

* Install `lua`, `switchaudio-osx`, `nowplaying-cli`, and `sketchybar` (if missing)
* Install fonts: `sf-symbols`, `font-sketchybar-app-font`
* Download the latest `icon_map.lua`
* Install **SbarLua**
* Restart & reload SketchyBar

---

## 🗑️ Uninstall

```sh
curl -fsSL https://raw.githubusercontent.com/phucisstupid/dotflow/main/stow.sh | sh -s -- uninstall
```

This will:

* Remove all symlinks created by Stow
* Optionally uninstall SketchyBar + helpers
* Restore your `~/.zshrc`

---

## ⚙️ Manual Install

```sh
git clone --depth 1 https://github.com/phucisstupid/dotfiles-stow.git
cd dotfiles-stow
stow .
```
