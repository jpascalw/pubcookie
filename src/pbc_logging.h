#ifndef INCLUDED_PBC_LOGGING_H
#define INCLUDED_PBC_LOGGING_H

#define PBC_LOG_ERROR 0
#define PBC_LOG_AUDIT 1
#define PBC_LOG_DEBUG_LOW 2
#define PBC_LOG_DEBUG_VERBOSE 3

/**
 *Initializes the logging system.  Optional.
 */
void pbc_log_init();

/**
 *Log activity messages
 *@param logging_level the importance level of the message
 *@param message the message to be logged
 */
void pbc_log_activity(int logging_level, const char *message,...);

/**
 *Create well-formed messages to be logged
 *@param info the string that contains the actual message
 *@param user the user's id
 *@param app_id the app_id of the requesting application
 *@return a nicely-formatted string to be logged
 */
char* pbc_create_log_message(char *info, char *user, char *app_id);

/**
 *Closes the logging system.  Optional.
 */
void pbc_log_close();

#endif INCLUDED_PBC_LOGGING_H
