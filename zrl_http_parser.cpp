#include"zrl_http_parser.h"
void http_parser::parse(const std::string&text)
{

    buff = std::move(text);
    std:: string line = readLine();
    std:: istringstream iss(line);
    //解析请求行
    iss>>_method>>_path>>_protocolVersion;

    //解析请求头
    line = readLine();
    while(!line.empty())
    {
        int colonIndex = line.find_first_of(':');
        auto name = line.substr(0, colonIndex);
        auto value = line.substr(colonIndex+1);
        _headers[name]=value;
        line=readLine();
    }
    _body = buff.substr(start);

}

std:: string http_parser::method() const
{
    return _method;
}


std:: string http_parser::path()   const
{
    return _path;
}


std:: string http_parser::protocolVersion() const
{
    return _protocolVersion;
}


std:: string http_parser::body() const
{

    return _body;;
}


std:: vector<std::string> http_parser::headerNames() const
{
    std:: vector<std::string> ret;

    for(auto&it:_headers)   //使用auto的最大好处在于可以避免写迭代器，这对于代码的简洁性有很大的帮助
    {
        ret.push_back(it.first);
    }
    return ret;
}


std:: string http_parser::header(const std::string& headerName)
{
    return _headers[headerName];
}



std::string http_parser::readLine()
{   std:: string ret;
    for(;start<buff.length();start++)
    {   ret.push_back(buff[start]);
        if(buff[start]=='\n')
        {   start++;
            break;
        }
    }

    return ret.substr(0,ret.find_first_of("\r\n"));
}



