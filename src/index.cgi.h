/* 

    Copyright 1999, University of Washington.  All rights reserved.

     ____        _                     _    _
    |  _ \ _   _| |__   ___ ___   ___ | | _(_) ___
    | |_) | | | | '_ \ / __/ _ \ / _ \| |/ / |/ _ \
    |  __/| |_| | |_) | (_| (_) | (_) |   <| |  __/
    |_|    \__,_|_.__/ \___\___/ \___/|_|\_\_|\___|


    All comments and suggestions to pubcookie@cac.washington.edu
    More info: https:/www.washington.edu/pubcookie/
    Written by the Pubcookie Team

    this is the header file for index.cgi the pubcookie login cgi

 */

/*
    $Id: index.cgi.h,v 1.2 1999-10-21 01:29:27 willey Exp $
 */

/* utility macros */
#define SWSTRCAT(a,b) (strcat( strcpy( calloc(strlen(a)+strlen(b)+1, sizeof(char)), a), b) )

typedef struct {
    char	*args;
    char	*uri;
    char	*host;
    char	*method;
    char	*version;
    int		creds;
    char	*appid;
    char	*appsrvid;
    char	*fr;
    char	*user;
    char	*pass;
    char	*pass2;
    char	*post_stuff;
} login_rec;

/* prototypes */
int cgiMain();
int cookie_test();
void notok( void (*)() );
void notok_no_g_or_l();
void print_j_test();
void notok_need_ssl();
void notok_no_g();
void notok_formmultipart();
void notok_generic();
void notok_bad_agent();
void print_login_page_part1(int);
void print_login_page_part5();
int check_user_agent();
// todo
login_rec *get_query();
char *check_login(login_rec *);
char *check_l_cookie(login_rec *);
void print_login_page(char *, char *, int, int);
void print_redirect_page(login_rec *);
int get_next_serial();
char *url_encode();
char *get_cookie_created(char *);

#define LOGIN_DIR "/"
#define REFRESH "0"
#define EXPIRE_LOGIN 60 * 60 * 8

#define NOTOK_NEEDSSL "I'm sorry this page is only accessible via a ssl protected connection.<BR>\n"

/* some messages about people who hit posts and don't have js on */
#define PBC_POST_NO_JS_TEXT "Thank you for logging in\n"

#define PRINT_LOGIN_PLEASE "Please log in."
#define TROUBLE_CREATING_COOKIE "Trouble creating cookie.  Please re-enter."
#define PROBLEMS_PERSIST "If problems persist contact help@cac.washington.edu."
#define AUTH_FAILED_MESSAGE1 "Login failed.  Please re-enter."
#define AUTH_FAILED_MESSAGE2 "Please make sure:<BR><UL><LI>Your caps lock key is off.<LI>Your number lock key is on.</UL>"
#define AUTH_TROUBLE "There are currently problems with authentication services, please try again later"

#define PROMPT_UWNETID "<B>Password:</B><BR>\n"
#define PROMPT_SECURID "<B>Securid:</B><BR>\n"

/* how we accentuate warning messages */
#define PBC_EM1_START "<B><FONT COLOR=\"#FF0000\" SIZE=\"+1\">" 
#define PBC_EM1_END "</FONT></B><BR>"
/* how we accentuate less important warning messages */
#define PBC_EM2_START "<B><FONT SIZE=\"+1\">" 
#define PBC_EM2_END "</FONT></B><BR>"

/* identify log messages */
#define ANY_LOGINSRV_MESSAGE "PUBCOOKIE_LOGINSRV_LOG"
#define SYSERR_LOGINSRV_MESSAGE "PUBCOOKIE SYSTEM ERROR"

/* flags to send to get_string_arg */
#define YES_NEWLINES_FUNC cgiFormString
#define NO_NEWLINES_FUNC cgiFormStringNoNewlines

/* flags to send to print_login_page */
#define YES_CLEAR_LOGIN 1
#define NO_CLEAR_LOGIN 0

/* flags to send to print_login_page_part1 */
#define YES_FOCUS 1
#define NO_FOCUS 1

/* keys and certs */
#define KEY_DIR "/usr/local/pubcookie/"
#define CRYPT_KEY_FILE "c_key"
#define CERT_FILE "pubcookie.cert"
#define CERT_KEY_FILE "pubcookie.key"

/* programs for creating and verifying cookies */
#define CREATE_PGM "/usr/local/pubcookie/pbc_create"
#define VERIFY_PGM "/usr/local/pubcookie/pbc_verify"

/* some misc settings */
#define SERIAL_FILE "/tmp/s"
#define FIRST_SERIAL 23

/* file to get the list of ok browsers from */
#define OK_BROWSERS_FILE "/usr/local/pubcookie/ok_browsers"

/* utility to send messages to pilot */
#define SEND_PILOT_CMD "/usr/local/adm/send_pilot_stat.pl"


