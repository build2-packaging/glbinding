./: external/
./: glbinding/
./: glbinding-aux/
./: tests/
tests/: install = false

./: manifest legal{LICENSE} doc{README.md UPSTREAM.README.md AUTHORS}
doc{UPSTREAM.README.md}@./: install = doc/README.md
doc{README.md}@./: install = doc/PACKAGE.README.md
