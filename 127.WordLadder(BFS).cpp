/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

*/

/*
注意点：
1. wordList 要从vector转化为unordered_set
因为要用要erase（keyword）--unordered_set
vector中erase（position)

2. 没从Queue 中pop出一个cur, 检查是否等于endWord: return count; 不然最终return 0.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int count = 0;
        queue<string> queue;
        unordered_set<string> wordDic;
        for(auto str: wordList)
        {
            wordDic.insert(str);
        }

        if(wordDic.find(endWord) == wordDic.end())
            return 0;

        queue.push(beginWord);
        wordDic.erase(beginWord);

        while(!queue.empty())
        {
            int size = queue.size();
            count++;
            for(int i = 0;  i < size; i++)
            {
                //pop cur + addChildren
                string cur = queue.front();
                queue.pop();
                if(cur == endWord) ///????????只有找到endWord时候才return count， 不然return 0；
                    return count;

                addChildren(cur, queue, wordDic, endWord);
            }
            //count++;
        }

        return 0;
    }

    void addChildren(string cur, queue<string> &queue, unordered_set<string> &wordDic, string endWord)
    {
        for(int i = 0; i < cur.length(); i++)
        {
            //change cur[i]'s char
            //char letter = cur[i];
            for(int j = 0; j < 26; j++)
            {
                //change to 26 char + check if the newWord in wordList + add to queue
                string newStr = cur;
                newStr[i] = 'a' + j;
                if(inList(newStr, wordDic))
                {
                    queue.push(newStr);
                    wordDic.erase(newStr);
                    if(newStr == endWord)
                        return;
                }
            }
            //cur[i] = letter;
        }
    }

    bool inList(string str, unordered_set<string> &wordDic)
    {
        bool inList = false;

        if(wordDic.find(str) != wordDic.end())
            inList = true;

        return inList;
    }
};