/* text */
#define NOTOK_NO_G_OR_L_TEXT1 "<P><B><font size=\"+1\" color=\"#FF0000\">\
A problem has been detected!</font></B></P> \
\
<p><b><font size=\"+1\">Either your browser is not configured to accept \
cookies,\
or the URL address you opened contains a shortened domain name.</font></b></p>\
\
<p>Review \
<A HREF=\"http://www.washington.edu/computing/web/login-problems.html\">Common\
Problems With the UW NetID Login Page</A> for further advice.</p>\
\
<p>&nbsp;</p>"

#define J_TEST_TEXT1 "<SCRIPT LANGUAGE=\"JavaScript\"><!-- \
 \
name = \"cookie_test\"; \
s = (new Date().getSeconds()); \
document.cookie = name + \"=\" + s; \
 \
dc = document.cookie; \
prefix = name + \"=\"; \
begin = dc.indexOf(\"; \" + prefix); \
if (begin == -1) { \
    begin = dc.indexOf(prefix); \
    if (begin != 0) returned = \"\"; \
} else \
    begin += 2; \
end = document.cookie.indexOf(\";\", begin); \
if (end == -1) \
    end = dc.length; \
returned = unescape(dc.substring(begin + prefix.length, end)); \
 \
if ( returned == s ) { \
"

#define J_TEST_TEXT2 "    document.write(\"<P><B><font size=\\\"+1\\\" color=\\\"#FF0000\\\">A problem has been detected!</font></B></P>\");\
document.write(\"<p><b><font size=\\\"+1\\\">Either you tried to use the BACK button to return to pages you\");\
document.write(\" visited before the UW NetID login page, or the URL address you opened contains a shortened\");\
document.write(\" domain name. </font></b></p>\");\
document.write(\"<p>Review <A HREF=\\\"http://www.washington.edu/computing/web/login-problems.html\\\">Common\");\
document.write(\" Problems With the UW NetID Login Page</A> for further advice.</p>\");\
document.write(\"<p>&nbsp;</p>\");\
"

#define J_TEST_TEXT3 "    document.cookie = name + \"=; expires=Thu, 01-Jan-70 00:00:01 GMT\";\
}\
else {\
"

#define J_TEST_TEXT4 "    document.write(\"<P><B><font size=\\\"+1\\\" color=\\\"#FF0000\\\">This browser doesn't accept cookies!</font></B></P>\");\
document.write(\"<p><b><font size=\\\"+1\\\">Your browser must <a href=\\\"http://www.washington.edu/computing/web/cookies.html\\\">accept cookies</a> in\");\
document.write(\" order to use the UW NetID login page.</font></b></p>\");\
document.write(\"<p>&nbsp;</p>\");\
"

#define J_TEST_TEXT5 "}\
\
// -->\
</SCRIPT>\
"

#define NOTOK_NO_G_TEXT1 "<P><B><font size=\"+1\" color=\"#FF0000\">A problem has been detected!</font></B></P>\
\
<p><b><font size=\"+1\">Either you tried to use the BACK button to return to pages you visited before the UW NetID login page, or the URL address you opened contains a shortened domain name. </font></b></p>\
\
<p>Review <A HREF=\"http://www.washington.edu/computing/web/login-problems.html\">Common Problems With the UW NetID Login Page</A> for further advice.</p>\
\
<p>&nbsp;</p>\
"

#define NOTOK_FORMMULTIPART_TEXT1 "<P><B><font size=\"+1\" color=\"#FF0000\">A problem has been detected!</font></B></P> \
\
<p><b><font size=\"+1\">The resource you requested requires \"multipart/form-data\" capabilities not supported by the UW NetID login page. Please email <a href=\"mailto:help@cac.washington.edu\">help@cac.washington.edu</a> for further assistance.</font></b></p>\
\
<p>&nbsp;</p>\
"

#define NOTOK_BAD_AGENT_TEXT1 "<P><B><font size=\"+1\" color=\"#FF0000\">This browser is either incompatible or has serious security flaws.</font></B></P>\
\
<p><b><font size=\"+1\">Please upgrade to the most recent version of either <A HREF=\"http://home.netscape.com/computing/download/index.html\">Netscape Navigator</A>, <A HREF=\"http://www.microsoft.com/windows/ie/default.htm\">Internet Explorer</A>, or <A HREF=\"http://www.opera.com/\">Opera</A>.  The browser you are using identifies itself as:<P><TT>$ENV{'HTTP_USER_AGENT'}</TT><P>\
\
Please email <a href=\"mailto:help@cac.washington.edu\">help@cac.washington.edu</a> for further assistance.</font></b></p>\
\
<p>&nbsp;</p>\
"

#define NOTOK_GENERIC_TEXT1 "<P><B><font size=\"+1\" color=\"#FF0000\">A problem has been detected!</font></B></P> \
\
<p>Review <A HREF=\"http://www.washington.edu/computing/web/login-problems.html\">Common Problems With the UW NetID Login Page</A> for further advice.</p>\
\
<p>&nbsp;</p>\
"




