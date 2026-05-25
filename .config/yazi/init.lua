local catppuccin_theme = require("yatline-catppuccin"):setup("mocha")
require("full-border"):setup()
require("git"):setup({
  order = 1500,
})
require("yatline"):setup({
	theme = catppuccin_theme,
})
require("relative-motions"):setup({
	show_numbers = "relative_absolute",
})
