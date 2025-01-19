#include "gtest/gtest.h"
#include "Trie.hpp"  // Include the header for your Trie class

// Test Trie constructor
TEST(TrieTest, ConstructorTest) {
    Trie trie;
    EXPECT_NE(trie.Prefix(""), true);  // Prefix checks should return false for empty strings
}

// Test Insert and Search for a single word
TEST(TrieTest, InsertAndSearchSingleWord) {
    Trie trie;
    trie.Insert("apple");

    EXPECT_TRUE(trie.Search("apple"));  // Word "apple" should be found
    EXPECT_FALSE(trie.Search("app"));  // "app" is a prefix, not a word
    EXPECT_TRUE(trie.Prefix("app"));   // Prefix "app" should exist
    EXPECT_FALSE(trie.Search("banana")); // Word not inserted
}

// Test Insert and Search for multiple words
TEST(TrieTest, InsertAndSearchMultipleWords) {
    Trie trie;
    trie.Insert("apple");
    trie.Insert("app");
    trie.Insert("banana");

    EXPECT_TRUE(trie.Search("apple"));
    EXPECT_TRUE(trie.Search("app"));
    EXPECT_TRUE(trie.Search("banana"));

    EXPECT_FALSE(trie.Search("appl"));   // Prefix but not a complete word
    EXPECT_FALSE(trie.Search("bananaa")); // Word not inserted
    EXPECT_FALSE(trie.Search("grape"));  // Word not inserted
}

// Test Prefix functionality
TEST(TrieTest, PrefixTest) {
    Trie trie;
    trie.Insert("apple");
    trie.Insert("application");

    EXPECT_TRUE(trie.Prefix("app"));     // Common prefix
    EXPECT_TRUE(trie.Prefix("apple"));   // Exact match
    EXPECT_FALSE(trie.Prefix("banana")); // No such prefix
    EXPECT_TRUE(trie.Prefix("appl"));    // Partial match
    EXPECT_FALSE(trie.Prefix("x"));      // No such prefix
}

// Test edge cases
TEST(TrieTest, EdgeCases) {
    Trie trie;

    // Insert empty string
    trie.Insert("");
    EXPECT_TRUE(trie.Search(""));  // Empty string should now exist

    // Search for empty prefix
    EXPECT_TRUE(trie.Prefix(""));  // All words match the empty prefix

    // Insert duplicate words
    trie.Insert("test");
    trie.Insert("test");
    EXPECT_TRUE(trie.Search("test"));  // "test" should still exist

    // Case-sensitive words
    trie.Insert("Test");
    EXPECT_FALSE(trie.Search("test"));  // Assuming the trie is case-sensitive
    EXPECT_TRUE(trie.Search("Test"));   // "Test" should exist as-is
}