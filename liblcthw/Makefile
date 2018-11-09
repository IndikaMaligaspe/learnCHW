CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/src/learnCHW

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TARGET=build/liblcthw.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

#The Target build
all: $(TARGET) $(SO_TARGET)

dev: CFLAGS=-g  -Wall -Isrc -Wall -Wextra  $(OPTFLAGS)

dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@	$(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

#The Unit Tests
.PHONY: tests
tests: CFLAGS=-g -Wall -Isrc
#tests: CFLAGS
#tests: build/liblcthw.a

tests:  
	cc -g -Wall -Isrc tests/list_tests.c -o tests/list_tests build/liblcthw.a
	sh ./tests/runtests.sh

#The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf 'find . -name "*.dSYM" -print'

#The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

#The Checker
check:
	@echo Files with potentially dangerous functions.
	@egrep '[^_.>a-zA-Z0-9] (str (n?cpy|n?cat\xfrm|n?dup|str|pbrk|tok|-)\
		|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true
	
