#ifndef ZRL_HTTP_PARSER
#define ZRL_HTTP_PARSER
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<iostream>
//直接通过parse()外接接口，对输入的文本进行文本解析，输入的文本需要转化为string类型
//如果只有头部，就只解析头部，如果头部和实体均存在则可以全部解析
class http_parser
{
public:
    http_parser():start(0){}
    void parse(const std::string&text);
    std:: string method() const;
    std:: string path()   const;
    std:: string protocolVersion() const;
    std:: string body() const;
    std:: vector<std::string> headerNames() const;
    std:: string header(const std::string& headerName);
    int start;
private:
    std:: string _method;
    std:: string _path;
    std:: string _protocolVersion;
    std:: map<std::string, std::string> _headers;
    std:: string _body;
    std:: string buff;
    std:: string readLine();


};
#endif