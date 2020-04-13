#include <stdlib.h>
#include "leetcode2.h"

/** Initialize your data structure here. */
Twitter* twitterCreate() 
{
	Twitter* twitter = (Twitter *)malloc(sizeof(Twitter));
	twitter->twitter_tweet_size = 0;
	return twitter;
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) 
{
	user* cur_user = NULL;
	int index = 0;
	if (obj->flag_user[userId] == 0) {
		obj->flag_user[userId] = 1;
		obj->users[userId] = *(user*)malloc(sizeof(user));
		obj->users[userId].user_friends_size = 0;
	}
	cur_user = &(obj->users[userId]);
	index = cur_user->user_friends_size;
	cur_user->user_tweets[index] = *(tweet*)malloc(sizeof(tweet));
	cur_user->user_tweets[index].tweet_id = tweetId;
	cur_user->user_tweets[index].post_time = obj->twitter_tweet_size;
	obj->twitter_tweet_size += 1;
	cur_user->user_tweets_size += 1;
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) 
{

}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) 
{

}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) 
{

}

void twitterFree(Twitter* obj) 
{
	for (int i = 0; i < 10000; i++) {
		if (obj->flag_user[i] == 1) {
			free(&obj->users[i]);
		}
	}
	free(obj);
}
