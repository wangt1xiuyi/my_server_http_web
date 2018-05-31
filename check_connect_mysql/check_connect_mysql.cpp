//#include"/usr/include/mysql/mysql.h"
#include<mysql/mysql.h>
#include<iostream>
#include<string>
#include<string.h>
#include<cstdio>
#include"connection_pool.h"
#include<map>
using namespace std;
int main(int argc,char *argv[])
{
    map<string,string> users;
    if(argc!=3){
        return 0;
    }
    connection_pool *connPool=connection_pool::GetInstance("localhost","root","root","test_c",3306,5);
    MYSQL *mysql=connPool->GetConnection();
    if(mysql_query(mysql,"SELECT username,passwd FROM user"))
    {
        printf("INSERT error:%s\n",mysql_error(mysql));
        return -1;
    }
    MYSQL_RES *result=mysql_store_result(mysql);
    int num_fields=mysql_num_fields(result);
    MYSQL_FIELD *fields=mysql_fetch_fields(result);
    while(MYSQL_ROW row=mysql_fetch_row(result))
    {
        string temp1(row[0]);
        string temp2(row[1]);
        users[temp1]=temp2;
    }
    string name(argv[1]);
    string passwd(argv[2]);
    if(users.find(name)!=users.end()&&users[name]==passwd)
        printf("1\n");
    else
        printf("0\n");
    mysql_free_result(result);
    connPool->DestroyPool();
}

