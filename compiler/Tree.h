#ifndef TREE_H
#define TREE_H

#define OKTREE    255
#define NOTOKTREE 0

#define npossibles 35

typedef unsigned char token;

typedef struct Tree{
    token  symbol;
    Tree   *ntoken; 
}Tree;

Tree INSTANCE;
Tree CONTROL;

#endif //TREE_H