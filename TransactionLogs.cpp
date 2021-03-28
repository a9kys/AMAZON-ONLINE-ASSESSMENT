/*A startup that builds a chat app wants to identify highly social users. All the chat data is in a large log file with three values on each line - the sender ID, receipient ID, and the number of messages. Given a threshold number, find the number of users that appear at least as many times as this threshold.

For example:
USERA USERB 14
USERA USERC 94
USERB USERB 3
...
Note: On the third line, a user sents a message to himself.

Inputs
logs = a list of lines where each line is a string
threshold = a number

Output
Return a list of sorted user IDs. If the same user appears in the same line, only count them once.

Example:
Input:
logs:
345366 899212 45
029323 382391 23
382391 345366 15
029323 382391 77
345366 382391 23
029323 345366 13
382391 382391 23
...
threshold: 3

Output: [029323, 345366, 382391]
Explanation:
There are three users that have appear more than 3 times:
345366 appears 4 times.
382391 appears 5 times.
029323 appears 3 times.*/


vector<string> get_fraud_id(vector<string>& uid, int threshold) {
    vector<string> result;
    unordered_map <string, int> ump;
    vector<string> temp;
    int idx;
    string word;
    for (idx = 0; idx < uid.size(); idx++) {
        stringstream ss(uid[idx]);
        while (ss >> word) {
            temp.push_back(word);
        }
        if (temp[0] != temp[1]) {
            ump[temp[0]]++;
            ump[temp[1]]++;
        }
        else
            ump[temp[0]]++;
        temp.clear();
    }
    for (auto &i1 : ump) {
        if (i1.second >= threshold)
            result.push_back(i1.first);
    }

    sort(result.begin(), result.end(), [](const string& a, const string& b)
                                            {return stoi(a) > stoi(b); });

    return result;
}

