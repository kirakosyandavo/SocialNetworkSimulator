#ifndef POST
#define POST
#include<iostream>
#include<ctime>
#include<vector>
class Comment;
class User;
class Post{
public:
 Post(const string& content);
 void addComment(const string& username,const string& content);
 void display()const; 
 
 private:
  static int p_id;
  int id; 
  time_t timestamp;
  string text_content;
  vector<shared_ptr<Comment>>comments;
};
#endif
