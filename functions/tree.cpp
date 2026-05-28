#include "tree.h"
#include "search.h"

using namespace std;

// Tree Traversal
void inorderDisplay(const Node *root) {
  if (root == nullptr)
    return;

  for (Node *child : root->children) {
    cout << "[" << child->type << "]" << endl;
    for (const Pokemon &p : child->pokemonList) {
      cout << "  " << p.index << " " << p.pokemonName << " [" << p.type1;
      if (!p.type2.empty())
        cout << "/" << p.type2;
      cout << "]" << endl;
    }
  }
}

// Tree Cleanup
void freeTree(Node *root) {
  if (root == nullptr)
    return;

  for (Node *child : root->children)
    freeTree(child);

  delete root;
}

// Build the Tree for Pokedex
void groupAndDisplayByType(const vector<Pokemon> &pokedex) {
  Node *root = new Node("Pokedex");

  for (size_t i = 0; i < pokedex.size(); i++) {
    string types[] = {pokedex[i].type1, pokedex[i].type2};
    for (const string &type : types) {
      if (type.empty())
        continue;

      Node *targetNode = nullptr;

      for (Node *child : root->children) {
        if (child->type == type) {
          targetNode = child;
          break;
        }
      }

      if (targetNode == nullptr) {
        targetNode = new Node(type);
        root->children.push_back(targetNode);
      }

      targetNode->pokemonList.push_back(pokedex[i]);
    }
  }

  string query;
  cout << "Enter the type you want to view (e.g. 'Fire', or type 'All' for all "
          "types): ";
  cin >> query;
  cout << endl;

  string lowerQuery = toLowerStr(query);

  if (lowerQuery == "all") {
    inorderDisplay(root);
  } else {
    bool found = false;
    for (Node *child : root->children) {

      if (toLowerStr(child->type) == lowerQuery) {
        cout << "[" << child->type << "]" << endl;
        for (const Pokemon &p : child->pokemonList) {
          cout << "  " << p.index << " " << p.pokemonName << " [" << p.type1;
          if (!p.type2.empty())
            cout << "/" << p.type2;
          cout << "]" << endl;
        }
        found = true;
        break;
      }
    }

    if (!found) {
      cout << "No Pokemon found for type '" << query << "'." << endl;
    }
  }

  freeTree(root);
}
