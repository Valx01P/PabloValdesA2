/* doublesort.c – Assignment 3: Word‐Level Doubly‐Linked Sorter
   Author: Pablo Valdes
   Affirmation of Originality: This program is entirely my own work.

   Description:
      This tool reads each “word” from an input file, strips
      out any punctuation, converts to lowercase, and maintains
      a doubly‐linked list of unique entries in alphabetical
      order as it goes.  When reading finishes, it can traverse
      forward (default) or backward (with -d) and write the
      sorted list to stdout or, if you supply -o filename,
      to that file.

   Example Usage:
      make
      ./doublesort input.txt
      ./doublesort -d input.txt


   Command‐line options (via getopt):
     -d             : dump list in reverse
     -o <out_file>  : write output to <out_file> (instead of stdout)
     input_file     : required name of the file to read
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

typedef struct WordNode {
    char            *text;
    struct WordNode *prev;
    struct WordNode *next;
} WordNode;

static void print_usage(const char *prog) {
    fprintf(stderr, "Usage: %s [-d] [-o output_file] input_file\n", prog);
}

static WordNode *create_node(const char *w) {
    WordNode *n = malloc(sizeof *n);
    if (!n) return NULL;
    n->text = strdup(w);
    if (!n->text) { free(n); return NULL; }
    n->prev = n->next = NULL;
    return n;
}

/* Inserts 'w' into *headp in sorted order; ignores duplicates */
static int insert_word(WordNode **headp, const char *w) {
    WordNode *cur = *headp, *prev = NULL;
    /* find insertion point */
    while (cur && strcmp(w, cur->text) > 0) {
        prev = cur;
        cur  = cur->next;
    }
    if (cur && strcmp(w, cur->text) == 0) {
        return 0;     /* already in list */
    }
    WordNode *n = create_node(w);
    if (!n) return -1;

    if (!prev) {
        /* at front */
        n->next = *headp;
        if (*headp) (*headp)->prev = n;
        *headp = n;
    } else {
        /* after prev */
        n->next      = prev->next;
        n->prev      = prev;
        prev->next   = n;
        if (n->next) n->next->prev = n;
    }
    return 1;
}

int main(int argc, char **argv) {
    int        opt, reverse = 0;
    char      *out_name = NULL;
    FILE      *in = NULL, *out = stdout;
    WordNode  *head = NULL;

    while ((opt = getopt(argc, argv, "do:")) != -1) {
        switch (opt) {
            case 'd': reverse  = 1;      break;
            case 'o': out_name = optarg; break;
            default:
                print_usage(argv[0]);
                return 1;
        }
    }
    if (optind >= argc) {
        print_usage(argv[0]);
        return 1;
    }

    in = fopen(argv[optind], "r");
    if (!in) {
        perror("Error opening input");
        return 1;
    }
    if (out_name) {
        out = fopen(out_name, "w");
        if (!out) {
            perror("Error opening output");
            fclose(in);
            return 1;
        }
    }

    /* buffer and parse loop */
    char buffer[256];
    int  idx = 0, ch;
    while ((ch = fgetc(in)) != EOF) {
        if (isalpha(ch)) {
            buffer[idx++] = tolower(ch);
            if (idx >= (int)sizeof buffer - 1) idx = sizeof buffer - 2;
        } else if (idx > 0) {
            buffer[idx] = '\0';
            if (insert_word(&head, buffer) < 0) {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }
            idx = 0;
        }
    }
    /* last word if file didn’t end on punctuation */
    if (idx > 0) {
        buffer[idx] = '\0';
        if (insert_word(&head, buffer) < 0) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    /* output */
    if (!reverse) {
        for (WordNode *p = head; p; p = p->next)
            fprintf(out, "%s\n", p->text);
    } else {
        WordNode *p = head;
        while (p && p->next) p = p->next;
        for (; p; p = p->prev)
            fprintf(out, "%s\n", p->text);
    }

    /* cleanup */
    for (WordNode *p = head; p; ) {
        WordNode *next = p->next;
        free(p->text);
        free(p);
        p = next;
    }
    if (out != stdout) fclose(out);
    fclose(in);
    return 0;
}
