SRCS_DIR:=src
BUILD_DIR:=bin
CURRENT_DIR := $(shell pwd)


CC=gcc
CFLAGS=-Wall -g

CCSOURCES=$(wildcard $(SRCS_DIR)/*.c)


all:  preload test link

link:

	$(CC) -c $(SRCS_DIR)/wrap-link.c -o $(BUILD_DIR)/wrap-link.o
	$(CC) -c $(SRCS_DIR)/test.c -o $(BUILD_DIR)/test-link.o
	$(CC) -Wl,-wrap=write -Wl,-wrap=puts $(BUILD_DIR)/test-link.o $(BUILD_DIR)/wrap-link.o -o $(BUILD_DIR)/test-link-bin

preload:
	$(CC) -fPIC -shared $(SRCS_DIR)/wrap-preload.c -o $(BUILD_DIR)/libpreload.so  -ldl

test:
	$(CC) $(CFLAGS) $(SRCS_DIR)/test.c -o $(BUILD_DIR)/test

clean:
	rm -rf bin/*
