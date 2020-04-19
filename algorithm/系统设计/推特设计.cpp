#include<iostream>
#include<string>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		
		if (userMap.find(userId) == userMap.end())
		{
			userMap[userId] = new user(userId);
		}
		times++;
		user *a = userMap[userId];
		a->postTweet(tweetId, times);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		if (userMap.find(userId) == userMap.end())
			return{ };
		user *a = userMap[userId];
		vector<int> t= a->getTweet();
		for (auto a : t)
			cout << a << "   ";
		cout << endl;
		return t;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followeeId == followerId)
			return;
		if (userMap.find(followerId) == userMap.end())
			userMap[followerId] = new user(followerId);
		if (userMap.find(followeeId) == userMap.end())
			userMap[followeeId] = new user(followeeId);
		user* follower = userMap[followerId];
		user* followee = userMap[followeeId];
		follower->followUser(followee);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (userMap.find(followerId) == userMap.end())
			return;
		if (userMap.find(followeeId) == userMap.end())
			return;
		user* follower = userMap[followerId];
		user* followee = userMap[followeeId];
		follower->unfollow(followee);
	}
private:
	class message {
	public:
		int times;
		int id;
		bool operator<(const message& a)const {
			return times < a.times;
		}
	};
	class user {
	public:
		user(int id):userId(id){ }
		
		void unfollow(user* followee) {
			if (followSet.find(followee) != followSet.end())
				followSet.erase(followee);
		}
		void followUser(user* followee) {
			if (followSet.find(followee) == followSet.end())
				followSet.insert(followee);
		}
		void postTweet(int id,int time) {
			newsList.push({time,id});
		}
		priority_queue<message, vector<message>, less<message>> getMessageList() {
			return newsList;
		}
		int getUserId() {
			return userId;
		}
		vector<int> getTweet() {
			priority_queue<message, vector<message>, less<message>> resultList = newsList;
			for (auto u : followSet) {
				auto list= u->getMessageList();
				while (!list.empty()) {
					resultList.push(list.top());
					list.pop();
				}
			}
			vector<int> res;
			int t = 0;
			while (!resultList.empty()&&t<10) {
				res.push_back(resultList.top().id);
				resultList.pop();
				t++;
			}
			return res;
		}
	private:
		set<user*> followSet;
		priority_queue<message, vector<message>, less<message>> newsList;
		int userId;
		
	};

	int times = 0;
	unordered_map<int, user*> userMap;
};

/*int main() {
	Twitter t;
	t.follow(1, 2);
	t.follow(1, 3);
	t.postTweet(1, 100);
	t.postTweet(2, 200);
	t.getNewsFeed(1);
	t.postTweet(3, 300);
	t.getNewsFeed(1);
	t.getNewsFeed(2);
	t.getNewsFeed(4);
	t.postTweet(1, 26);
	t.postTweet(3, 35);
	t.follow(2, 3);
	t.getNewsFeed(2);
	getchar();
	return 0;
}*/