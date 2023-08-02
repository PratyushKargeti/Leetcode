class Solution {
public:
    // vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    //     vector<int>ans;
    //     for(int i=0;i<queries.size();i++)
    //     {
    //         string s=queries[i];
    //         map<char,int>m;
    //         for(int i=0;i<s.size();i++)
    //         {
    //             m[s[i]]++;
    //         }
    //         int fq=m.begin()->second;
    //         int count=0;
    //         for(int i=0;i<words.size();i++)
    //         {
    //             string t=words[i];
    //             map<char,int>mp;
    //             for(int i=0;i<t.size();i++)
    //             {
    //                 mp[t[i]]++;
    //             }
    //             int fw=mp.begin()->second;
    //             if(fw>fq) count++;
    //         }
    //         ans.push_back(count);
    //     }
    //     return ans;
    // }

    // Helper function to calculate the frequency of the lexicographically smallest  character in a string
    int getSmallestCharFrequency(string& s) {
        map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        return m.begin()->second;
    }

// Function to calculate the count of words with frequencies greater than the query frequency
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
    // Calculate frequencies of lexicographically smallest characters in the "words" vector
        vector<int> wordFrequencies;
        for (string& word : words) 
        {
            wordFrequencies.push_back(getSmallestCharFrequency(word));
        }

        // Sort the word frequencies vector
        sort(wordFrequencies.begin(), wordFrequencies.end());

        // Iterate over each query word and find the count of words with frequencies greater than the query frequency
        for (string& query : queries) 
        {
            int queryFrequency = getSmallestCharFrequency(query);
            int count = wordFrequencies.end() - upper_bound(wordFrequencies.begin(), wordFrequencies.end(), queryFrequency);
            ans.push_back(count);
        }
        return ans;
    }
};