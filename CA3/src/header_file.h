#define ZERO 0
#define ONE 1
typedef struct PostInfo post_info;
typedef struct UserInfo user_info;
typedef struct username_of_the_liker liker;

struct username_of_the_liker {
	char *username;
	liker *next;
};

struct PostInfo {
	int post_ID;
	int number_of_likes;
	char* post_text;
	liker *head_of_likers;
	post_info* next;
};
struct UserInfo {
	int number_of_posts;
	char *username;
	char *password;
	post_info *head_of_posts;
	user_info *next;
};

void add_liker(liker *head_of_likers, liker *new_liker);
void add_post(post_info *head_of_posts, post_info *new_post);
void add_user(user_info *head_of_nodes, user_info *new_node);
int cmd_detection (char *cmd_type);
void error_malloc(char* text);
void free_post(post_info *curr_post);
void free_user(user_info *curr_user);
void free_users(user_info *head_of_users);
char* get_input(int flag);
liker* NewLiker(void);
post_info* NewPost(void);
user_info* NewUser(void);
int num_of_posts(post_info* head_of_posts);
void print_file(user_info *head_of_users);
void print_post_info(user_info *curr_user);
user_info* search(user_info* head_of_users, char* username);