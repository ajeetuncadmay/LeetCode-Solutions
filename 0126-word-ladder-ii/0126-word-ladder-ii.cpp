#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
private:
    std::unordered_map<std::string, int> wordLevelMap;
    std::vector<std::vector<std::string>> result;
    std::string bWord;

    // Phase 2: Backtracking from endWord to beginWord
    void backtrack(std::string word, std::vector<std::string>& currentSequence) {
        // Base Case: If we traced back to the beginWord, store the valid path
        if (word == bWord) {
            std::vector<std::string> validPath = currentSequence;
            std::reverse(validPath.begin(), validPath.end());
            result.push_back(validPath);
            return;
        }

        int currentLevel = wordLevelMap[word];
        std::string originalWord = word;

        // Try changing every character of the current word
        for (int i = 0; i < word.size(); ++i) {
            char originalChar = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                
                // If the transformed word exists in our level map AND
                // belongs to the exact level right before our current level
                if (wordLevelMap.find(word) != wordLevelMap.end() && wordLevelMap[word] == currentLevel - 1) {
                    currentSequence.push_back(word);
                    backtrack(word, currentSequence);
                    currentSequence.pop_back(); // Backtrack
                }
            }
            word[i] = originalChar; // Undo change
        }
    }

public:
    std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord isn't even in the list, no transformation sequence is possible
        if (wordSet.find(endWord) == wordSet.end()) return {};

        bWord = beginWord;
        std::queue<std::string> q;
        
        // Phase 1: Standard BFS to establish level heights
        q.push(beginWord);
        wordLevelMap[beginWord] = 1;
        wordSet.erase(beginWord); // Marks as visited

        while (!q.empty()) {
            std::string word = q.front();
            q.pop();

            int currentLevel = wordLevelMap[word];

            // If we've reached the endWord, we don't need to dive into deeper levels
            if (word == endWord) break;

            std::string originalWord = word;
            for (int i = 0; i < word.size(); ++i) {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;

                    if (wordSet.find(word) != wordSet.end()) {
                        q.push(word);
                        wordLevelMap[word] = currentLevel + 1;
                        wordSet.erase(word); // Erase so other paths in deeper levels don't use it
                    }
                }
                word[i] = originalChar;
            }
        }

        // If endWord was mapped, it means a valid path exists; begin backtracking
        if (wordLevelMap.find(endWord) != wordLevelMap.end()) {
            std::vector<std::string> currentSequence = {endWord};
            backtrack(endWord, currentSequence);
        }

        return result;
    }
};