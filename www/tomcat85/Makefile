# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomcat
PORTVERSION=	8.5.12
CATEGORIES=	www java
MASTER_SITES=	APACHE/tomcat/tomcat-8/v${PORTVERSION}/bin
PKGNAMESUFFIX=	85
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	vvd@unislabs.com
COMMENT=	Open-source Java web server by Apache, 8.5.x branch

LICENSE=	APACHE20

RUN_DEPENDS=	jsvc:devel/jakarta-commons-daemon

USES=		cpe
CPE_VENDOR=	apache

USE_JAVA=	yes
JAVA_VERSION=	1.7+
NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	${PKGBASE}

TOMCAT_SUBDIR?=	${DISTNAME:R}
TOMCAT_HOME=	${PREFIX}/${TOMCAT_SUBDIR}
TOMCAT_CONF_FILES=	\
		catalina.policy catalina.properties context.xml logging.properties \
		server.xml tomcat-users.xml tomcat-users.xsd web.xml \
		jaspic-providers.xml jaspic-providers.xsd
PLIST_SUB=	T=${TOMCAT_SUBDIR} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

SUB_LIST=	TOMCAT_HOME=${TOMCAT_HOME} \
		TOMCAT_USER=${WWWOWN} \
		JAVA_HOME=${JAVA_HOME}

.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${TOMCAT_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"

post-patch:
	@${FIND} ${WRKSRC} -name '*.bat' -delete
.for f in ${TOMCAT_CONF_FILES}
	@${MV} ${WRKSRC}/conf/${f} ${WRKSRC}/conf/${f}.sample
.endfor

do-install:
	@${ECHO_MSG} -n ">> Creating destination directory..."
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/logs
	@${MKDIR} ${STAGEDIR}${TOMCAT_HOME}/endorsed
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${TOMCAT_HOME}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Fixing permissions..."
	@${FIND} ${STAGEDIR}${TOMCAT_HOME} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
