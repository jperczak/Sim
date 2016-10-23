
#include "AVLTree.h"

unsigned char AVLTree::height(node* p)
{
    return p?p->height:0;
}

int AVLTree::bfactor(node* p)
{
    return height(p->right)-height(p->left);
}

void AVLTree::fixheight(node* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

node* AVLTree::rotateright(node* p)
{
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

node* AVLTree::rotateleft(node* q)
{
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

node* AVLTree::balance(node* p) // balancing the p node
{
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // balancing is not required
}

node* AVLTree::insert(node* p, IPAddress k) // insert k key in a tree with p root
{
    if( !p ) return new node(k);
    if( k<p->key )
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);
    return balance(p);
}

node* AVLTree::insertNode(node* p, node* k)
{
    if( !p ) return new node(k);
    if( k->key<p->key )
        p->left = insertNode(p->left,k);
    else
        p->right = insertNode(p->right,k);
    return balance(p);
}

node* AVLTree::findmin(node* p) // find a node with minimal key in a p tree
{
    return p->left?findmin(p->left):p;
}

node* AVLTree::removemin(node* p) // deleting a node with minimal key from a p tree
{
    if( p->left==0 )
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

node* AVLTree::remove(node* p, IPAddress k) // deleting k key from p tree
{
    if( !p ) return 0;
    if( k < p->key )
        p->left = remove(p->left,k);
    else if( k > p->key )
        p->right = remove(p->right,k);
    else //  k == p->key
    {
        node* q = p->left;
        node* r = p->right;
        delete p;
        if( !r ) return q;
        node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

node* AVLTree::search(IPAddress data, node *p)
{
    //TODO add to searching MASK value
    if(p != nullptr)
    {
        if(data == p->key)
        {
            return p;
        }
        else if(data < p->key)
        {
            return search(data, p->left);
        }
        else
        {
            return search(data, p->right);
        }
    }
    else
    {
        EV<<"The key wasn't found in the tree\n";
        return nullptr;
    }
}
