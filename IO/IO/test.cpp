#include <iostream>
using namespace std;

////C++文件IO流
//
////使用文件IO流用文本及二进制方式演示读写配置文件
//struct ServerInfo
//{
//	char _ip[32];  // ip
//	int _port;     // 端口
//};
//
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* configfile = "server.config")
//		: _configfile(configfile)
//	{}
//
//	void WriteBin(const ServerInfo& info)
//	{
//		// 这里注意使用二进制方式打开写
//		ofstream ofs(_configfile, ifstream::in | ifstream::binary);
//		ofs.write((const char*)&info, sizeof(ServerInfo));
//		ofs.close();
//	}
//
//	void ReadBin(ServerInfo& info)
//	{
//		// 这里注意使用二进制方式打开读
//		ifstream ifs(_configfile, ifstream::out | ifstream::binary);
//		ifs.read((char*)&info, sizeof(ServerInfo));
//		ifs.close();
//	}
//
//	void WriteText(const ServerInfo& info)
//	{
//		// 这里会发现IO流写整形比C语言那套就简单多了，
//		// C 语言得先把整形itoa再写
//		ofstream ofs(_configfile);
//		ofs << info._ip << endl;
//		ofs << info._port << endl;
//		ofs.close();
//	}
//	void ReadText(ServerInfo& info)
//	{
//		// 这里会发现IO流读整形比C语言那套就简单多了，
//		// C 语言得先读字符串，再atoi
//		ifstream ifs(_configfile);
//		ifs >> info._ip;
//		ifs >> info._port;
//		ifs.close();
//	}
//private:
//	string _configfile; // 配置文件
//};
//int main()
//{
//	ConfigManager cfgMgr;
//	ServerInfo wtinfo;
//	ServerInfo rdinfo;
//	strcpy(wtinfo._ip, "127.0.0.1");
//	wtinfo._port = 80;
//	// 二进制读写
//	cfgMgr.WriteBin(wtinfo);
//	cfgMgr.ReadBin(rdinfo);
//	cout << rdinfo._ip << endl;
//	cout << rdinfo._port << endl;
//	// 文本读写
//	cfgMgr.WriteText(wtinfo);
//	cfgMgr.ReadText(rdinfo);
//	cout << rdinfo._ip << endl;
//	cout << rdinfo._port << endl;
//	return 0;
//}
#include<sstream>
int main()
{
	int a = 12345678;
	string sa;
	// 将一个整形变量转化为字符串，存储到string类对象中
	stringstream s;
	s << a;
	s >> sa;
	// 将stringstream底层管理string对象设置成"",
	// 否则多次转换时，会将结果全部累积在底层string对象中
	//s.str("");
	s.clear(); // 清空s, 不清空会转化失败
	double d = 12.34;
	s << d;
	s >> sa;
	string sValue;
	sValue = s.str(); // str()方法：返回stringsteam中管理的string类型
	cout << sValue << endl;
	return 0;
}

int main()
{
	stringstream sstream;
	// 将多个字符串放入 sstream 中
	sstream << "first" << " " << "string,";
	sstream << " second string";
	cout << "strResult is: " << sstream.str() << endl;
	// 清空 sstream
	sstream.str("");
	sstream << "third string";
	cout << "After clear, strResult is: " << sstream.str() << endl;
	return 0;
}