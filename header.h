#include <stdio.h>
#include <stdlib.h>
#define max 999
int arr[max];
int head[6];
int freehead;
int n;
void create_list();
int add_element(int m, int key);
int delete_element(int key, int m);
int count_total();
int count_single(int m);
void display_all();
void display_free();
void defragment();
int pop();
int push(int m);
int glob;
int minimum();
int maximum();
