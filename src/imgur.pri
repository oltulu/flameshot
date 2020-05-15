# Use default Imgur client_id if user did not pass
# this variable to qmake
isEmpty(IMGUR_CLIENT_ID) {
    IMGUR_CLIENT_ID = "313baf0c7b4d3ff"
}

DEFINES += IMGUR_CLIENT_ID=\\\"$${IMGUR_CLIENT_ID}\\\"

HEADERS += \
    $$PWD/tools/cut/cut.h \
    $$PWD/tools/luping/luping.h \
    $$PWD/tools/options/options.h

SOURCES += \
    $$PWD/tools/cut/cut.cpp \
    $$PWD/tools/luping/luping.cpp \
    $$PWD/tools/options/options.cpp
