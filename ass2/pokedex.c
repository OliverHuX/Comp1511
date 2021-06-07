// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c
//
// This program was written by Xiao Hu (z5223731)
// on 21/04/2019
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.
// Version 1.1.1: Renamed "pokemon_id" to "id" in change_current_pokemon.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.
//
// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.
#define DIFFERENCE 32

// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.

struct pokedex {
    struct pokenode *head;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    struct pokenode *evolution;
    Pokemon         pokemon;
    int state;//state is to define whether the Pokemon has been found or not!
    int index;//index is to define which Pokemon is current!
};

// Add any other structs you define here.


// Add prototypes for any extra functions you create here.

//This help function is to create new pokenode!
struct pokenode *newnode(Pokemon pokemon) {
    struct pokenode *n = malloc(sizeof (struct pokenode));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->pokemon = pokemon;
    n->evolution = NULL;
    n->next = NULL;
    n->state = 0;
    n->index = 0;
    return n;
}

//This help function is to creat a link list!
//This help function is to add each new pokenode into the end of list!
void add_pokemon_to_end(Pokedex pokedex, struct pokenode *n) {
    struct pokenode *current = pokedex->head;
    if (current == NULL) {
        pokedex->head = n;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = n;
    }
}

//This help function is to arrange link list in ascending order!
void sort_found_pokemon(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    struct pokenode *previous = pokedex->head;  
    struct pokenode *tmp = malloc(sizeof (struct pokenode));
    while (previous != NULL) {
        while (current != NULL) {
            if (pokemon_id(previous->pokemon) < pokemon_id(current->pokemon)) {
                tmp->pokemon = previous->pokemon;
                previous->pokemon = current->pokemon;
                current->pokemon = tmp->pokemon;
            }
            current = current->next;
        }
        previous = previous->next;
        current = pokedex->head;
    }
    free(tmp);
}

//This help function is to delete one Pokenode from link list!
void removePokenode(Pokedex pokedex) {
    struct pokenode *n = pokedex->head;
    struct pokenode *previous = NULL;
    while (n != NULL && n->index == 1) {
        previous = n;
        n = n->next;
    }
    if (previous == NULL) {
        if (n->next != NULL) {
            pokedex->head = n->next;
        } else {
            pokedex->head = n->next;
        }
        destroy_pokemon(n->pokemon);
        free(n);
    } else if (n != NULL) {
        if (n->next != NULL) {
            previous->index = 1;
        } else {
            previous->index = 0;
        }        
        previous->next = n->next;
        destroy_pokemon(n->pokemon);
        free(n);
    }
}

//This function is to creat a new Pokedex!
Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    new_pokedex->head = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    struct pokenode *current1 = newnode(pokemon);
    struct pokenode *current = pokedex->head;
    //Checking is there a Pokemon in the Pokedex with the same ID.
    if (current != NULL) {
        while (current != NULL) {
            if (pokemon_id(current->pokemon) == pokemon_id(current1->pokemon)) {
                printf("This Pokemon is already in Pokedex!\nSee U, mate!\n");
                destroy_pokemon(current1->pokemon);
                free(current1);
                exit(1);
            }
            current = current->next;
        }
    }
    add_pokemon_to_end(pokedex, current1);
}

