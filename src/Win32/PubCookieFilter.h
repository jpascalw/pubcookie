//
//  Copyright (c) 1999-2004 University of Washington.  All rights reserved.
//  For terms of use see doc/LICENSE.txt in this distribution.
//

//
//  $Id: PubCookieFilter.h,v 1.28 2004-02-17 23:06:38 ryanc Exp $
//

#define Pubcookie_Version "Pubcookie ISAPI Filter, 3.0.1 pre-beta1"

#define MAX_INSTANCE_ID 25
#define MAX_REG_BUFF 2048 /* Using a fixed size saves a registy lookup 
                             and malloc to find/set the buffer size */

typedef struct {
	char			remote_host[MAX_PATH];
	DWORD			inact_exp;
	DWORD			hard_exp;
	DWORD			failed;
	DWORD			has_granting;
	char			pszUser[SF_MAX_USERNAME];
	char			pszPassword[SF_MAX_PASSWORD];
	char			appid[PBC_APP_ID_LEN];
	char			s_cookiename[64];
	char			force_reauth[4];
	char			AuthType;
	char			default_url[1024];
	char			timeout_url[1024];
	char			user[PBC_USER_LEN];
	char			appsrvid[PBC_APPSRV_ID_LEN];
	char			appsrv_port[6];
	char			uri[1024];		              // *** size ??
	char			args[4096];                   // ***
	char			method[8];		              // ***
	char			handler;
	DWORD			session_reauth;
	DWORD			logout_action;
	char			Error_Page[MAX_PATH];
	char			Enterprise_Domain[1024];
	char			Login_URI[1024];
    pbc_cookie_data *cookie_data;
	DWORD			Set_Server_Values;
	DWORD			legacy;
	char			*g_certfile;
	char			*s_keyfile;
	char			*s_certfile;
	char			*crypt_keyfile;
	int				serial_s_sent;
	char			server_hostname[MAX_PATH];
	char			instance_id[MAX_INSTANCE_ID+1];
	TCHAR			strbuff[MAX_REG_BUFF];  //temporary buffer for libpbc_config_getstring calls
	security_context      *sectext;

} pubcookie_dir_rec;

// Statistic variables removed

#define START_COOKIE_SIZE  1024
#define MAX_COOKIE_SIZE	   10500	// allow enough room for 20 session cookies
									// browser limits 20 cookies per server

// From /usr/local/src/apache_1.2.0/src/httpd.h

#define DECLINED -1             /* Module declines to handle */
#define OK		  0             /* Module has handled this stage. */


extern VOID OutputDebugMsg (char *buff);
extern int Debug_Trace;
extern FILE *debugFile;
void vlog_activity( int logging_level, const char * format, va_list args );
char *Get_Cookie (HTTP_FILTER_CONTEXT* pFC, char *name);



#define WINKEY "System\\CurrentControlSet\\Control\\Windows"
#define PBC_Header_Appid   "Pubcookie-Appid:"
#define PBC_Header_User    "Pubcookie-User:"
#define PBC_Header_Creds   "Pubcookie-Creds:"
#define PBC_Header_Server  "Pubcookie-Server:"
#define PBC_Header_Version "Pubcookie-Filter-Version:"

// Define COOKIE_PATH to include a path of /<application name> in the session
// cookie. This implies that the first node of all URLs are case sensative since
// browsers will only return cookies if the URL matches the path exactly.
// This path feature is desireable so the browser doesn't return all session
// cookies for all applications visited for every URL. 
// Setting this option requires that the Default and Timeout URLs defined in the
// registry are case sensative also.

// Pubcookie Version a5 got rid of these, I still like em!

#define PBC_BAD_GRANTING_CERT 4
#define PBC_BAD_SESSION_CERT 5
#define PBC_BAD_VERSION 6
#define PBC_BAD_APPID 7
#define PBC_BAD_SERVERID 8
// used to redirect from http->https
#define PBC_BAD_PORT 9
#define PBC_LOGOUT_REDIR 10

//AUTH Types = Cred Types
#define AUTH_NONE '0'
#define AUTH_NETID '1'
#define AUTH_SECURID '3'


//LOGOUT Types

#define LOGOUT_NONE 0
#define LOGOUT_LOCAL 1  //NOTE: overrides AuthType to PUBLIC
#define LOGOUT_REDIRECT 2
#define LOGOUT_REDIRECT_CLEAR_LOGIN 3

// Only need two marked below for functionality, rest for debug
static const DWORD 	
Notify_Flags =  ( SF_NOTIFY_SECURE_PORT         |
					  SF_NOTIFY_NONSECURE_PORT      |
					  // SF_NOTIFY_READ_RAW_DATA       | // Not supported in IIS 6
					  SF_NOTIFY_PREPROC_HEADERS     | 
					  SF_NOTIFY_URL_MAP             |
					  SF_NOTIFY_AUTHENTICATION      | 
					  SF_NOTIFY_ACCESS_DENIED       |
					  SF_NOTIFY_SEND_RESPONSE       |
					  // SF_NOTIFY_SEND_RAW_DATA       |  // Too many debug calls  
					  SF_NOTIFY_END_OF_REQUEST      |
					  SF_NOTIFY_LOG                 |
					  SF_NOTIFY_END_OF_NET_SESSION  |
					  SF_NOTIFY_ORDER_DEFAULT ); 
