#include <stdio.h>
#include <string.h>

union UserData {
    char username[20];
    char email[30];
};

struct User {
    union UserData data;
    char password[20];
};

void registerUser(struct User *user) {
    printf("Registration\n");
    printf("Enter username: ");
    fgets(user->data.username, sizeof(user->data.username), stdin);
    user->data.username[strcspn(user->data.username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(user->password, sizeof(user->password), stdin);
    user->password[strcspn(user->password, "\n")] = '\0';

    printf("Registration successful!\n");
}

void loginUser(struct User *user) {
    char username[20];
    char password[20];

    printf("Login\n");
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (strcmp(username, user->data.username) == 0 && strcmp(password, user->password) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password!\n");
    }
}

int main() {
    struct User user;
    int choice;

    printf("Welcome!\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  // Consume the newline character

    switch (choice) {
        case 1:
            registerUser(&user);
            break;
        case 2:
            loginUser(&user);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}