#include <deque>
#include "Trie.hpp"

Trie::Trie(): root_(new Node()){
    // initialize root_ node
    root_->c_ = '_';
}

Trie::~Trie(){
    // need to do a graph traversal to deconstruct the Trie
    std::deque<Node*> q{};
    q.push_back(root_);

    while(!q.empty()){
        auto& curr_node{q.front()};    
        q.pop_front();
        for(int i{0}; i < curr_node->children_.size(); ++i){
            if(curr_node->children_[i]){
                q.push_back(curr_node->children_[i]);
            }
        }
        delete curr_node;
    }
}

//  Inserts the string word into the trie.
void Trie::Insert(std::string_view word){
    Node* curr_node = root_;
    for(auto c : word){
        // if character in trie, move down to child node
        if(!curr_node->children_[c - 'a']){
            curr_node->children_[c - 'a'] = new Node{c};
        }
        
        curr_node = curr_node->children_[c-'a'];
    }    
    curr_node->is_word_ = true; 
}

// Returns true if the string word is in the trie (i.e., was inserted before), 
// and false otherwise.
bool Trie::Search(std::string_view word){
    Node* curr_node{root_};
    for(auto c : word){
        if(!curr_node->children_[c - 'a']){
            return false;
        }
        curr_node = curr_node->children_[c - 'a'];
    }
    return curr_node->is_word_;
}

// Returns true if there is a previously inserted string word that has the 
// prefix prefix, and false otherwise.
bool Trie::Prefix(std::string_view prefix){
    if(prefix.size() == 0) return false;
    Node* curr_node{root_};
    for(auto c : prefix){
        if(!curr_node->children_[c - 'a']){
            return false;
        }
        curr_node = curr_node->children_[c - 'a'];
    } 
    return true;
} 