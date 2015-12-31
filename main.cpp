// Copyright 2016 7kachika
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#define STU_MAX 5
#define CUS_MAX 5
#define ID_MAX 10
#define NAME_MAX 10
#define SCORE_MAX 3

using namespace std;

int choose(0);    // 選單序號
int menu(0);    // 選單
string admin;
string adminPW = "1234";
string *cName, *sName;

void defmenu() {

	cout << endl << "--------------------------------" << endl;
	cout << " 選課管理系統" << endl;
	cout << endl << " 1. 選課登入 " << endl;
	cout << endl << " 2. 成績輸入 " << endl;
	cout << endl << " 3. 後臺管理 " << endl;
	cout << endl << " 0. 離開系統 " << endl;
	cout << endl << "--------------------------------" << endl;
	cout << "請輸入選單序號: ";    cin >> choose;
	system("cls");
}

void stumenu() {

	cout << endl << "--------------------------------" << endl;
	cout << " 學生選課系統" << endl;
	cout << endl << " 1. 課程列表 " << endl;
	cout << " 2. 課程加選 " << endl;
	cout << " 3. 課程退選 " << endl;
	cout << " 4. 資料修改 " << endl;
	cout << endl << " 0. 登出系統 " << endl;
	cout << endl << "--------------------------------" << endl;
	cout << "請輸入選單序號: ";    cin >> choose;
	system("cls");
}

void cusmenu() {

	cout << endl << "--------------------------------" << endl;
	cout << " 成績輸入系統" << endl;
	cout << endl << " 1. 成績輸入 " << endl;
	cout << " 2. 資料修改 " << endl;
	cout << endl << " 0. 登出系統 " << endl;
	cout << endl << "--------------------------------" << endl;
	cout << "請輸入選單序號: ";    cin >> choose;
	system("cls");
}

void stueditmenu() {

	cout << endl << "--------------------------------" << endl;
	cout << " 學生資料修改" << endl;
	cout << endl << " 1.學號" << endl;
	cout << " 2.姓名" << endl;
	cout << " 3.課程上限" << endl;
	cout << endl << " 0.返回" << endl;

	cout << endl << "--------------------------------" << endl;
	cout << "請輸入要修改的選項: ";    cin >> choose;
	system("cls");
}

void backmenu() {

	cout << endl << "--------------------------------" << endl;
	cout << " 後臺管理系統" << endl;
	cout << endl << " 1. 課程列表 " << endl;
	cout << " 2. 新增課程 " << endl;
	cout << " 3. 修改課程 " << endl;
	cout << " 4. 移除課程 " << endl;
	cout << endl << " 5. 學生列表 " << endl;
	cout << " 6. 新增學生 " << endl;
	cout << " 7. 修改學生 " << endl;
	cout << " 8. 移除學生 " << endl;
	cout << endl << " 0. 返回目錄 " << endl;
	cout << endl << "--------------------------------" << endl;
	cout << "請輸入選單序號: ";    cin >> choose;
	system("cls");
}

void cuseditmenu() {

	cout << endl << "--------------------------------" << endl;
	cout << " 課程資料修改" << endl;
	cout << endl << " 1.編號" << endl;
	cout << " 2.名稱" << endl;
	cout << " 3.教師" << endl;
	cout << " 4.人數上限" << endl;
	cout << endl << " 0.返回" << endl;

	cout << endl << "--------------------------------" << endl;
	cout << "請輸入要修改的選項: ";    cin >> choose;
	system("cls");
}

