# **Dotfiles Setup**

## 🚀 Auto Install with [`Dotflow Script`](https://github.com/phucleeuwu/dotflow)

```bash
bash -c "$(curl -fsSL https://raw.githubusercontent.com/phucleeuwu/dotflow/main/stow.sh)"
```

## ⚙️ Manual Install

```bash
git clone --depth 1 https://github.com/phucleeuwu/dotfiles-stow.git
cd dotfiles-stow
stow .
```

## ✏️ Note:
-	Make sure you have Homebrew and stow installed (brew install stow).
-	For a full setup with apps and tools, you can optionally use my [Brewfile](./brew/Brewfile) included in the repo.
-	⚠️ Important: Back up your ~/.config folder before running the script if you have existing configs.
