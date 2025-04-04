#ifndef USER
#define USER
#include<iostream>
#include<vector>
#include<memory>
#include"Post.h"
#include"Comment.h"
class Post;
class User{
public:
 User(const std::string& username, const std::string& email, const std::string& profileDescription);
  void addFriend(int friendId);
  std::vector<std::shared_ptr<Post>>posts;
  void removeFriend(int friendId);
  void createPost(const std::string& content);
  void displayProfile() const;
  int getId() const;
  const std::string& getUsername() const;
   private: 
   static int m_id;
   int id;
   std::string m_username;
   std::string m_email;
   std::string m_profile_description;
   std::vector<int>friends;
};
#endif
