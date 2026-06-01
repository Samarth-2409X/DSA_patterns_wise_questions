class WordDictionary {
public:
    struct TrieNode {
        char data;
        TrieNode* children[26];
        bool isTerminal;
    };

    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode -> isTerminal = false;

        for(int i=0; i<26; i++){
            newNode -> children[i] = NULL;
        }
        return newNode;
    }

    TrieNode* root;

    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        TrieNode* crawler = root;

        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'a';

            if(crawler -> children[index] == NULL){
                crawler -> children[index] = getNode();
            }

            crawler = crawler -> children[index];
        }

        crawler -> isTerminal = true;
    }

    bool searchUtil(TrieNode* root, string word){
        TrieNode* crawler = root;

        for(int i=0; i<word.length(); i++){

            char ch = word[i];
            
            if(ch == '.'){

                for(int j=0; j<26; j++){

                    if(crawler -> children[j] != NULL){

                        if(searchUtil(crawler -> children[j], word.substr(i+1)) == true){
                            return true;
                        }

                    }
                }
                return false;
            }
            else if(crawler -> children[ch - 'a'] == NULL){
                return false;
            }

            crawler = crawler -> children[ch - 'a'];
        }
        return (crawler != NULL && crawler -> isTerminal == true);
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */