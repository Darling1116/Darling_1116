#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

void test_ifstream(){
	ifstream ifile("io.h");
	char ch;
	/*while ((ch = ifile.get()) != EOF){
		cout << ch;
	}*/

	//while (ifile.get(ch)){
	//	cout << ch;
	//}

	while (ifile){
		cout << (char)ifile.get();
	}
}

void test_ofstream(){
	ofstream ofile("write.txt");
	ofile.put('G');  //写一个字符
	ofile.write(": I enjoy the sweet life.", 30);

}


namespace GXR{
	struct ServerInfo{
		char _ip[20];
		int _port;
	};


	struct ManagerConfig{
	public:
		ManagerConfig(const char* file)
			:_file(file){

		}

		//1. 以二进制的形式进行文件的读写
		void read(ServerInfo& info){
			ifstream ifile(_file);
			ifile.read((char*)&info, sizeof(info));
		}

		void write(ServerInfo& info){
			ofstream ofile(_file);  //打开文件
			ofile.write((char*)&info, sizeof(info));  //往文件中写入info里面的内容
			//但是显示的时候，会有显示不全的问题
		}



		//2. 以文本的形式进行文件的读写
		void read_txt(ServerInfo& info){
			ifstream ifile(_file);
			ifile.getline(info._ip, 20);

			char buff[20];
			ifile.getline(buff, 20);
			info._port = stoi(buff);
		}


		void write_txt(ServerInfo& info){
			ofstream ofile(_file);
			ofile.write(info._ip, strlen(info._ip));

			ofile.put('\n');

			string port = to_string(info._port); //先把int型转为string类型
			ofile.write(port.c_str(), port.size());  
		}


		//3. 以IO流的形式进行文件的读写
		void read_io(ServerInfo& info){
			ifstream ifile(_file);
			ifile >> info._ip >> info._port;

		}


		void write_io(ServerInfo& info){
			ofstream ofile(_file);
			ofile << info._ip << endl;
			ofile << info._port << endl;

		}

	private:
		string _file;
	};

	//以二进制的形式进行文件的读写
	void server_test_1(){
		ServerInfo s = { "192.168.191.154", 21};
		ManagerConfig mc("mc.txt");
		mc.write(s);

		ServerInfo rs;
		ManagerConfig rmc("mc.txt");
		rmc.read(rs);
		cout << rs._ip << " " << rs._port << endl;
	}

	//以文本的形式进行文件的读写
	void server_test_2(){
		ServerInfo s = { "192.168.191.154", 21 };
		ManagerConfig mc("mc.txt");
		mc.write_txt(s);

		ServerInfo rs;
		ManagerConfig rmc("mc.txt");
		rmc.read_txt(rs);
		cout << rs._ip << " " << rs._port << endl;
	}


	//以IO流的形式进行文件的读写
	void server_test_3(){
		ServerInfo s = { "192.168.191.154", 21 };
		ManagerConfig mc("io.txt");
		mc.write_io(s);

		ServerInfo rs;
		ManagerConfig rmc("io.txt");
		rmc.read_io(rs);
		cout << rs._ip << " " << rs._port << endl;
	}


	//C语言中的序列化和反序列化
	void server_test_4(){
		ServerInfo s = { "192.168.191.154", 21 };

		//序列化
		char buff[128];
		sprintf(buff, "%s %d", s._ip, s._port);

		//反序列化
		ServerInfo rs;
		sscanf(buff, "%s %d", &rs._ip, &rs._port);
		cout << rs._ip << " " << rs._port << endl;

	}


	void server_test_5(){
		ServerInfo s = { "192.168.191.154", 21 };
		//stringstream ss;
		//ss << s._ip << " " << s._port;
		//string buff = ss.str();
		//cout << buff << endl;

		ServerInfo info;
		stringstream ss;
		ss.str("192.168.191.154 21");
		ss >> info._ip >> info._port;
		cout << info._ip << " " << info._port << endl;
	}
}