class student {
	public:
		int sSize;    // 學生數目
		string *id;    // 學生學號
		string *name;    // 學生姓名
		int *cMax;    // 課程上限
		string **course;    // 已選課程
		string **score;    // 成績
		string sId;
		int sPow;
		int sLogin;
		string stuId, stuName;
		int cancel;
		string::size_type sFind;
		student(int isSize = 0, string *iid = NULL, string *iname = NULL, int *icMax = 0, string **icourse = NULL, string **iscore = NULL) : sSize(isSize), id(iid), name(iname), cMax(icMax), course(icourse), score(iscore) {
			if (isSize > 0) {
				sPow = sSize;
				sLogin = sSize;
				cMax = new int[sSize];
				id = new string[sSize];
				name = new string[sSize];
				course = new string*[sSize];
				score = new string*[sSize];
				for (int i = 0; i < sSize; i++) {
					course[i] = new string[CUS_MAX];
					score[i] = new string[CUS_MAX];
				}
				for (int i = 0, j = 0; i < sSize; i++) {
					cMax[i] = CUS_MAX;
					string chk = iid[i];
					if (iid != NULL)
						id[i] = iid[i];
					else
						id[i] = '1' + i;
					if (iname != NULL)
						name[i] = iname[i];
					else
						name[i] = 'A' + i;
					for (int j = 0; j < CUS_MAX; j++) {
						course[i][j] = score[i][j] = "";
					}
				}
			}
		}
		void add() {
			student stu;

			cout << endl << "--------------------------------" << endl;
			cout << "請輸入學生學號: ";    cin >> stuId;
			cout << "請輸入學生姓名: ";    cin >> stuName;
			system("cls");
			cancel = 0;
			for(int i = 0; i < sSize; i++) {
				sFind = id[i].find(stuId);
				if (sFind != id[i].npos) {
					cancel++;
					cout << endl << "--------------------------------" << endl;
					cout << " 學號 " << stuId << " 已存在。" << endl;

					cout << endl << "--------------------------------" << endl;
					system("PAUSE");
					system("cls");
					break;
				}
			}
			if (stuId.length() > ID_MAX) {
				cancel++;
				cout << endl << "--------------------------------" << endl;
				cout << " 超過學號長度上限 " << ID_MAX << " 。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
			}
			if (stuName.length() > NAME_MAX) {
				cancel++;
				cout << endl << "--------------------------------" << endl;
				cout << " 超過姓名長度上限 " << NAME_MAX << " 。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
			}
			if (cancel == 0) {
				stu.cMax = cMax;
				stu.id = id;
				stu.name = name;
				stu.course = course;
				stu.score = score;

				sPow = ++sSize;
				cMax = new int[sSize];
				id = new string[sSize];
				name = new string[sSize];
				course = new string*[sSize];
				score = new string*[sSize];
				for (int i = 0; i < sSize; i++) {
					course[i] = new string[CUS_MAX];
					score[i] = new string[CUS_MAX];
				}

				for (int i = 0; i < sSize; i++) {
					cMax[i] = CUS_MAX;
					for (int j = 0; j < CUS_MAX; j++)
						id[i] = name[i] = course[i][j] = score[i][j] = "";
				}

				for (int i = 0; i < sSize - 1; i++) {
					cMax[i] = stu.cMax[i];
					id[i] = stu.id[i];
					name[i] = stu.name[i];
					for (int j = 0; j < CUS_MAX; j++) {
						course[i][j] = stu.course[i][j];
						score[i][j] = stu.score[i][j];
					}
				}
				id[--sSize] = stuId;
				name[sSize++] = stuName;
				cout << endl << "--------------------------------" << endl;
				cout << " 新增了一筆學生資料。" << endl;
				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");
			}
			else {
				system("cls");
				cout << endl << "--------------------------------" << endl;
				cout << " 取消了新增學生資料。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");
			}
		}
		void print() {

			cout << endl << "--------------------------------" << endl;
			if (sSize > 0) {
				cout << "--------------------------------" << endl;
				cout << " 學生列表" << endl;

				cout << endl << "--------------------------------" << endl;
				cout << setw(ID_MAX) << "學號" << setw(NAME_MAX) << "姓名" << setw(10) << "課程上限" << endl;
				for (int i = 0; i < sSize; i++) {
					cout << setw(ID_MAX) << id[i] << setw(NAME_MAX) << name[i] << setw(10) << cMax[i];
					cout << endl;
				}
			}
			else {
				system("cls");
				cout << endl << "--------------------------------" << endl;
				cout << " 尚無學生資料。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");
			}
		}
		void get() {

			cout << endl << "--------------------------------" << endl;
			if (sPow < sSize) {
				int i = sPow;
				cout << "--------------------------------" << endl;
				cout << " 學生列表" << endl;
				cout << endl << "--------------------------------" << endl;
				cout << setw(ID_MAX) << "學號" << setw(NAME_MAX) << "姓名" << setw(10) << "課程上限" << endl;
				cout << setw(ID_MAX) << id[i] << setw(NAME_MAX) << name[i] << setw(10) << cMax[i] << endl;
				cout << endl << "--------------------------------" << endl;
				if (course[i][0] != "") {
					cout << setw(4) << "編號" << setw(NAME_MAX) << "課程" << setw(6) << "成績" << endl;
					for (int j = 0; j < CUS_MAX; j++) {
						if (course[i][j] != "")
							cout << setw(4) << j + 1 << setw(10) << course[i][j] << setw(6) << score[i][j] << endl;
					}
				}
				else cout << " 尚無任何課程。" << endl;
			}
			else {
				system("cls");
				cout << endl << "--------------------------------" << endl;
				cout << " 查無此學生資料。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");
			}
		}
		void load() {

			cout << endl << "--------------------------------" << endl;
			cout << "請輸入學生學號: ";    cin >> sId;

			for (int i = 0; i < sSize; i++) {
				sFind = id[i].find(sId);
				sPow = sSize;
				if (sFind != id[i].npos) {
					sPow = i;
					break;
				}
			}
			system("cls");
		}
		void del() {
			load();
			if (sPow < sSize) {
				get();
				char ans;
				cout << endl << "--------------------------------" << endl;
				cout << "確定要刪除這筆學生資料嗎? (y/n) : ";    cin >> ans;

				cout << endl << "--------------------------------" << endl;
				if ((ans == 'y') || (ans == 'Y')) {
					student stu;

					stu.cMax = cMax;
					stu.id = id;
					stu.name = name;
					stu.course = course;
					stu.score = score;

					cMax = new int[--sSize];
					id = new string[sSize];
					name = new string[sSize];
					course = new string*[sSize];
					score = new string*[sSize];
					for (int i = 0; i < sSize; i++) {
						course[i] = new string[CUS_MAX];
						score[i] = new string[CUS_MAX];
					}

					for (int i = 0, k = 0; i < sSize; i++, k++) {
						if (i == sPow)
							k++;
						cMax[i] = stu.cMax[k];
						id[i] = stu.id[k];
						name[i] = stu.name[k];
						for (int j = 0; j < CUS_MAX; j++) {
							course[i][j] = stu.course[k][j];
							score[i][j] = stu.score[k][j];
						}
					}
					system("cls");
					cout << endl << "--------------------------------" << endl;
					cout << " 刪除了一筆學生資料。" << endl;

					cout << endl << "--------------------------------" << endl;
					system("PAUSE");
					system("cls");
				}
				else {
					system("cls");
					cout << endl << "--------------------------------" << endl;
					cout << " 取消了刪除這筆學生資料。" << endl;

					cout << endl << "--------------------------------" << endl;
					system("PAUSE");
					system("cls");
				}
			}
		}
		void edit() {
			if (sPow < sSize) {
				int back(0);
				do {
					//cout << "sLogin = " << sLogin << ", sPow = " << sPow << ", sSize = " << sSize << endl;
					get();
					int i = sPow;
					stueditmenu();
					switch(choose) {
						case 1:
							cout << endl << "--------------------------------" << endl;
							cout << " 目前的學號為 " << id[i] << endl;
							cout << endl << "--------------------------------" << endl;
							cout << "請輸入要修改的學號: ";    cin >> stuId;
							system("cls");
							cancel = 0;
							for(int j = 0; j < sSize; j++) {
								sFind = id[j].find(stuId);
								if (sFind != id[j].npos) {
									cancel++;
									cout << endl << "--------------------------------" << endl;
									cout << " 學號 " << stuId << " 已存在。" << endl;

									cout << endl << "--------------------------------" << endl;
									system("PAUSE");
								}
							}
							if (stuId.length() > ID_MAX) {
								cancel++;
								cout << endl << "--------------------------------" << endl;
								cout << " 超過學號長度上限 " << ID_MAX << " 。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
							}
							if (cancel == 0) {
								id[i] = stuId;
								cout << endl << "--------------------------------" << endl;
								cout << " 修改了學號為 " << id[i] << " 。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								system("cls");
							}
							else {
								system("cls");
								cout << endl << "--------------------------------" << endl;
								cout << " 取消了修改學號。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								system("cls");
							}
							break;
						case 2:

							cout << endl << "--------------------------------" << endl;
							cout << " 目前的姓名為 " << name[i] << endl;
							cout << endl << "--------------------------------" << endl;
							cout << "請輸入要修改的姓名: ";    cin >> name[i];

							system("cls");
							cancel = 0;
							if (stuName.length() > NAME_MAX) {
								cancel++;
								cout << endl << "--------------------------------" << endl;
								cout << " 超過姓名長度上限 " << NAME_MAX << " 。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
							}
							if (cancel != 0) {
								cout << endl << "--------------------------------" << endl;
								cout << " 修改了姓名為 " << name[i] << " 。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								system("cls");
							}
							else {
								system("cls");
								cout << endl << "--------------------------------" << endl;
								cout << " 取消了修改姓名。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								system("cls");
							}
							break;
						case 3:

							system("cls");
							cout << endl << "--------------------------------" << endl;
							cout << " 目前的課程上限為 " << cMax[i] << endl;
							cout << endl << "--------------------------------" << endl;
							int cusMax;
							cout << "請輸入要修改的課程上限 (最大為 " << CUS_MAX << " ): ";    cin >> cusMax;
							if (cusMax <= CUS_MAX) {
								cMax[i] = cusMax;
								cout << endl << "--------------------------------" << endl;
								cout << " 修改了課程上限為 " << cMax[i] << " 。" << endl;
							}
							else {

								system("cls");
								cout << endl << "--------------------------------" << endl;
								cout << " 超過課程上限 " << CUS_MAX << " 。" << endl;
								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								cout << endl << "--------------------------------" << endl;
								cout << " 取消了修改課程上限。" << endl;
							}

							cout << endl << "--------------------------------" << endl;
							system("PAUSE");
							system("cls");
							break;
						case 0:
							back++;
							sPow = sSize;
							break;
						default:
							cout << endl << "--------------------------------" << endl;
							cout << " Error." << endl;

							cout << endl << "--------------------------------" << endl;
							system("PAUSE");
							system("cls");
							break;
					}
				}while(back == 0);
			}
			else {
				load();
				if (sPow >= sSize) {
					system("cls");
					cout << endl << "--------------------------------" << endl;
					cout << " 查無此學生資料。" << endl;

					cout << endl << "--------------------------------" << endl;
					system("PAUSE");
					system("cls");
				}
				else edit();
			}
		}
};

