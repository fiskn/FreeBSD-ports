# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	florist-gpl
PORTVERSION=	2016
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	freebsd.contact@marino.st
COMMENT=	POSIX Ada binding, IEEE Standards 1003.5(b,c)

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild:devel/gprbuild

USES=		ada gmake
GNU_CONFIGURE=	yes
SUB_FILES=	florist.gpr

post-extract:
	(cd ${WRKSRC}/configs && ${CP} pconfig.FreeBSD pconfig.DragonFly)

.include <bsd.port.mk>
