MODULES := FIFO calculator cwd dir dup exec fcntl fork io_function lib_make lib_shared_make lseek lstat mmap opendir perror pipe read sign stat test

.PHONY: all run clean list

all:
	@for m in $(MODULES); do \
		echo "==> build $$m"; \
		$(MAKE) -C $$m all || exit 1; \
	done

run:
	@for m in $(MODULES); do \
		echo "==> run $$m"; \
		$(MAKE) -C $$m run || exit 1; \
	done

clean:
	@for m in $(MODULES); do \
		echo "==> clean $$m"; \
		$(MAKE) -C $$m clean || exit 1; \
	done

list:
	@printf '%s\n' $(MODULES)
