/* cprefix.h:  This file is included by assembly source which needs
 *             to know what the c-label prefixes are. The newer versions
 *	       of cpp that come with gcc predefine such things to help
 *	       us out. The reason this stuff is needed is to make
 *	       solaris compiles of the kernel work.
 *
 * Copyright (C) 1995 David S. Miller (davem@caip.rutgers.edu)
 */
#ifndef __SPARC_CPREFIX_H
#define __SPARC_CPREFIX_H

#ifndef __svr4__
#define C_LABEL_PREFIX _
#else
#define C_LABEL_PREFIX
#endif

#define CONCAT(a, b) CONCAT2(a, b)
#define CONCAT2(a, b) a##b

#define C_LABEL(name) CONCAT(C_LABEL_PREFIX, name)

#endif /* !(__SPARC_CPREFIX_H) */
