#pragma once

#include "../models/structs.h"
#include <iostream>
#include <string>
#include <vector>

// Tree Node
struct Node {
  std::string type;
  std::vector<Pokemon> pokemonList;
  std::vector<Node *> children;

  Node(const std::string &t) : type(t) {}
};

Node *insertIntoTree(Node *root, const std::string &type, const Pokemon &p);
void inorderDisplay(const Node *root);
void freeTree(Node *root);

void groupAndDisplayByType(const std::vector<Pokemon> &pokedex);
