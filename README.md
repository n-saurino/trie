# Implement a Trie

A Trie (pronounced "try") is an efficient tree-like data structure for storing and retrieving strings. This implementation provides basic Trie operations including insertion, search, and prefix matching.

## Features

- Initialize an empty Trie data structure
- Insert new words into the Trie
- Search for complete words in the Trie
- Check if any word in the Trie starts with a given prefix

## API Reference

### Constructor

```java
Trie()
```

Initializes an empty Trie data structure.

### Methods

#### insert

```java
void insert(String word)
```

Inserts a new word into the Trie.

**Parameters:**
- `word`: The string to insert into the Trie

**Example:**
```java
Trie trie = new Trie();
trie.insert("hello");
```

#### search

```java
boolean search(String word)
```

Searches for a complete word in the Trie.

**Parameters:**
- `word`: The string to search for

**Returns:**
- `true` if the exact word exists in the Trie
- `false` otherwise

**Example:**
```java
Trie trie = new Trie();
trie.insert("hello");
trie.search("hello");  // returns true
trie.search("hell");   // returns false
```

#### startsWith

```java
boolean startsWith(String prefix)
```

Checks if any word in the Trie starts with the given prefix.

**Parameters:**
- `prefix`: The prefix to search for

**Returns:**
- `true` if any word in the Trie starts with the given prefix
- `false` otherwise

**Example:**
```java
Trie trie = new Trie();
trie.insert("hello");
trie.startsWith("hel");   // returns true
trie.startsWith("world"); // returns false
```

## Time Complexity

- Insert: O(m), where m is the length of the word
- Search: O(m), where m is the length of the word
- StartsWith: O(m), where m is the length of the prefix

## Space Complexity

- O(N * M), where N is the total number of words and M is the average length of words

## Usage Example

```java
Trie trie = new Trie();

// Insert some words
trie.insert("apple");
trie.insert("app");
trie.insert("apricot");

// Search for words
System.out.println(trie.search("apple"));    // true
System.out.println(trie.search("app"));      // true
System.out.println(trie.search("apricot"));  // true
System.out.println(trie.search("apt"));      // false

// Check prefixes
System.out.println(trie.startsWith("app"));  // true
System.out.println(trie.startsWith("apt"));  // false
```
