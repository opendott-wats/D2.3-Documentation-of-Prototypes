FILES=ReadMe.md
OUTPUT=D2.3-Documentation-of-Prototypes-ESR1

OPTIONS=--metadata-file=meta.yml -F pandoc-crossref --citeproc\
	-f markdown+rebase_relative_paths \
	--strip-comments \
	--toc \
	--resource-path figures:screenshots

# --number-sections \

CMD=pandoc $(OPTIONS) $(FILES)

clean:
	rm -f output/article.pdf output/report.pdf output/$(OUTPUT).md index.html

article report:
	$(CMD) -V documentclass=$@ -o output/$@.pdf

html:
	$(CMD) -o index.html --embed-resources --standalone

docx:
	$(CMD) --dpi 35 -o $(OUTPUT).docx

md:
	$(CMD) -o output/$(OUTPUT).md -t markdown-citations -t markdown_strict --wrap=none

watch:
	nodemon --exec "make all" -e "md bib" -i output/$(OUTPUT).md

all: html report article docx md

release: all
	git commit -am "updates"

upload:
	git push --follow-tags

deploy: release upload