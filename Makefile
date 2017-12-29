all: clean output

output:
	cp -r * $(HOME)/Arduino/libraries/

clean:
	rm -rf `find -type d -name Cellar.Esp8266`