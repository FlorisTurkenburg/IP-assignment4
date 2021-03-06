.PHONY: all config paper hotel clean 

all: config web/smarty ccgi/libccgi.a paper hotel

zip:
	./mkexcludes.sh > excludes.lst
	zip -r ../assignment4.zip * --exclude @excludes.lst

config: web/config.php paper/config.h

%/config.php: config.ini
	python confgen.py php $@

%/config.h: config.ini
	python confgen.py c $@

web/smarty:
	make -C web smarty

ccgi/libccgi.a:
	make -C ccgi

paper:
	make -C paper build

hotel:
	make -C hotel build

clean:
	make -C paper clean
	make -C hotel clean