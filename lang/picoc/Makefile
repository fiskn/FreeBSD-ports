# $FreeBSD$

PORTNAME=	picoc
PORTVERSION=	2.1
CATEGORIES=	lang devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very small C interpreter for scripting

LICENSE=	BSD3CLAUSE

BROKEN=		Unfetchable (google code has gone away)
DEPRECATED=	Unfetchable for more than six months (google code has gone away)
EXPIRATION_DATE=	2017-04-30

USES=		gmake readline tar:bzip2

PLIST_FILES=	bin/picoc

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picoc ${STAGEDIR}${PREFIX}/bin/picoc

.include <bsd.port.mk>
