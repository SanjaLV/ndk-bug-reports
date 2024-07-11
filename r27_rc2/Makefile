CFLAGS := -O1 -std=gnu99
INPUT_FILE := test.c
CC := toolchains/llvm/prebuilt/linux-x86_64/bin/x86_64-linux-android32-clang

NDK_r27 := $(ANDROID_HOME)/ndk/27.0.11902837/
NDK_r26d := $(ANDROID_HOME)/ndk/26.3.11579264/

local:
	clang $(INPUT_FILE) -Wall -Wextra -Wshadow -Wpedantic -O2 -std=gnu99
	./a.out

r27:
	$(NDK_r27)/$(CC) $(INPUT_FILE) -o r27 $(CFLAGS)
	adb push r27 /data/local/tmp
	adb shell "chmod +x /data/local/tmp/r27"
	adb shell "/data/local/tmp/r27"

optnone:
	$(NDK_r27)/$(CC) $(INPUT_FILE) -o r27 -O0
	adb push r27 /data/local/tmp
	adb shell "chmod +x /data/local/tmp/r27"
	adb shell "/data/local/tmp/r27"

r26:
	$(NDK_r26d)/$(CC) $(INPUT_FILE) -o r26 $(CFLAGS)
	adb push r26 /data/local/tmp
	adb shell "chmod +x /data/local/tmp/r26"
	adb shell "/data/local/tmp/r26"

.PHONY:	local	r27	optnone	r26
