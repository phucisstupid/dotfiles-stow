local colors = require("colors").sections.bar

sbar.bar({
	topmost = "window",
	height = 30,
	notch_display_height = 30,
	padding_right = 5,
	padding_left = 5,
	border_color = colors.border,
	color = colors.bg,
})