class course {
	public:
		int cSize;
		string *id;
		string *name;
		string *teacher;
		int *sMax;
		string **student;
		string **score;
		string cId;
		int cPow;
		int cLogin;
		string cusId, cusName, cusTeacher;
		int cancel;
		string::size_type cFind;
		course (int icSize = 0, string *iid = NULL, string *iname = NULL, string *iteacher = NULL, int *isMax = 0, string **istudent = NULL, string **iscore = NULL) : cSize(icSize), id(iid), name(iname), teacher(iteacher), sMax(isMax), student(istudent), score(iscore) {
			if (icSize > 0) {
				cPow = cSize;
				cLogin = cSize;
				sMax = new int[cSize];
				id = new string[cSize];
				name = new string[cSize];
				teacher = new string[cSize];
				student = new string*[cSize];
				score = new string*[cSize];
				for (int i = 0; i < cSize; i++) {
					student[i] = new string[STU_MAX];
					score[i] = new string[STU_MAX];
				}
				for (int i = 0; i < cSize; i++) {
					sMax[i] = STU_MAX;
					id[i] = '1' + i;
					name[i] = cName[i];
					teacher[i] = cName[i] + "老師";
					for (int j = 0; j < STU_MAX; j++) {
						student[i][j] = score[i][j] = "";
					}
				}
			}
		}
		void add() {
			course cus;

			cout << endl << "--------------------------------" << endl;
			cout << "請輸入課程編號: ";    cin >> cusId;
			cout << "請輸入課程名稱: ";    cin >> cusName;
			cout << "請輸入課程教師: ";    cin >> cusTeacher;
			system("cls");
			cancel = 0;
			for (int i = 0; i < cSize; i++) {
				cFind = id[i].find(cusId);
				if (cFind != id[i].npos) {
					cancel++;
					cout << endl << "--------------------------------" << endl;
					cout << " 課程編號 " << cusId << " 已存在。" << endl;

					cout << endl << "--------------------------------" << endl;
					system("PAUSE");
				}
			}
			if (cusId.length() > ID_MAX) {
				cancel++;
				cout << endl << "--------------------------------" << endl;
				cout << " 超過編號長度上限 " << ID_MAX << " 。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
			}
			if (cusName.length() > NAME_MAX) {
				cancel++;
				cout << endl << "--------------------------------" << endl;
				cout << " 超過名稱長度上限 " << NAME_MAX << " 。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
			}
			if (cusTeacher.length() > NAME_MAX) {
				cancel++;
				cout << endl << "--------------------------------" << endl;
				cout << " 超過教師長度上限 " << NAME_MAX << " 。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
			}
			if (cancel == 0) {
				cus.sMax = sMax;
				cus.id = id;
				cus.name = name;
				cus.teacher = teacher;
				cus.student = student;
				cus.score = score;

				cPow = ++cSize;
				sMax = new int[cSize];
				id = new string[cSize];
				name = new string[cSize];
				teacher = new string[cSize];
				student = new string*[cSize];
				score = new string*[cSize];
				for (int i = 0; i < cSize; i++) {
					student[i] = new string[STU_MAX];
					score[i] = new string[STU_MAX];
				}

				for (int i = 0; i < cSize; i++) {
					sMax[i] = STU_MAX;
					for (int j = 0; j < STU_MAX; j++)
						id[i] = name[i] = teacher[i] = student[i][j] = score[i][j] = "";
				}

				for (int i = 0; i < cSize - 1; i++) {
					sMax[i] = cus.sMax[i];
					id[i] = cus.id[i];
					name[i] = cus.name[i];
					teacher[i] = cus.teacher[i];
					for (int j = 0; j < STU_MAX; j++) {
						student[i][j] = cus.student[i][j];
						score[i][j] = cus.score[i][j];
					}
				}
				id[--cSize] = cusId;
				name[cSize] = cusName;
				teacher[cSize++] = cusTeacher;

				cout << endl << "--------------------------------" << endl;
				cout << " 新增了一筆課程資料。" << endl;
				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");

			}
			else {
				cout << endl << "--------------------------------" << endl;
				cout << " 取消了新增課程資料。" << endl;
				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");
			}
		}
		void print() {

			cout << endl << "--------------------------------" << endl;
			if (cSize > 0) {
				cout << "--------------------------------" << endl;
				cout << " 課程列表" << endl;

				cout << endl << "--------------------------------" << endl;
				cout << setw(ID_MAX) << "編號" << setw(NAME_MAX) << "名稱" << setw(NAME_MAX) << "教師" << setw(10) << "人數上限" << endl;
				for (int i = 0; i < cSize; i++) {
					cout << setw(ID_MAX) << id[i] << setw(NAME_MAX) << name[i] << setw(NAME_MAX) << teacher[i] << setw(10) << sMax[i];
					cout << endl;
				}
			}
			else {
				system("cls");
				cout << endl << "--------------------------------" << endl;
				cout << " 尚無課程資料。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");
			}
		}
		void get() {
			cout << endl << "--------------------------------" << endl;
			if (cPow < cSize) {
				int i = cPow;
				cout << "--------------------------------" << endl;
				cout << " 課程列表" << endl;

				cout << endl << "--------------------------------" << endl;
				cout << setw(ID_MAX) << "編號" << setw(NAME_MAX) << "名稱" << setw(NAME_MAX) << "教師" << setw(10) << "人數上限" << endl;
				cout << setw(ID_MAX) << id[i] << setw(NAME_MAX) << name[i] << setw(NAME_MAX) << teacher[i] << setw(10) << sMax[i] << endl;
				cout << endl << "--------------------------------" << endl;
				if (student[i][0] != "") {
					cout << setw(4) << "座號" << setw(NAME_MAX) << "學生" << setw(6) << "成績" << endl;
					for (int j = 0; j < STU_MAX; j++) {
						if (student[i][j] != "")
							cout << setw(4) << j + 1 << setw(10) << student[i][j] << setw(6) << score[i][j] << endl;
					}
				}
				else cout << " 尚無任何學生。" << endl;
			}
			else {
				system("cls");
				cout << endl << "--------------------------------" << endl;
				cout << " 查無此課程資料。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");
			}
		}
		void load() {

			cout << endl << "--------------------------------" << endl;
			cout << "請輸入課程編號: ";    cin >> cId;

			for (int i = 0; i < cSize; i++) {
				cFind = id[i].find(cId);
				cPow = cSize;
				if (cFind != id[i].npos) {
					cPow = i;
					break;
				}
			}
			system("cls");
		}
		void del() {
			load();
			if (cPow < cSize) {
				get();
				char ans;
				cout << endl << "--------------------------------" << endl;
				cout << "確定要刪除這門課程資料嗎? (y/n) : ";    cin >> ans;

				cout << endl << "--------------------------------" << endl;
				if ((ans == 'y') || (ans == 'Y')) {
					course cus;

					cus.sMax = sMax;
					cus.id = id;
					cus.name = name;
					cus.teacher = teacher;
					cus.student = student;
					cus.score = score;

					sMax = new int[--cSize];
					id = new string[cSize];
					name = new string[cSize];
					teacher = new string[cSize];
					student = new string*[cSize];
					score = new string*[cSize];
					for (int i = 0; i < cSize; i++) {
						student[i] = new string[STU_MAX];
						score[i] = new string[STU_MAX];
					}

					for (int i = 0, k = 0; i < cSize; i++, k++) {
						if (i == cPow)
							k++;
						sMax[i] = cus.sMax[k];
						id[i] = cus.id[k];
						name[i] = cus.name[k];
						teacher[i] = cus.teacher[k];
						for (int j = 0; j < STU_MAX; j++) {
							student[i][j] = cus.student[k][j];
							score[i][j] = cus.score[k][j];
						}
					}
					system("cls");
					cout << endl << "--------------------------------" << endl;
					cout << " 刪除了一筆課程資料。" << endl;

					cout << endl << "--------------------------------" << endl;
					system("PAUSE");
					system("cls");
				}
				else {
					system("cls");
					cout << endl << "--------------------------------" << endl;
					cout << " 取消了刪除這門課程資料。" << endl;

					cout << endl << "--------------------------------" << endl;
					system("PAUSE");
					system("cls");
				}
			}
		}
		void edit() {
			if (cPow < cSize) {
				int back(0);
				do {
					//cout << "cLogin = " << cLogin << ", cPow = " << cPow << ", cSize = " << cSize << endl;
					get();
					int i = cPow;
					cuseditmenu();
					switch(choose) {
						case 1:
							cout << endl << "--------------------------------" << endl;
							cout << " 目前的編號為 " << id[i] << endl;
							cout << endl << "--------------------------------" << endl;
							cout << "請輸入要修改的編號: ";    cin >> cusId;
							system("cls");
							cancel = 0;
							for (int j = 0; j < cSize; j++) {
								cFind = id[j].find(cusId);
								if (cFind != id[j].npos) {
									cancel++;
									cout << endl << "--------------------------------" << endl;
									cout << " 課程編號 " << cusId << " 已存在。" << endl;

									cout << endl << "--------------------------------" << endl;
									system("PAUSE");
								}
							}
							if (cusId.length() > ID_MAX) {
								cancel++;
								cout << endl << "--------------------------------" << endl;
								cout << " 超過編號長度上限 " << ID_MAX << " 。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
							}
							if (cancel == 0) {
								id[i] = cusId;
								cout << endl << "--------------------------------" << endl;
								cout << " 修改了課程編號為 " << cusId << " 。" << endl;
								cout << endl << "--------------------------------" << endl;
								system("PAUSE");

							}
							else {
								cout << endl << "--------------------------------" << endl;
								cout << " 取消了修改課程編號。" << endl;
								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								system("cls");
							}
							break;
						case 2:

							cout << endl << "--------------------------------" << endl;
							cout << " 目前的名稱為 " << name[i] << endl;
							cout << endl << "--------------------------------" << endl;
							cout << "請輸入要修改的名稱: ";    cin >> name[i];

							system("cls");
							cancel = 0;
							if (cusName.length() > NAME_MAX) {
								cancel++;
								cout << endl << "--------------------------------" << endl;
								cout << " 超過名稱長度上限 " << NAME_MAX << " 。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
							}
							if (cancel != 0) {
								cout << endl << "--------------------------------" << endl;
								cout << " 修改了名稱為 " << name[i] << " 。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								system("cls");
							}
							else {
								cout << endl << "--------------------------------" << endl;
								cout << " 取消了修改課程名稱。" << endl;
								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								system("cls");
							}
							break;
						case 3:

							cout << endl << "--------------------------------" << endl;
							cout << " 目前的教師為 " << teacher[i] << endl;
							cout << endl << "--------------------------------" << endl;
							cout << "請輸入要修改的教師: ";    cin >> teacher[i];

							system("cls");
							cancel = 0;
							if (cusTeacher.length() > NAME_MAX) {
								cancel++;
								cout << endl << "--------------------------------" << endl;
								cout << " 超過教師長度上限 " << NAME_MAX << " 。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
							}
							if (cancel != 0) {
								cout << endl << "--------------------------------" << endl;
								cout << " 修改了教師為 " << teacher[i] << " 。" << endl;

								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								system("cls");
							}
							else {
								cout << endl << "--------------------------------" << endl;
								cout << " 取消了修改課程教師。" << endl;
								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								system("cls");
							}
							break;
						case 4:

							cout << endl << "--------------------------------" << endl;
							cout << " 目前的人數上限為 " << sMax[i] << endl;
							cout << endl << "--------------------------------" << endl;
							int stuMax;
							cout << "請輸入要修改的人數上限 (最大為 " << STU_MAX << " ): ";    cin >> stuMax;
							if (stuMax <= STU_MAX) {
								sMax[i] = stuMax;
								system("cls");
								cout << endl << "--------------------------------" << endl;
								cout << " 修改了人數上限為 " << sMax[i] << " 。" << endl;
							}
							else {
								system("cls");
								cout << endl << "--------------------------------" << endl;
								cout << " 超過人數上限 " << STU_MAX << " 。" << endl;
								cout << endl << "--------------------------------" << endl;
								system("PAUSE");
								cout << endl << "--------------------------------" << endl;
								cout << " 取消了修改人數上限。" << endl;
							}


							cout << endl << "--------------------------------" << endl;
							system("PAUSE");
							system("cls");
							break;
						case 0:
							back++;
							cPow = cSize;
							break;
						default:
							cout << endl << "--------------------------------" << endl;
							cout << " Error." << endl;

							cout << endl << "--------------------------------" << endl;
							system("PAUSE");
							system("cls");
							break;
					}
				}while(back == 0);
			}
			else {
				load();
				if (cPow >= cSize) {
					system("cls");
					cout << endl << "--------------------------------" << endl;
					cout << " 查無此課程資料。" << endl;

					cout << endl << "--------------------------------" << endl;
					system("PAUSE");
					system("cls");
				}
				else edit();
			}
		}
};


