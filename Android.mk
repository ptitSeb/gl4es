LOCAL_PATH := $(call my-dir)

###########################
#
# GL static library
#
###########################

include $(CLEAR_VARS)

LOCAL_MODULE := glshim

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include \
	$(LOCAL_PATH)/src/util \
	$(LOCAL_PATH)/src/util/vectorial

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES) -DBCMHOST

LOCAL_SRC_FILES := \
	src/gl/array.c \
	src/gl/buffers.c \
	src/gl/decompress.c \
	src/gl/eval.c \
	src/gl/framebuffers.c \
	src/gl/gl.c \
	src/gl/light.c \
	src/gl/line.c \
	src/gl/list.c \
	src/gl/pixel.c \
	src/gl/raster.c \
	src/gl/render.c \
	src/gl/stack.c \
	src/gl/texgen.c \
	src/gl/texture.c \
	src/gl/wrap/gl.c \
	src/gl/wrap/gles.c \
	src/gl/wrap/gles2.c \
	src/gl/wrap/glesext.c \
	src/gl/wrap/glstub.c \
	src/gl/math/eval.c \
	src/gl/debug.c \
	src/glx/glx.c \
	src/glx/lookup.c \
	src/glx/streaming.c \
	src/gl/directstate.c

LOCAL_CFLAGS += -g -std=c99 -funwind-tables -O3 -DBCMHOST -include include/android_debug.h

#LOCAL_LDLIBS := -ldl -llog -lEGL

include $(BUILD_STATIC_LIBRARY)

