all:
	gcc signals.c -o run_signals
	./run_signals

compile:
	gcc signals.c -o run_signals

run:
	./run_signals

git:
	git add --all
	git commit -m "$(MAKE)"
