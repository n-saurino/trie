#include "Trie.hpp"

Trie::Trie(): root_(new Node()){
    // initialize root_ node
    root_->c_ = '_';
}

Trie::~Trie(){
    
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
    Node* curr_node{root_};
    for(auto c : prefix){
        if(!curr_node->children_[c - 'a']){
            return false;
        }
        curr_node = curr_node->children_[c - 'a'];
    } 
    return true;
} 