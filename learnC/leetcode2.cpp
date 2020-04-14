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
	return NULL;
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	ListNode* res = NULL;
	ListNode* temp = NULL;
	int node1_size = 1;
	int node2_size = 1;
	temp = l1;
	while (temp->next != NULL) {
		node1_size++;
		temp = temp->next;
	}
	temp = l2;
	while (temp->next != NULL) {
		node2_size++;
		temp = temp->next;
	}
	int* list1 = (int*)malloc(sizeof(int) * node1_size);
	temp = l1;
	for (int i = node1_size - 1; i >= 0; i--) {
		list1[i] = temp->val;
		temp = temp->next;
	}
	int* list2 = (int*)malloc(sizeof(int) * node2_size);
	temp = l2;
	for (int i = node2_size - 1; i >= 0; i--) {
		list2[i] = temp->val;
		temp = temp->next;
	}
	int i = 0;
	int val = 0;
	int add = 0;
	while (i < node1_size && i < node2_size) {
		val = list1[i] + list2[i] + add;
		add = 0; 
		if (val > 9) {
			val = val - 10;
			add = 1;
		}
		ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
		new_node->val = val;
		new_node->next = res;
		res = new_node;
		i++;
	}
	if (i == node1_size) {
		while (i < node2_size) {
			val = list2[i] + add;
			add = 0;
			if (val > 9) {
				val = val - 10;
				add = 1;
			}
			ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
			new_node->val = val;
			new_node->next = res;
			res = new_node;
			i++;
		}
	} else {
		while (i < node1_size) {
			val = list1[i] + add;
			add = 0;
			if (val > 9) {
				val = val - 10;
				add = 1;
			}
			ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
			new_node->val = val;
			new_node->next = res;
			res = new_node;
			i++;
		}
	}
	if (add == 1) {
		val = add;
		ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
		new_node->val = val;
		new_node->next = res;
		res = new_node;
	}
	free(list1);
	free(list2);
	return res;
}
