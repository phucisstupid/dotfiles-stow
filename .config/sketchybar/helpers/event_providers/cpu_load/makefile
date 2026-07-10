bin/cpu_load: cpu_load.c cpu.h ../sketchybar.h | bin
	clang -std=c99 -O3 $< -o $@

bin:
	mkdir bin

test: test_cpu.c cpu.h | bin
	clang -std=c99 -O3 -I./mock_include $< -o bin/test_cpu
	./bin/test_cpu
