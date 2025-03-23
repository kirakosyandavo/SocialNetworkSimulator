#ifndef USER
#define USER
#include<iostream>
#include<vector>
#include<memory>
#include"Post.h"
#include"Comment.h"
using namespace std;
class Post;
class User{
public:
 User(const std::string& username, const std::string& email, const std::string& profileDescription);
  void addFriend(int friendId);
  vector<shared_ptr<Post>>posts;
  void removeFriend(int friendId);
  void createPost(const std::string& content);
  void displayProfile() const;
  int getId() const;
  const string& getUsername() const;
   private: 
   static int m_id;
   int id;
   string m_username;
   string m_email;
   string m_profile_description;
   vector<int>friends;
};
#endif
