#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

struct Node {
  std::string name;
  std::vector<Node*> children;
  
  Node(std::string name) {
    this->name = name;
  }
};

Node* findParent(const std::string& key, Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (root->name == key) {
        return root;
    }
    for (auto node : root->children) {
        Node* ans = findParent(key, node);
        if (ans) {
            return ans;
        }
    }
    return nullptr;
}

Node* findParent(std::string& key,  map<string, Node*>& keyMap) {
    for (auto& pair : keyMap) {
        Node* node = findParent(key, pair.second);
        if (node) {
            return node;
        }
    }
    return nullptr;
}

void PrintRelation(const std::string& key, Node* root, int height) {
    if (root == nullptr) {
        return;
    }
    
    for (int i = 1; i < height; i++) {
        std::cout << "--";
    }
    std::cout << root->name << std::endl;
    
    for (auto node : root->children) {
        PrintRelation(key, node, height + 1);
    }
}

void PrintRelation(map<string, Node*>& keyMap) {
    for (auto& pair : keyMap) {
        PrintRelation(pair.first, pair.second, 1);
    }
}

int main() 
{

    vector<unordered_map<string, string>> data;
    data.push_back({{"id","MR0001"}, {"isChild", "false"}, {"parentId", "nil"}});
    data.push_back({{"id","MR0002"}, {"isChild", "true"}, {"parentId", "MR0001"}});
    data.push_back({{"id","MR0003"}, {"isChild", "true"}, {"parentId", "MR0001"}});
    data.push_back({{"id","MR0004"}, {"isChild", "false"}, {"parentId", "nil"}});
    data.push_back({{"id","MR0005"}, {"isChild", "true"}, {"parentId", "MR0004"}});
    data.push_back({{"id","MR0006"}, {"isChild", "true"}, {"parentId", "MR0005"}});
    data.push_back({{"id","MR0007"}, {"isChild", "true"}, {"parentId", "MR0006"}});
    
    map<string, Node*> keyMap;

    for (auto& dict : data) {
       string currId = dict["id"];
       if (dict["parentId"] == "nil") {
         keyMap[currId] = new Node(currId);
       } else {
         string parentId = dict["parentId"];
         Node* parent = findParent(parentId, keyMap);
         parent->children.push_back(new Node(currId));
      }
    }
    
    PrintRelation(keyMap);
    return 0;
}
