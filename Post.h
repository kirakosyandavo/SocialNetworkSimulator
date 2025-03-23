#ifndef POST
#define POST
using namespace std;
#include"Comment.h"
#include"User.h"
class Comment;
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