void addCourse(student stu, course cus) {
	stu.get();
	cus.load();
	stu.get();
	cus.get();
	int s = stu.sPow;
	int c = cus.cPow;
	int success(0);
	if (cus.cPow < cus.cSize) {
		char ans;
		cout << endl << "--------------------------------" << endl;
		cout << "確定要加選這門課程嗎? (y/n) : ";    cin >> ans;

		if ((ans == 'y') || (ans == 'Y')) {
			int stuCount(0);
			int cusCount(0);
			for (int j = 0; j < stu.cMax[s]; j++) {
				stuCount += (stu.course[s][j] != "") ? 1 : 0;
			}
			for (int j = 0; j < cus.sMax[c]; j++) {
				cusCount += (cus.student[c][j] != "") ? 1 : 0;
			}

			if (stuCount >= stu.cMax[s]) {
		cout << endl << "--------------------------------" << endl;
				cout << " 已達加選課程上限。" << endl;
			}
			else if (cusCount >= cus.sMax[c]) {
		cout << endl << "--------------------------------" << endl;
				cout << " 這門課程已達人數上限。" << endl;
			}
			else {
				for (int j = 0; j < stu.cMax[s]; j++) {
					if (stu.course[s][j] == cus.name[c]) {
		cout << endl << "--------------------------------" << endl;
						cout << " 重複加選這門課程。" << endl;
						break;
					}
					else if (stu.course[s][j] == "") {
						stu.course[s][j] = cus.name[c];
						for (int k = 0; k < cus.sMax[c]; k++) {
							if (cus.student[c][k] == "") {
								cus.student[c][k] = stu.name[s];
								break;
							}
						}
						success++;
						break;
					}
				}
			}
		}
	}

	if (success != 0) {
		cout << endl << "--------------------------------" << endl;
		cout << " 加選了這門課程。" << endl;

		cout << endl << "--------------------------------" << endl;
		system("PAUSE");
		system("cls");
	}
	else{
		cout << endl << "--------------------------------" << endl;
		cout << " 取消了加選課程。" << endl;

		cout << endl << "--------------------------------" << endl;
		system("PAUSE");
		system("cls");
	}
}

