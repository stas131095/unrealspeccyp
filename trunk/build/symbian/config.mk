PROJECT_NAME = unreal_speccy_portable
TARGET_TYPE = exe
UID2 = 0
UID3 = A000821A
SECUREID = A000821A
EPOCSTACKSIZE = 0x5000
EPOCHEAPSIZE = 0x400000,0x800000
CAPABILITY = NONE
SYSINCLUDE = $(EPOCROOT)/epoc32/include $(EPOCROOT)/epoc32/include/mmf/plugin $(EPOCROOT)/epoc32/include/libc
USERINCLUDE = 
SRCFOLDERS = . z80 ui snapshot tools tools/zlib tools/tinyxml platform platform/symbian platform/custom_ui devices devices/fdd devices/input devices/sound 
CXXSRCS = $(foreach dir, $(SRCFOLDERS), $(wildcard $(SRC_PATH)/$(dir)/*.cpp))
CSRCS = $(foreach dir, $(SRCFOLDERS), $(wildcard $(SRC_PATH)/$(dir)/*.c))
IMG_SRCS = icon.svg
IMG_TARGETS = $(DIST_PATH)/$(PROJECT_NAME).mif
IMG_ARGS = /c32
RSS_TARGETS = $(DIST_PATH)/$(PROJECT_NAME).rsc $(DIST_PATH)/$(PROJECT_NAME)_reg.rsc
LANG_MACRO = LANGUAGE_SC
SYSLIBRARY = euser.lib estlib.lib avkon.lib libGLES_CM.lib eikcore.lib cone.lib apparc.lib ws32.lib fbscli.lib efsrv.lib commondialogs.lib eikcoctl.lib mediaclientaudiostream.lib
#CERT = /c/cert/selfsigned.cer
#KEY = /c/cert/selfsigned.key
