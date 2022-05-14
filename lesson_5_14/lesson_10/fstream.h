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
	ofile.put('G');  //дһ���ַ�
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

		//1. �Զ����Ƶ���ʽ�����ļ��Ķ�д
		void read(ServerInfo& info){
			ifstream ifile(_file);
			ifile.read((char*)&info, sizeof(info));
		}

		void write(ServerInfo& info){
			ofstream ofile(_file);  //���ļ�
			ofile.write((char*)&info, sizeof(info));  //���ļ���д��info���������
			//������ʾ��ʱ�򣬻�����ʾ��ȫ������
		}



		//2. ���ı�����ʽ�����ļ��Ķ�д
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

			string port = to_string(info._port); //�Ȱ�int��תΪstring����
			ofile.write(port.c_str(), port.size());  
		}


		//3. ��IO������ʽ�����ļ��Ķ�д
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

	//�Զ����Ƶ���ʽ�����ļ��Ķ�д
	void server_test_1(){
		ServerInfo s = { "192.168.191.154", 21};
		ManagerConfig mc("mc.txt");
		mc.write(s);

		ServerInfo rs;
		ManagerConfig rmc("mc.txt");
		rmc.read(rs);
		cout << rs._ip << " " << rs._port << endl;
	}

	//���ı�����ʽ�����ļ��Ķ�д
	void server_test_2(){
		ServerInfo s = { "192.168.191.154", 21 };
		ManagerConfig mc("mc.txt");
		mc.write_txt(s);

		ServerInfo rs;
		ManagerConfig rmc("mc.txt");
		rmc.read_txt(rs);
		cout << rs._ip << " " << rs._port << endl;
	}


	//��IO������ʽ�����ļ��Ķ�д
	void server_test_3(){
		ServerInfo s = { "192.168.191.154", 21 };
		ManagerConfig mc("io.txt");
		mc.write_io(s);

		ServerInfo rs;
		ManagerConfig rmc("io.txt");
		rmc.read_io(rs);
		cout << rs._ip << " " << rs._port << endl;
	}


	//C�����е����л��ͷ����л�
	void server_test_4(){
		ServerInfo s = { "192.168.191.154", 21 };

		//���л�
		char buff[128];
		sprintf(buff, "%s %d", s._ip, s._port);

		//�����л�
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