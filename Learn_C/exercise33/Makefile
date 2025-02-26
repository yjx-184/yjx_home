CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/lcthw/**/*.c src/lcthw/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/exercise32.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# 目标构建
all: $(TARGET) $(SO_TARGET) tests

dev: CFLAGS=-g -Wall -Isrc -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	@ar rcs $@ $(OBJECTS)
	@ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	@$(CC) -shared -o $@ $(OBJECTS) $(LIBS)

build:
	@mkdir -p build
	@mkdir -p bin

# 单元测试
.PHONY: tests
tests: $(TESTS)
	@sh ./tests/runtests.sh

$(TESTS): $(TARGET)
	@$(CC) $(CFLAGS) $@.c $(TARGET) -o $@ $(LIBS)

valgrind:
	@VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# 清洁
clean:
	@rm -rf build $(OBJECTS) $(TESTS)
	@rm -f tests/tests.log
	@find . -name "*.gc*" -exec rm {} \;
	@rm -rf `find . -name "*.dSYM" -print`

# 安装
install: all
	@install -d $(DESTDIR)/$(PREFIX)/lib/
	@install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/
	@install $(SO_TARGET) $(DESTDIR)/$(PREFIX)/lib/

# 检查
BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true
