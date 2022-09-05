CAPS_WORD_ENABLE = yes
LTO_ENABLE = yes
UNICODEMAP_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

SRC += functions.c
ifeq ($(strip $(ENCODER_ENABLE)), yes)
     SRC += encoder.c
endif
