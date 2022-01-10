# md_to_html

## Markdown to HTML converter in awk, with support for stylesheets

`md_to_html` reads input from `stdin` and writes output to `stdout`.

input is always a markdown file and output is always a html file.

not everything works. == and -- headings are not supported. lists inside lists are not supported. and probably many other things.

the stylesheet is defaulted to the file `style.css` in the current directory, but running it with `md_to_html -v style=other_style_sheet.css` sets it to `other_style_sheet.css`.

many many many bugs.
