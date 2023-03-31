#include <stdio.h>
#include <stdlib.h>

//дерево строится по тому же принципу, что в задаче на поиск высоты дерева, ввод заканчивается нулем

struct node {
    int value;
    struct node *left;
    struct node *right;
};

double avg = 0;

struct node *add(struct node *tree, int data) {
    if (tree == NULL)
    {
        tree = (struct node*)malloc(sizeof(struct node));
        tree -> value = data;
        tree -> left = tree -> right = NULL;
    }
    else if (data < tree -> value)
        tree -> left = add(tree -> left, data);
    else if (data > tree -> value)
        tree -> right = add(tree -> right, data);
    return tree;
}

void destroy(struct node *tree) {
    if (tree -> left != NULL)
        destroy(tree -> left);
    if (tree -> right != NULL)
        destroy(tree -> right);
    free(tree);
}

double count_avg(struct node *root, int div)
{
    if (root == NULL)
        return;
    if (root -> left == NULL && root -> right == NULL)
        avg = avg + (double)root -> value/div;
    count_avg(root -> left, root -> right == NULL ? div : div*2);
    count_avg(root -> right, root -> left == NULL ? div : div*2);
}

int main()
{
    struct node *tree = NULL;
    int a;
    while (1) {
        scanf("%d", &a);
        if (a == 0)
            break;
        tree = add(tree, a);
    }
    count_avg(tree, 1);
    printf("\nAverage leaf value: %.2lf\n", avg);
    destroy(tree);
    return 0;
}
