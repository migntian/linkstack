.PHONY:clean
main :llinkstack.c
	gcc $^ -o $@
clean:
	rm -f main
