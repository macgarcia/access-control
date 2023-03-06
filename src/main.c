#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"
#include "../include/configuration.h"
#include "../include/note_behavior.h"
#include "../include/note_list.h"
#include "../include/note.h"

#define TRUE 1

int main() {
    char title[100] = "Amazon teste";
    char user[100] = "macgarcia-teste 01";
    char pass[100] = "1234 789";

    /*
    char line[150] = "1|Teste 01|macgarcia|123";
    Note n = to_note_by_buffer_line(line);
    printf("%s", n.to_txt(n));
    printf("====================\n");
    n.to_string(n);
*/
    for (int i = 0; i < 1000; i++) {
        Note note = new_note(title, user, pass);


        printf("%s", note.to_txt(note));
        add_list(note);
    }
    print_list();
    printf("%d\n", get_size_list());
    /*
    Note note;
    printf("Title: ");
    gets(note.title);
    printf("User: ");
    gets(note.user);
    printf("Pass: ");
    gets(note.pass);

    printf("%d, %s, %s, %s", note.id, note.title, note.user, note.pass);
    pause_screen();
    */
    /*
    while(TRUE) {
        clear_screen();
        char* options[] = { "[1] - List all notes"
                          , "[2] - Create a new note"
                          , "[3] - Search by title"
                          , "[4] - Exit" };
        int choice = generic_menu(options, 4);
        process_user_choice(choice);
    }
    */
    return 0;
}
