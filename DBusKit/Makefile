.include <internal/framework.common.mk>

FRAMEWORK=DBusKit
SRCS= \
      DKConnection.m DKMessage.m DKMenu.m

INCS= \
      DKConnection.h DKMessage.h DKMenu.h

RESOURCES=
DBUS_CFLAGS!= pkg-config --cflags dbus-1
DBUS_LDFLAGS!= pkg-config --libs dbus-1
DBUS_LDFLAGS+=-Wl,-R\$$ORIGIN/./
CFLAGS+= -g ${FMWK_CFLAGS} -I${.CURDIR}/.. -I${BUILDROOT}/usr/include -I/usr/local/include \
	 -I. -I../Foundation/Foundation.framework/Headers ${DBUS_CFLAGS} -fblocks
LDFLAGS+= -g ${FMWK_LDFLAGS} -L/usr/local/lib ${DBUS_LDFLAGS} \
	  -Wl,-R/System/Library/Frameworks/Foundation.framework/Versions/A \
	  -Wl,-R/System/Library/Frameworks/CoreFoundation.framework/Versions/A \
	  -L${BUILDROOT}/System/Library/Frameworks/Foundation.framework/Versions/Current \
	  -L${BUILDROOT}/System/Library/Frameworks/CoreFoundation.framework/Versions/Current \
	  -lFoundation -lCoreFoundation -lobjc -lm

build: all copydbus

copydbus:
	rm -rf ${FRAMEWORK}.framework/Headers/dbus
	rm -f ${FRAMEWORK}.framework/Versions/Current/libdbus-1.so*
	cp -rvf /usr/local/include/dbus-1.0/dbus/*.h ${FRAMEWORK}.framework/Headers/
	cp -vf /usr/local/lib/dbus-1.0/include/dbus/dbus-arch-deps.h ${FRAMEWORK}.framework/Headers/
	sed -i.bak -e 's/#include <dbus/#import <${FRAMEWORK}/g' ${FRAMEWORK}.framework/Headers/dbus*.h
	rm -f ${FRAMEWORK}.framework/Headers/*.bak
	ln -sf /usr/local/lib/libdbus-1.so* ${FRAMEWORK}.framework/Versions/Current/

.include <he.framework.mk>