void delCourse(student stu, course cus) {
	int success(0);
	stu.get();

	cout << endl << "--------------------------------" << endl;
	int cNum;
	cout << "請輸入課程編號: ";    cin >> cNum;
	int s = stu.sPow;
	cNum--;
	if ((cNum < CUS_MAX) && (cNum >= 0)) {
		if (stu.course[s][cNum] != "") {
			for (int i = 0; i < cus.cSize; i++) {
				cus.cFind = cus.name[i].find(stu.course[s][cNum]);
				cus.cPow = cus.cSize;
				if (cus.cFind != cus.name[i].npos) {
					cus.cPow = i;
					break;
				}
			}
			int c = cus.cPow;
			system("cls");

			cout << endl << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << " 課程資料" << endl;

			cout << "--------------------------------" << endl;
			cout << setw(4) << "編號" << setw(10) <<  "名稱" << setw(10) <<  "成績" << endl;
			cout << setw(4) << cNum << setw(10) <<  stu.course[s][cNum] << setw(10) <<  stu.score[s][cNum] << endl;
			if (cus.cPow < cus.cSize) {
				char ans;
				cout << endl << "--------------------------------" << endl;
				cout << "確定要退選這門課程嗎? (y/n) : ";    cin >> ans;

				int s = stu.sPow;
				int c = cus.cPow;
				if ((ans == 'y') || (ans == 'Y')) {
					for (int j = 0; j < stu.cMax[s]; j++) {
						if (stu.course[s][j] == cus.name[c]) {
							stu.course[s][j] = stu.score[s][j] = "";
							for (int k = 0; k < cus.sMax[c]; k++) {
								if (cus.student[c][k] == stu.name[s]) {
									cus.student[c][k] = cus.score[c][k] = "";
									k--;
								}
							}
							success++;
							j--;
						}
					}
				}
			}
		}
		else {
			system("cls");
			cout << endl << "--------------------------------" << endl;
			cout << " 查無此課程資料。" << endl;

			cout << endl << "--------------------------------" << endl;
			system("PAUSE");
			system("cls");
		}
	}
	else {
		system("cls");
		cout << endl << "--------------------------------" << endl;
		cout << " 查無此課程資料。" << endl;

		cout << endl << "--------------------------------" << endl;
		system("PAUSE");
		system("cls");
	}
	if (success != 0) {
		cout << endl << "--------------------------------" << endl;
		cout << " 退選了這門課程。" << endl;

		cout << endl << "--------------------------------" << endl;
		system("PAUSE");
		system("cls");
	}
	else{

		cout << endl << "--------------------------------" << endl;
		cout << " 取消了退選課程。" << endl;

		cout << endl << "--------------------------------" << endl;
		system("PAUSE");
		system("cls");
	}
}

