# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
UNICODE_ENABLE = yes         # Unicode

#ADDED
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
ENCODER_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

VIA_ENABLE = yes

#RGB_MATRIX_ENABLE = yes
#RGB_MATRIX_DRIVER = WS2812
