DESCRIPTION = "Simple helloworld application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://rgb2yuv_c.c"

S = "${WORKDIR}"

do_compile() {
	${CC} rgb2yuv_c.c ${LDFLAGS} -o rgb2yuv_c
}

do_install() {
	install -d ${D}${bindir}
	install -m 0755 rgb2yuv_c ${D}${bindir}
}
