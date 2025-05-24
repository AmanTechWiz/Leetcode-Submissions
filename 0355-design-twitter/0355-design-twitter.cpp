class Twitter {
private:
    int time;
    unordered_map<int,unordered_set<int>> fol;
    unordered_map<int,vector<pair<int,int>>> tweets;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time,tweetId);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto it : tweets[userId]) pq.push(it);

        for(auto it : fol[userId]){
            for(auto it2 : tweets[it]){
                pq.push(it2);
            }
        }

        vector<int>feed;
        int counter = 10;

        while(!pq.empty() && counter){
            feed.push_back(pq.top().second);
            pq.pop();
            counter--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */