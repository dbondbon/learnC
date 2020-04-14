#ifndef LEETCODE2_H
#define LEETCODE2_H

#include "algorithm.h"

typedef struct _tweet {
	int tweet_id;
	int post_time;
}tweet;
typedef struct _user {
	int user_tweets_size;
	tweet user_tweets[10000];
	int user_friends_size;
	int user_friends[10000];
}user; 
typedef struct {
	long twitter_tweet_size;
	int flag_user[10000] = { 0 };
	user users[10000];
} Twitter;

Twitter* twitterCreate();
void twitterPostTweet(Twitter* obj, int userId, int tweetId);
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize);
void twitterFollow(Twitter* obj, int followerId, int followeeId);
void twitterUnfollow(Twitter* obj, int followerId, int followeeId);
void twitterFree(Twitter* obj);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

#endif