void typeScore(student stu, course cus) {
	cus.get();

	cout << endl << "--------------------------------" << endl;
	int sNum, cNum;
	cout << "請輸入學生座號: ";    cin >> sNum;
	int c = cus.cPow;
	sNum--;
	if ((sNum < STU_MAX) && (sNum >= 0)) {
		if (cus.student[c][sNum] != "") {
			for (int i = 0; i < stu.sSize; i++) {
				stu.sFind = stu.name[i].find(cus.student[c][sNum]);
				stu.sPow = stu.sSize;
				if (stu.sFind != stu.name[i].npos) {
					stu.sPow = i;
					break;
				}
			}
			int s = stu.sPow;
			for (int j = 0; j < stu.cMax[s]; j++) {
				stu.sFind = stu.course[s][j].find(cus.name[c]);
				cNum = stu.sSize;
				if (stu.sFind != stu.course[s][j].npos) {
					cNum = j;
					break;
				}
			}
			system("cls");
			if (stu.sPow < stu.sSize) {
				cout << endl << "--------------------------------" << endl;
				cout << "--------------------------------" << endl;
				cout << " 學生資料" << endl;

				cout << "--------------------------------" << endl;
				cout << setw(4) << "座號" << setw(10) << "學生" << setw(6) << "成績" << endl;
				cout << setw(4) << sNum + 1 << setw(10) << cus.student[c][sNum] << setw(6) << cus.score[c][sNum] << endl;

				cout << endl << "--------------------------------" << endl;
				cout << " 目前的成績為 " << cus.score[c][sNum] << endl;

				cout << endl << "--------------------------------" << endl;
				cout << "請輸入要修改的成績: ";    cin >> cus.score[c][sNum];
				stu.score[s][cNum] = cus.score[c][sNum];
				system("cls");
				cout << endl << "--------------------------------" << endl;
				cout << " 修改了成績為 " << cus.score[c][sNum] << " 。" << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");
			}
		}
		else {
			system("cls");
			cout << endl << "--------------------------------" << endl;
			cout << " 查無此學生資料。" << endl;

			cout << endl << "--------------------------------" << endl;
			system("PAUSE");
			system("cls");
		}
	}
	else {
		system("cls");
		cout << endl << "--------------------------------" << endl;
		cout << " 查無此學生資料。" << endl;

		cout << endl << "--------------------------------" << endl;
		system("PAUSE");
		system("cls");
	}
}

