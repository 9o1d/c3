# Please set dir for temp header files
HEADERS_DIR=$(HOME)/tmp

INCLUDE=-I . -I common -I module -I file -I char_string -I parse -I utopia -I $(HEADERS_DIR) -I prime -I chars
CFLAGS=-Wall -g -D_DEBUG ${INCLUDE}
LDLIBS=-lm -pthread
MOD_H=$(shell find $(SOURCEDIR) -name '*.mod.h')
OBJECTS_H=$(MOD_H:%.mod.h=%.h)
DEPS=$(basename($(MAKECMDGOALS)):%=%.d)

# Uncomment next string (remove '#') after mod_to_h compile
#include $(OBJECTS_H)

%.h: %.mod.h
	test/mod_to_h $^ $(HEADERS_DIR)/

%.d: %.c
	$(CC) -MM ${INCLUDE} $^ -o $(HEADERS_DIR)/$@

