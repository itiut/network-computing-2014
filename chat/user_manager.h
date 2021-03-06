#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <stdbool.h>
#include "message_queue.h"

#define MAX_N_OF_USERS 100

typedef enum state_t {
    CONNECTED,
    JOINED,
    LEFT
} state_t;

typedef struct user {
    int fd;
    state_t state;
    char *name;
    message_queue_t queue;
} *user_t;

user_t create_user(int fd);
void delete_user(user_t user);

typedef struct user_manager {
    int n_of_users;
    user_t users[MAX_N_OF_USERS];
} *user_manager_t;

user_manager_t create_user_manager();
void delete_user_manager(user_manager_t manager);

int add_user(user_manager_t manager, int fd);
int delete_user_by_fd(user_manager_t manager, int fd);
user_t find_user_by_fd(user_manager_t manager, int fd);

bool user_joins(user_t user, const char *user_name);

#endif /* USER_MANAGER_H */
