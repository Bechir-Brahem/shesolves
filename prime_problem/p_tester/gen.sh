touch out_file
for f in tests/*.in; do
    #./do < $f >"$(basename -- "$f" .ans).in"
    ./do < $f >>out_file
done
