#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

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

int calc_height(struct node *root)
{
    int height_left = 0, height_right = 0;
    if (root == NULL)
        return 0;
    if (root -> left == NULL && root -> right == NULL)
        return 1;
    if (root -> left != NULL)
        height_left = calc_height(root -> left);
    if (root -> right != NULL)
        height_right = calc_height(root -> right);
    if (height_left > height_right)
        return height_left + 1;
    else
        return height_right + 1;
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
    printf("%d\n", calc_height(tree));
    destroy(tree);
    return 0;
}
