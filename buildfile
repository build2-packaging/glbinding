import pkgs = {*/ -upstream/ -*-tests/ -*-examples/ -*-tools/}
import tests = {*-tests/ *-examples/ *-tools/}
./: $pkgs
./: $tests: install = false
