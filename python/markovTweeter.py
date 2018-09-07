import urllib3
import tweepy
import re
import csv
import markovify

consumer_key = "YOURCONSUMERKEY"
consumer_secret = "YOURCONSUMERSECRET"
access_key = "YOURACCESSKEY"
access_secret = "YOURACCESSSECRET"

def get_all_tweets(user):
    all_tweets = []
    new_tweets = []
    
    auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
    auth.set_access_token(access_key, access_secret)
    client = tweepy.API(auth)
    
    new_tweets = client.user_timeline(screen_name=screen_name, count=200)
    
    while len(new_tweets) > 0:
        for tweet in new_tweets:
            if tweet.source == "Twitter for Android":
                all_tweets.append(tweet.text.encode("utf-8"))
        
        max_id = new_tweets[-1].id - 1
        new_tweets = client.user_timeline(screen_name=screen_name,
                                          count=200, max_id=max_id)
                                          
    return all_tweets
    
def clean_tweet(tweet):
    tweet = re.sub("https?\:\/\/", "", tweet)   #links
    tweet = re.sub("#\S+", "", tweet)           #hashtags
    tweet = re.sub("\.?@", "", tweet)           #at mentions
    tweet = re.sub("RT.+", "", tweet)           #Retweets
    tweet = re.sub("Video\:", "", tweet)        #Videos
    tweet = re.sub("\n", "", tweet)             #new lines
    tweet = re.sub("^\.\s.", "", tweet)         #leading whitespace
    tweet = re.sub("\s+", " ", tweet)           #extra whitespace
    tweet = re.sub("&", "and", tweet)       #encoded ampersands
    return tweet
    
def write_tweets_csv(tweets):
    with open('tweets..csv', 'wb') as f:
        writer = csv.writer(f)
        
        for tweet in tweets:
            tweet = clean_tweet(tweet)
            
            if tweet:
                writer.writerow([tweet])

#if __name__ == "__main__":
    #tweets = get_all_tweets("jessfraz")
    #write_tweets_csv(tweets)
        
    
                
    