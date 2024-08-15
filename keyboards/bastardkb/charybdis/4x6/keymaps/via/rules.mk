VIA_ENABLE = yes
TAP_DANCE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
CAPS_WORD_ENABLE = yes
# CONSOLE_ENABLE = yes

# MACCEL
SRC += ./qmk_userspace_features/maccel/maccel.c
OPT_DEFS += -DMACCEL_ENABLE