void reload(student stus, course cuss) {
	choose = menu = 0;
	admin = "";
	stus.sLogin = stus.sSize;
	cuss.cLogin = cuss.cSize;
}

int main(int argc, char *argv[]) {
	string stuId[] = {"1", "2", "3", "4", "5", "6", "7", "8"};
	string stuName[] = {"陳信宏", "溫尚翊", "蔡昇晏", "石錦航", "劉冠佑", "陳嘉樺", "田馥甄", "任家萱"};
	int stuSize = sizeof(stuName) / sizeof(stuName[0]);
	sName = new string[stuSize];
	sName = stuName;
	student stus(stuSize, stuId, stuName);

	string cusName[] = {"國文", "英文", "數學", "歷史", "理化", "音樂", "藝術", "體育"};
	int cusSize = sizeof(cusName) / sizeof(cusName[0]);
	cName = new string[cusSize];
	cName = cusName;
	course cuss(cusSize);
	reload(stus, cuss);
	do {
		//cout << "sLogin = " << stus.sLogin << ", sPow = " << stus.sPow << ", sSize = " << stus.sSize << endl;
		//cout << "cLogin = " << cuss.cLogin << ", cPow = " << cuss.cPow << ", cSize = " << cuss.cSize << endl;

		switch(menu) {
			case 0:
				defmenu();
				switch(choose) {
					case 0:    // 離開系統
						exit(1);
					case 1:    // 選課登入
					case 2:    // 成績輸入
					case 3:    // 後臺管理
						menu = choose;
						break;
					default:
						cout << endl << "--------------------------------" << endl;
						cout << " Error." << endl;

						cout << endl << "--------------------------------" << endl;
						system("PAUSE");
						system("cls");
						reload(stus, cuss);
						break;
				}
				break;
			case 1:
				if (stus.sLogin < stus.sSize) {
					stus.sPow = stus.sLogin;
					stus.get();
					stumenu();
					switch(choose) {
						case 0:
							reload(stus, cuss);
							stus.sLogin = stus.sPow = stus.sSize;
							break;
						case 1:    // 課程列表
							cuss.print();
							break;
						case 2:    // 課程加選
							addCourse(stus, cuss);
							break;
						case 3:    // 課程退選
							delCourse(stus, cuss);
							break;
						case 4:    // 資料修改
							stus.edit();
							break;
						default:
							cout << endl << "--------------------------------" << endl;
							cout << " Error." << endl;

							cout << endl << "--------------------------------" << endl;
							system("PAUSE");
							system("cls");
							reload(stus, cuss);
							break;
					}
				}
				else {
					stus.load();
					stus.sLogin = stus.sPow;
					if (stus.sLogin >= stus.sSize) {
						system("cls");
						cout << endl << "--------------------------------" << endl;
						cout << " 查無此學生資料。" << endl;

						cout << endl << "--------------------------------" << endl;
						system("PAUSE");
						system("cls");
						reload(stus, cuss);
					}
				}
				break;
			case 2:
				if (cuss.cLogin < cuss.cSize) {
					cuss.cPow = cuss.cLogin;
					cuss.get();
					cusmenu();
					switch(choose) {
						case 0:
							reload(stus, cuss);
							cuss.cLogin = cuss.cPow = cuss.cSize;
							break;
						case 1:    // 成績輸入
							typeScore(stus, cuss);
							break;
						case 2:    // 資料修改
							cuss.edit();
							break;
						default:
							cout << endl << "--------------------------------" << endl;
							cout << " Error." << endl;

							cout << endl << "--------------------------------" << endl;
							system("PAUSE");
							system("cls");
							reload(stus, cuss);
							break;
					}
				}
				else {
					cuss.load();
					cuss.cLogin = cuss.cPow;
					if (cuss.cLogin >= cuss.cSize) {
						system("cls");
						cout << endl << "--------------------------------" << endl;
						cout << " 查無此課程資料。" << endl;

						cout << endl << "--------------------------------" << endl;
						system("PAUSE");
						system("cls");
						reload(stus, cuss);
					}
				}
				break;
			case 3:
				if (admin == adminPW) {
					backmenu();
					switch(choose) {
						case 0:    // 返回目錄
							reload(stus, cuss);
							break;
						case 1:    // 課程列表
							cuss.print();
							break;
						case 2:    // 新增課程
							cuss.add();
							break;
						case 3:    // 修改課程
							cuss.edit();
							break;
						case 4:    // 移除課程
							cuss.del();
							break;
						case 5:    // 學生列表
							stus.print();
							break;
						case 6:    // 新增學生
							stus.add();
							break;
						case 7:    // 修改學生
							stus.edit();
							break;
						case 8:    // 移除學生
							stus.del();
							break;
						default:
							cout << endl << "--------------------------------" << endl;
							cout << " Error." << endl;

							cout << endl << "--------------------------------" << endl;
							system("PAUSE");
							system("cls");
							reload(stus, cuss);
							break;
					}
				}
				else {
					cout << endl << "請輸入密碼 (" << adminPW << ") : ";    cin >> admin;
					system("cls");
					if (admin != adminPW) {
						system("cls");
						cout << endl << "--------------------------------" << endl;
						cout << " 密碼錯誤。" << endl;

						cout << endl << "--------------------------------" << endl;
						system("PAUSE");
						system("cls");
						reload(stus, cuss);
					}
				}
				break;
			default:
				cout << endl << "--------------------------------" << endl;
				cout << " Error." << endl;

				cout << endl << "--------------------------------" << endl;
				system("PAUSE");
				system("cls");
				reload(stus, cuss);
				break;
		}
	}while(1);
	system("PAUSE");
    return 0;
}
