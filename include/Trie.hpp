#pragma once
#include <iostream>
#include <vector>

struct Node{
    char c_{};
    std::vector<Node*> children_ = std::vector<Node*>(26, nullptr);
    bool is_word_{false};
};


class Trie{
public:
    Trie();
    ~Trie();
    void Insert(std::string_view word);
    bool Search(std::string_view word);
    bool Prefix(std::string_view prefix);

private:
    Node* root_{nullptr};
};
