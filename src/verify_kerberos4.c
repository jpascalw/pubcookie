
#ifdef HAVE_CONFIG_H
# include "config.h"
# include "pbc_path.h"
#endif

#ifdef HAVE_STDLIB_H
# include <stdlib.h>
#endif /* HAVE_STDLIB_H */

#include "verify.h"

#ifdef HAVE_DMALLOC_H
# ifndef APACHE
#  include <dmalloc.h>
# endif /* ! APACHE */
#endif /* HAVE_DMALLOC_H */

static int kerberos4_v(const char *userid,
		       const char *passwd,
		       const char *service,
		       const char *user_realm,
		       struct credentials **creds,
		       const char **errstr)
{
    if (creds) *creds = NULL;

    *errstr = "kerberos4 not implemented";
    return -1;
}

verifier kerberos4_verifier = { "kerberos_v4",
				&kerberos4_v, NULL, NULL };
