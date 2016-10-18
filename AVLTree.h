#pragma once

#ifndef AVLTREE_H
#define AVLTREE_H

#include "IPAddress.h"

struct node
{
    IPAddress key;
    IPAddress dstAddress;
    int mask;
    int gate;

    unsigned char height;
    node* left;
    node* right;

    node(IPAddress k) {
        key = k;
        dstAddress = k;
        gate = -1;
        left = right = 0;
        height = 1;
        mask = 0;
    }
};

class AVLTree
{
public:
    AVLTree() { avlRoot = nullptr;};
    virtual ~AVLTree() {};

    void AddNodeElement(IPAddress address) {avlRoot = insert(avlRoot,address);};
    node* FindProperNode(IPAddress address) {return search(address, avlRoot);};

    IPAddress GetDstAddress(node* p) {return p->dstAddress;};
    int GetGate(node* p) {return p->gate;};

private:
    unsigned char height(node* p);
    int bfactor(node* p);
    void fixheight(node* p);
    node* rotateright(node* p);
    node* rotateleft(node* q);
    node* balance(node* p); // balancing the p node
    node* insert(node* p, IPAddress k); // insert k key in a tree with p root
    node* findmin(node* p); // find a node with minimal key in a p tree
    node* removemin(node* p); // deleting a node with minimal key from a p tree
    node* remove(node* p, IPAddress k); // deleting k key from p tree
    node* search(IPAddress data, node *p);

private:
    node* avlRoot;
};

#endif /*AVLTREE_H*/
