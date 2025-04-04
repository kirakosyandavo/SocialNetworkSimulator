#include"Post.h"
#include"Comment.h"
#include"User.h"
using namespace std;
int Post::p_id=0;
Post::Post(const string& content){
 id=++p_id;
 text_content=content;
 timestamp=time(nullptr); 
}
 void Post::addComment(const string& username,const string& content){
    comments.push_back(make_shared<Comment>(username,content));
 }
 void Post::display()const{
   cout<<"The post id is"<<id<<endl;
   cout<<"content is"<<text_content<<endl;
   cout<<ctime(&timestamp)<<endl;
}
   

 
 