void detail_pokemon(Pokedex pokedex) {
    int len = 0;
    char *length = pokemon_name(get_current_pokemon(pokedex));
    struct pokenode *current = pokedex->head;
    //Count the length of Pokemon.
    while (length[len] != '\0') {
        len++;
    }
    //Find the current Pokemon.
    while (current->index == 1) {
        current = current->next;
    }
    //Checking whether the current Pokemon is found ot not
    if (current->state == 0) {
        printf("Id: %03d\n", pokemon_id(get_current_pokemon(pokedex)));
        printf("Name: ");
        for (int i = 0; i < len; i++) {
            printf("*");
        }
        printf("\n");
        printf("Height: --\n");
        printf("Weight: --\n");
        printf("Type: --\n");
    } else { //THis Pokemon is been found.
        printf("Id: %03d\n", pokemon_id(get_current_pokemon(pokedex)));   
        printf("Name: %s\n", pokemon_name(get_current_pokemon(pokedex)));
        printf("Height: %.1lfm\n", pokemon_height(get_current_pokemon(pokedex)));
        printf("Weight: %.1lfkg\n", pokemon_weight(get_current_pokemon(pokedex)));
        if (pokemon_first_type(get_current_pokemon(pokedex)) != 0 && 
        pokemon_second_type(get_current_pokemon(pokedex)) != 0) {
            printf("Type: %s %s\n", 
            pokemon_type_to_string(pokemon_first_type(get_current_pokemon(pokedex)))
            , pokemon_type_to_string(pokemon_second_type(get_current_pokemon(pokedex))));
        } else if (pokemon_first_type(get_current_pokemon(pokedex)) != 0 && 
                   pokemon_second_type(get_current_pokemon(pokedex)) == 0) {
            printf("Type: %s\n", 
            pokemon_type_to_string(pokemon_first_type(get_current_pokemon(pokedex))));
        } else {
            printf("Type: %s\n", 
            pokemon_type_to_string(pokemon_second_type(get_current_pokemon(pokedex))));
        }
    }
}

Pokemon get_current_pokemon(Pokedex pokedex) {
    Pokemon curr; 
    struct pokenode *current = pokedex->head;
    //Checking whether the link list is NULL or not.
    if (current == NULL) {
        return NULL;
    } else if (current->index == 1) {//Find the current Pokemon when the first Pokemon is not current.
        while (current->index == 1 && current->next != NULL) {
            current = current->next;
        }
        curr = current->pokemon;
        return curr;
    } else {//The first Pokemon is current.
        curr = current->pokemon;
        return curr;
    }
}

void find_current_pokemon(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    //Checking whether the link list is NULL or not.
    if (current != NULL) {
        //Find the current Pokemon when the first Pokemon is not current.
        if (current->index == 1) {
            while (current->index == 1) {
                current = current->next;
            }
            current->state = 1;
        } else {//The first Pokemon is current.
            current->state = 1;
        }    
    }
}

