#ifndef COMMENT
#define COMMENT
#include<iostream>
#include<ctime>
class User;
class Comment{
    public:
Comment(const string & username,const string& content);
void display()const;
private:
 string m_content;
 time_t timestamp;
 string m_username;
};
#endif