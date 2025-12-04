i=2
for f in *.md; do
	mv "$f" "opsys_ex$i.md"
	i=$((i+1))
done