void print_pokemon(Pokedex pokedex) { 
    struct pokenode *current = pokedex->head;
    //Checking whether the link list is NULL or not.
    if (get_current_pokemon(pokedex) != NULL) {
        //loop the whole list.
        while (current != NULL) {
            //Count the length of the current Pokemon's name.
            int len = 0;
            char *length = pokemon_name(current->pokemon);
            while (length[len] != '\0') {
                len++;  
            }
            //Print * if the current Pokemon is not been found.
            if(current->state == 0) {
                if (current->pokemon == get_current_pokemon(pokedex)) {
                    printf("--> ");
                    printf("#%03d: ", pokemon_id(current->pokemon));
                    for (int i = 0; i < len; i++) {
                        printf("*");
                    }
                    printf("\n");
                } else {
                    printf("    ");
                    printf("#%03d: ", pokemon_id(current->pokemon));
                    for (int i = 0; i < len; i++) {
                        printf("*");
                    }
                    printf("\n");
                }
            } else {
                //Print the normal information
                if (current->pokemon == get_current_pokemon(pokedex)) {
                    printf("--> ");
                    printf("#%03d: ", pokemon_id(current->pokemon));
                    printf("%s\n", pokemon_name(current->pokemon));
                } else {
                    printf("    ");
                    printf("#%03d: ", pokemon_id(current->pokemon));
                    printf("%s\n", pokemon_name(current->pokemon));
                }
            }
            current = current->next;
        }
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    //Checking whether the link list is NULL or not.
    if (current != NULL) {
        //Find the current Pokemon.
        while (current->index == 1) {
            current = current->next;
        }
        //Change the index into 1 to represent the current Pokemon.
        if (current->next != NULL) {
            current->index = 1;
        }
    }
}

void prev_pokemon(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    //Checking whether the link list is NULL or not.
    if (current != NULL && current->next != NULL) {
        //Find the the previous Pokemon of current Pokemon.
        while (current->next->index == 1) {
            current = current->next;
        }
        current->index = 0;
    }
}

void change_current_pokemon(Pokedex pokedex, int id) {
    struct pokenode *current = pokedex->head;
    int i = 0;
    //Checking whether the link list is NULL or not.
    while (current != NULL) {
        //Checking is there a Pokemon with the id.
        if (pokemon_id(current->pokemon) == id) {
            i = 1;
        }
        current = current->next;
    }
    current = pokedex->head;
    if (i == 1) {
        //Change the index of every pokenode into 0.
        while (current != NULL) {
            current->index = 0;
            current = current->next;
        }
        current = pokedex->head;
        //Loop the whole list and change the index into 1 until the Pokenode has the Pokemon with the id.
        while (pokemon_id(current->pokemon) != id && current->next != NULL) {
            current->index = 1;
            current = current->next;
        }
    }
}

void remove_pokemon(Pokedex pokedex) {
    //Make sure there is a link list.
    if (pokedex->head != NULL) {
        //Call help function.
        removePokenode(pokedex);
    }
}

void destroy_pokedex(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    struct pokenode *previous = NULL;
    //Loop the whole list and delete the pokenode from beginning.
    while (current != NULL) {
        previous = current;
        current = current->next;
        destroy_pokemon(previous->pokemon);
        free(previous);
    }
    //Delete the Pokedex.
    free(pokedex);
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {
    int random_n = 0, index = 0, bound = factor - 1;
    //The index is to represent that is there a Pokemon in the Pokedex with the id between 0 and factor-1.
    struct pokenode *current = pokedex->head;
    //Give srand a seed.
    srand(seed);
    //Produce a random number which is between 0 and factor-1.
    random_n = rand() % factor;
    //If there is no link list, print error and exit.
    if (current == NULL) {
        printf("There are no Pokemon in the Pokedex.\n");
        printf("See U, mate!\n");
        exit(1);
    } else {
        for (int i = 0; i < how_many; i++) {
            //produce a new random number.
            random_n = rand() % factor;
            //Loop the whole list to check is there a pokemon with the id which is same as random number
            while (current != NULL) {
                if (pokemon_id(current->pokemon) == random_n) {
                    current->state = 1;
                    index = 1;
                }
                current = current->next;
            }
        }
    }
    //There is no Pokemon in the Pokedex with the id between 0 and factor-1 if index = 0;
    if (index == 0) {
        printf("There are no Pokemon in the Pokedex with pokemon_id between 0 and %d.\n", bound);
        printf("See U, mate!\n");
        destroy_pokedex(pokedex);
        exit(1);
    }       
}

int count_found_pokemon(Pokedex pokedex) {
    int num = 0;
    struct pokenode *current = pokedex->head;
    //Loop the whole list.
    while (current != NULL) {
        //num plus one when the state of pokemon is 1
        if (current->state == 1) {
            num++;
        }
        current = current->next;
    }
    return num;
}

int count_total_pokemon(Pokedex pokedex) {
    int num = 0;
    struct pokenode *current = pokedex->head;
    //loop the whole list and count how many pokenode in the link list.
    while (current != NULL) {
        num++;
        current = current->next;
    }
    return num;    
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    struct pokenode *current1 = pokedex->head;
    struct pokenode *current2 = pokedex->head;

    //loop the list find the Pokenode has the Pokemon with the to_id
    while (current1 != NULL && pokemon_id(current1->pokemon) != to_id) {
        current1 = current1->next;
    }
    //loop the list find the Pokenode has the Pokemon with the from_id
    while (current2 != NULL && pokemon_id(current2->pokemon) != from_id) {
        current2 = current2->next;
    }
    //If the current1 and current2 both are NULL, which means there is no Pokemon the id between from_id and to_id.
    if (current1 == NULL && current2 == NULL) {
        printf("There is no Pokemon with the ID %d and %d.\nSee U, mate!\n", from_id, to_id);
        exit(1);
    } else if (from_id == to_id) {//Make sure the from_id and to_id are not same.
        printf("The provided from_id %d and to_id %d are same.\n", from_id, to_id);
        exit(1);
    } else if (current1 == NULL) {//Is there no Pokemon with to_id.
        printf("There is no Pokemon with the ID %d.\nSee U, mate!\n", to_id);
        exit(1);
    } else if (current2 == NULL) {//Is there no Pokemon with from_id.
        printf("There is no Pokemon with the ID %d.\nSee U, mate!\n", from_id);
        exit(1);
    } else if (current2->evolution == NULL) {//This Pokemon has not been evolved.
        current2->evolution = current1;
    } else {
        if (current2 != current1) {//This Pokemon has been evolved.
            current2->evolution = current1;
        }
    }
}   

void show_evolutions(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    if (current != NULL) {
        //find out the current pokenode by index.
        while (current->index == 1 && current->next != NULL) {
            current = current->next;
        }
        //print out the evolved Pokemon of current Pokemon.
        while (current != NULL) {
            if (current->state != 1) {
                if (current->evolution == NULL) {
                    printf("#%03d ???? [????]\n", pokemon_id(current->pokemon));
                } else {
                    printf("#%03d ???? [????] --> ", pokemon_id(current->pokemon));
                }
            } else {
                if (current->evolution == NULL) {
                    printf("#%03d %s ", pokemon_id(current->pokemon), pokemon_name(current->pokemon));
                    if (pokemon_second_type(current->pokemon) != 0) {
                        printf("[%s, %s]\n", pokemon_type_to_string(pokemon_first_type(current->pokemon)), 
                        pokemon_type_to_string(pokemon_second_type(current->pokemon)));
                    } else {
                        printf("[%s]\n", pokemon_type_to_string(pokemon_first_type(current->pokemon)));
                    }
                } else {
                    printf("#%03d %s ", pokemon_id(current->pokemon), pokemon_name(current->pokemon));
                    if (pokemon_second_type(current->pokemon) != 0) {
                        printf("[%s, %s] --> ", pokemon_type_to_string(pokemon_first_type(current->pokemon)), 
                        pokemon_type_to_string(pokemon_second_type(current->pokemon)));
                    } else {
                        printf("[%s] --> ", pokemon_type_to_string(pokemon_first_type(current->pokemon)));
                    }
                }
            }
            current = current->evolution;
        }
    }
}       

int get_next_evolution(Pokedex pokedex) {
    struct pokenode *current = pokedex->head;
    //Make sure there is a link list.
    if (current != NULL) {
        //Find the current Pokemon.
        while (current->index == 1 && current->next != NULL) {
            current = current->next;
        }
        //If the current Pokemon does not evolve, Print does not evolve.
        if (current->evolution == NULL) {
            return DOES_NOT_EVOLVE;
        } else {
            return pokemon_id(current->evolution->pokemon);
        }
    } else {
        printf("There is no Pokemon in the Pokedex!\nSee U, mate!\n");
        exit(1);
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    //Check the type is valid.
    if (type == NONE_TYPE || type == INVALID_TYPE || type == MAX_TYPE) {
        printf("U can't type NONE_TYPE, INVALID_TYPE and MAX_TYPE these three type!\n");
        exit(1);
    }
    struct pokedex *newpokedex = new_pokedex();
    struct pokenode *current = newpokedex->head;
    struct pokenode *current2 = pokedex->head;

    //loop the whole list.
    while (current2 != NULL) {
        //Check the Pokemon is found or not.
        if (current2->state == 1) {
            if (pokemon_first_type(current2->pokemon) == type || 
                pokemon_second_type(current2->pokemon) == type) {
                //add clonepokemon to newpokedex
                current = newnode(clone_pokemon(current2->pokemon));
                current->state = 1;
                add_pokemon_to_end(newpokedex, current);
            }
        }
        current2 = current2->next;
    }
    return newpokedex;
}

Pokedex get_found_pokemon(Pokedex pokedex) {
    struct pokedex *newpokedex = new_pokedex();
    struct pokenode *current = newpokedex->head;
    struct pokenode *current1 = pokedex->head;
    
    //Loop the whole list.
    while (current1 != NULL) {
        //Check the Pokemon is found or not.
        if (current1->state == 1) {
            //add clonepokemon to newpokedex
            current = newnode(clone_pokemon(current1->pokemon));
            //Mark this Pokemon found.
            current->state = 1;
            add_pokemon_to_end(newpokedex, current);
        }        
        current1 = current1->next;
    }
    //Call help function to rearrange the order of link list.
    sort_found_pokemon(newpokedex);
    return newpokedex;
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {
    struct pokenode *current = pokedex->head;
    //Crear a new Pokedex.
    struct pokedex *newpokedex = new_pokedex();
    struct pokenode *current1 = newpokedex->head;
    if (current == NULL) {
        return newpokedex;
    } else {
        char *name = pokemon_name(current->pokemon);
        //Index indicates the name of current Pokemon contains the text or not.
        //Assume it contains the same text.
        int i = 0, j = 0, index = 1;
        //To copy the first character of name and text.
        char copy_name, copy_text;
        while (current != NULL) {
            name = pokemon_name(current->pokemon);
            //This algorithm is to detect the current Pokemon contains the same text ot not.
            if (name[i] >= 'A' && name[i] <= 'Z') {
                copy_name = name[i] + DIFFERENCE;
            } else {
                copy_name = name[i];
            }
            if (text[j] >= 'A' && text[j] <= 'Z') {
                copy_text = text[j] + DIFFERENCE;
            } else {
                copy_text = text[j];
            }
            while (copy_name != '\0') {
                while (copy_name != copy_text && copy_name != '\0') {
                    i++;
                    if (name[i] >= 'A' && name[i] <= 'Z') {
                        copy_name = name[i] + DIFFERENCE;
                    } else {
                        copy_name = name[i];
                    }
                }
                while (copy_name == copy_text && copy_name != '\0' && copy_text != '\0') {
                    i++;
                    j++;
                    if (name[i] >= 'A' && name[i] <= 'Z') {
                        copy_name = name[i] + DIFFERENCE;
                    } else {
                        copy_name = name[i];
                    }
                    if (text[j] >= 'A' && text[j] <= 'Z') {
                        copy_text = text[j] + DIFFERENCE;
                    } else {
                        copy_text = text[j];
                    }
                }
            
                if (copy_name != '\0' && copy_text != '\0') {
                    j = 0;
                    if (text[j] >= 'A' && text[j] <= 'Z') {
                        copy_text = text[j] + DIFFERENCE;
                    } else {
                        copy_text = text[j];
                    }
                } else if (copy_name == '\0' && copy_text != '\0') {
                    index = 0;
                } else if (copy_name != '\0' && copy_text == '\0') {
                    copy_name = '\0';
                }
            }
            //When the index does not change and the current Pokemon is found.
            //Then add it to new Pokedex.
        
            if (index == 1 && current->state == 1) {
                current1 = newnode(clone_pokemon(current->pokemon));
                current1->state = 1;
                add_pokemon_to_end(newpokedex, current1);
            }
            current = current->next;
            i = 0, j = 0, index = 1;
        }
        return newpokedex;
    }
}

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.
