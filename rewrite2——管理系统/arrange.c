/*
学生管理系统，系统功能实现：增删改查
时间：2018年1月25日
天气：大雪
结束日期：2018年1月26日，大约花了五个小时
*/
#include "stdio.h"
#include "windows.h"
//#include "stdlib.h"
//#pragma warning(disable : 4996)
int main()
{
	//增加学生信息：姓名，学号，性别，联系方式，出勤率
	//定义学生的学号
	//大括号赋值初始化的时候及字符串的时候，必须在同一行，不能分开。
	char test_array[1000][10] = { 0 };//用于定位序号
	char Numa_array[1000][10] = { 0 };//姓名
	char Numb_array[1000][15] = { 0 };//虽然是数字，但是就以char型字符串了
	char Sex_array[1000][3] = { 0 };//性别
	//在性别的定义中遇到了很多问题，就是这个和下面的输入时候的字节一定要一致。
	//不然数组会有问题
	char Cantact_array[1000][20] = { 0 };//联系方式
	double Attendance_arry[1000] = { 0 };//出勤率
	int choose = 0;//输入选择
	int revise = 0;//修改选项
	int revise1 = 0;//输入界面中修改
	int sequence = 1;//用两个变量比较清晰
	int reset1 = 0; //查找中的回退
	while (1)
	{
		printf("\t欢迎进入学生管理系统！\n说明:按1进入信息录入；按2进入信息删除;\n     按3进入信息修改；按4进入信息查询按；0退出系统\n");
		scanf_s("%d", &choose);
		if (choose == 1)
		{
			//判断现在已经录入了多少名学生的信息
			sequence = 1;//为了保证循环时每次从初值从1开始，不能就会形成1 2 4 8 16
			//或者输出的时候sequence/2+1；当然最好的办法是直接把i的值用进去。
			//当然需要注意局部变量和全局变量
			for (int i = 1; i <= 1000; i++)
			{
				
				if (strcmp(Numa_array[i-1],"\0")==0)
				{
					break;
				}
				else 
				{
					sequence++;
				}
			
			}
			//进入信息录入模式
			printf("欢迎进入信息录入模式：您即将录入第%d位同学的信息，请按照提示以此录入信息！\n", sequence);
			printf("请输入姓名：");
			scanf_s("%s", Numa_array[sequence - 1], 10);//将新同学的姓名信息存储
			printf("请输入学号：");
			scanf_s("%s", Numb_array[sequence - 1], 15);//输入学号
			printf("请输入性别：");
			scanf_s("%s", Sex_array[sequence - 1], 3);//输入性别+判断是否输入正确
			if (strcmp(Sex_array[sequence - 1], "男") != 0 && strcmp(Sex_array[sequence - 1], "女") != 0)
			{
				//这里的判断尝试了好久，开始用了非字符串的比较觉得好蠢
				//最后用了字符串的，但是一直不行，最后才知道是因为两个错误：
				//既然字符串就至少三个字节，因为有'\0'所以[1000][3]
				//和sacnf_s(Sex_array[sequence-1],3)
				//第二个是字符串的比较，当s1<s2时，返回值<0
				//当s1 = s2时，返回值 = 0;当s1 > s2时，返回值 > 0
				 
				printf("请再次输入性别，男或女：");
				scanf_s("%s", Sex_array[sequence - 1], 3);
			}
			printf("请输入联系方式：");
			scanf_s("%s", Cantact_array[sequence - 1], 20);
			printf("请输入出勤率：");
			scanf_s("%lf", &Attendance_arry[sequence - 1]);//输入缺勤率
														  //输入完信息之后，可以进行最后一遍喝茶
			printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
				sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
				Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
			printf("请再次核对信息，若核对无误按1确录入，若有误按2进行修改！\n");
			scanf_s("%d", &choose);
			if (choose == 1)
			{
				printf("录入完毕，即将返回首页！");
				Sleep(2000);
				system("cls");//返回首页
			}
			else if (choose ==2)
			{
			//修改
				
				while (1)
				{
				printf("请输入需要修改的项：\n姓名请输入1，学号输入2，性别输入3，联系方式输入4，出勤率5,退出输入0！");
				scanf_s("%d", &revise1);
					switch (revise1)
					{
					case 1:
					{
						if (revise1 == 1)
						{
							printf("请输入正确的姓名：");
							scanf_s("%s", Numa_array[sequence - 1], 10);
							//如上判断性别是否输入正确
						}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise1);
						if (revise1 == 1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise1 == 2)
						{
							break;
						}
					}
					case 2:
					{
						if (revise1 ==2)
						{
							printf("请输入正确的学号：");
							scanf_s("%s", Numb_array[sequence - 1],15);
							//如上判断性别是否输入正确
						}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise1);
						if (revise1 == 1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise1 == 2)
						{
							break;
						}
					}
					case 3:
					{
					if (revise1==3)
					{
						printf("请输入正确的性别：");
						scanf_s("%s", Sex_array[sequence - 1],3);
						//如上判断性别是否输入正确
						if (strcmp(Sex_array[sequence - 1], "男") != 0 && strcmp(Sex_array[sequence - 1], "女") != 0)
						{
							printf("请再次输入性别，男或女：");
							scanf_s("%s", Sex_array[sequence - 1], 3);
						}
					}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise1);
						if (revise1==1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise1==2)
						{
							break;
						}
				
						
					}
					case 4:
					{
						if (revise1 == 4)
						{
							printf("请输入正确的联系方式：");
							scanf_s("%s", Cantact_array[sequence - 1], 20);
							//如上判断性别是否输入正确
						}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise1);
						if (revise1 == 1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise1 == 2)
						{
							break;
						}
					}
					case 5:
					{
						if (revise1 == 5)
						{
							printf("请输入正确的联系方式：");
							scanf_s("%s", Cantact_array[sequence - 1], 20);
							//如上判断性别是否输入正确
						}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise1);
						if (revise1 == 1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise1 == 2)
						{
							break;
						}
					}
					case 0:
					{
						printf("录入完毕，即将返回首页！");
						break;//返回上一层
					}
					
					default:
					{
						printf("请输入规定数字");
						system("cls");
						break;
					}
					
					}
					//实现输入0退出
					if (revise1 == 0||revise1==1)
					{
						break;//返回首页
					}
				
					
				}
				Sleep(2000);
				system("cls");
			}
	}
		else if (choose ==2)
		{
			//删除
			printf("请输入要删除学生的序号：\n");
			scanf_s("%d", &sequence);
			printf("请再次输入确认删除：\n");
			scanf_s("%d", &sequence);
			int y = sequence;//将删除的起始位赋值
			for (y;y<10;y++)
			{
				strcpy_s(Numa_array[y - 1],sizeof(Numb_array[y-1]) ,Numa_array[y]);
				strcpy_s(Numb_array[y - 1], sizeof(Numb_array[y-1]), Numb_array[y]);
				strcpy_s(Sex_array[y - 1], sizeof(Sex_array[y-1]), Sex_array[y]);
				strcpy_s(Cantact_array[y - 1], sizeof(Cantact_array[y-1]), Sex_array[y]);
				/*Numa_array[y - 1] = Numa_array[y];
				Numb_array[y - 1] = Numb_array[y];
				Sex_array[y - 1] = Sex_array[y];
				Cantact_array[y - 1] = Cantact_array[y];*/
				Attendance_arry[y - 1] = Attendance_arry[y];
			}
			printf("请输入1返回首页：");
			int z = 0;
			scanf_s("%d", &z);
			
		}
		else if (choose == 3)
		{
			//修改
			while (1)
			{
				printf("请输入要修改同学的序号\n");
				scanf_s("%d", &sequence);
				if (strcmp(Numa_array[sequence - 1], "\0") != 0) 
				{
					printf("当前次同学的信息为：\n");
					printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
						sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
						Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
					printf("请输入需要修改的项：\n姓名请输入1，学号输入2，性别输入3，联系方式输入4，出勤率5,退出输入0！\n");
					scanf_s("%d", &revise);
					switch (revise)
					{
					case 1:
					{
						if (revise == 1)
						{
							printf("请输入正确的姓名：");
							scanf_s("%s", Numa_array[sequence - 1], 10);
							//如上判断性别是否输入正确
						}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise == 2)
						{
							break;
						}
					}
					case 2:
					{
						if (revise == 2)
						{
							printf("请输入正确的学号：");
							scanf_s("%s", Numb_array[sequence - 1], 15);
							//如上判断性别是否输入正确
						}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise == 2)
						{
							break;
						}
					}
					case 3:
					{
						if (revise == 3)
						{
							printf("请输入正确的性别：");
							scanf_s("%s", Sex_array[sequence - 1], 3);
							//如上判断性别是否输入正确
							if (strcmp(Sex_array[sequence - 1], "男") != 0 && strcmp(Sex_array[sequence - 1], "女") != 0)
							{
								printf("请再次输入性别，男或女：");
								scanf_s("%s", Sex_array[sequence - 1], 3);
							}
						}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise == 2)
						{
							break;
						}


					}
					case 4:
					{
						if (revise == 4)
						{
							printf("请输入正确的联系方式：");
							scanf_s("%s", Cantact_array[sequence - 1], 20);
							//如上判断性别是否输入正确
						}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise == 2)
						{
							break;
						}
					}
					case 5:
					{
						if (revise == 5)
						{
							printf("请输入正确的联系方式：");
							scanf_s("%s", Cantact_array[sequence - 1], 20);
							//如上判断性别是否输入正确
						}
						printf("您修改过后的信息为：\n");
						printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("若无误请输入1，若仍需修改请输入2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("录入完毕，即将返回首页！");
							Sleep(2000);
							system("cls");
							break;//返回首页
						}
						else if (revise == 2)
						{
							break;
						}
					}
					case 0:
					{
						printf("录入完毕，即将返回首页！");
						Sleep(2000);
						system("cls");
						break;//返回上一层
					}

					default:
					{
						printf("请输入规定数字");
						system("cls");
						break;
					}

				
				}
					//实现输入0退出
				if (revise == 0 || revise == 1)
				{
					break;//返回首页
				}

				}
			else 
			{
				printf("此序号学生的信息尚未录入，即将返回首页！");
				Sleep(2000);
				system("cls");
				break;
			}
			}
		}
		else if (choose ==4)
		{
			printf("请输入你要查到同学的序号：\n");
			scanf_s("%d", &sequence);
			if (strcmp(Numa_array[sequence - 1], "\0") != 0)
			{
				printf("查找同学信息如下：\n");
				printf("\t序号:%d\t\t姓名：%s\n\t学号:%s\t\t性别：%s\n\t联系方式：%s\t出勤率:%lf\n",
					sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
					Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
				printf("请输入1返回首页！\n");
				scanf_s("%d", &reset1);
				system("cls");
				Sleep(2000);
			}
			else 
			{
				printf("此序号同学的信息还未录入!");
				printf("请输入1返回首页！\n");
				scanf_s("%d", &reset1);
				system("cls");
				Sleep(2000);
			}

		}
		else if (choose == 0)
		{
			return 0;
		}
		else 
		{
			printf("输入错误，请再次输入！\n");
		}

	}
	
	system("pause");
	return 0;
}