/*
ѧ������ϵͳ��ϵͳ����ʵ�֣���ɾ�Ĳ�
ʱ�䣺2018��1��25��
��������ѩ
�������ڣ�2018��1��26�գ���Լ�������Сʱ
*/
#include "stdio.h"
#include "windows.h"
//#include "stdlib.h"
//#pragma warning(disable : 4996)
int main()
{
	//����ѧ����Ϣ��������ѧ�ţ��Ա���ϵ��ʽ��������
	//����ѧ����ѧ��
	//�����Ÿ�ֵ��ʼ����ʱ���ַ�����ʱ�򣬱�����ͬһ�У����ֿܷ���
	char test_array[1000][10] = { 0 };//���ڶ�λ���
	char Numa_array[1000][10] = { 0 };//����
	char Numb_array[1000][15] = { 0 };//��Ȼ�����֣����Ǿ���char���ַ�����
	char Sex_array[1000][3] = { 0 };//�Ա�
	//���Ա�Ķ����������˺ܶ����⣬������������������ʱ����ֽ�һ��Ҫһ�¡�
	//��Ȼ�����������
	char Cantact_array[1000][20] = { 0 };//��ϵ��ʽ
	double Attendance_arry[1000] = { 0 };//������
	int choose = 0;//����ѡ��
	int revise = 0;//�޸�ѡ��
	int revise1 = 0;//����������޸�
	int sequence = 1;//�����������Ƚ�����
	int reset1 = 0; //�����еĻ���
	while (1)
	{
		printf("\t��ӭ����ѧ������ϵͳ��\n˵��:��1������Ϣ¼�룻��2������Ϣɾ��;\n     ��3������Ϣ�޸ģ���4������Ϣ��ѯ����0�˳�ϵͳ\n");
		scanf_s("%d", &choose);
		if (choose == 1)
		{
			//�ж������Ѿ�¼���˶�����ѧ������Ϣ
			sequence = 1;//Ϊ�˱�֤ѭ��ʱÿ�δӳ�ֵ��1��ʼ�����ܾͻ��γ�1 2 4 8 16
			//���������ʱ��sequence/2+1����Ȼ��õİ취��ֱ�Ӱ�i��ֵ�ý�ȥ��
			//��Ȼ��Ҫע��ֲ�������ȫ�ֱ���
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
			//������Ϣ¼��ģʽ
			printf("��ӭ������Ϣ¼��ģʽ��������¼���%dλͬѧ����Ϣ���밴����ʾ�Դ�¼����Ϣ��\n", sequence);
			printf("������������");
			scanf_s("%s", Numa_array[sequence - 1], 10);//����ͬѧ��������Ϣ�洢
			printf("������ѧ�ţ�");
			scanf_s("%s", Numb_array[sequence - 1], 15);//����ѧ��
			printf("�������Ա�");
			scanf_s("%s", Sex_array[sequence - 1], 3);//�����Ա�+�ж��Ƿ�������ȷ
			if (strcmp(Sex_array[sequence - 1], "��") != 0 && strcmp(Sex_array[sequence - 1], "Ů") != 0)
			{
				//������жϳ����˺þã���ʼ���˷��ַ����ıȽϾ��úô�
				//��������ַ����ģ�����һֱ���У�����֪������Ϊ��������
				//��Ȼ�ַ��������������ֽڣ���Ϊ��'\0'����[1000][3]
				//��sacnf_s(Sex_array[sequence-1],3)
				//�ڶ������ַ����ıȽϣ���s1<s2ʱ������ֵ<0
				//��s1 = s2ʱ������ֵ = 0;��s1 > s2ʱ������ֵ > 0
				 
				printf("���ٴ������Ա��л�Ů��");
				scanf_s("%s", Sex_array[sequence - 1], 3);
			}
			printf("��������ϵ��ʽ��");
			scanf_s("%s", Cantact_array[sequence - 1], 20);
			printf("����������ʣ�");
			scanf_s("%lf", &Attendance_arry[sequence - 1]);//����ȱ����
														  //��������Ϣ֮�󣬿��Խ������һ��Ȳ�
			printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
				sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
				Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
			printf("���ٴκ˶���Ϣ�����˶�����1ȷ¼�룬������2�����޸ģ�\n");
			scanf_s("%d", &choose);
			if (choose == 1)
			{
				printf("¼����ϣ�����������ҳ��");
				Sleep(2000);
				system("cls");//������ҳ
			}
			else if (choose ==2)
			{
			//�޸�
				
				while (1)
				{
				printf("��������Ҫ�޸ĵ��\n����������1��ѧ������2���Ա�����3����ϵ��ʽ����4��������5,�˳�����0��");
				scanf_s("%d", &revise1);
					switch (revise1)
					{
					case 1:
					{
						if (revise1 == 1)
						{
							printf("��������ȷ��������");
							scanf_s("%s", Numa_array[sequence - 1], 10);
							//�����ж��Ա��Ƿ�������ȷ
						}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise1);
						if (revise1 == 1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
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
							printf("��������ȷ��ѧ�ţ�");
							scanf_s("%s", Numb_array[sequence - 1],15);
							//�����ж��Ա��Ƿ�������ȷ
						}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise1);
						if (revise1 == 1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
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
						printf("��������ȷ���Ա�");
						scanf_s("%s", Sex_array[sequence - 1],3);
						//�����ж��Ա��Ƿ�������ȷ
						if (strcmp(Sex_array[sequence - 1], "��") != 0 && strcmp(Sex_array[sequence - 1], "Ů") != 0)
						{
							printf("���ٴ������Ա��л�Ů��");
							scanf_s("%s", Sex_array[sequence - 1], 3);
						}
					}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise1);
						if (revise1==1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
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
							printf("��������ȷ����ϵ��ʽ��");
							scanf_s("%s", Cantact_array[sequence - 1], 20);
							//�����ж��Ա��Ƿ�������ȷ
						}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise1);
						if (revise1 == 1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
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
							printf("��������ȷ����ϵ��ʽ��");
							scanf_s("%s", Cantact_array[sequence - 1], 20);
							//�����ж��Ա��Ƿ�������ȷ
						}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise1);
						if (revise1 == 1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
						}
						else if (revise1 == 2)
						{
							break;
						}
					}
					case 0:
					{
						printf("¼����ϣ�����������ҳ��");
						break;//������һ��
					}
					
					default:
					{
						printf("������涨����");
						system("cls");
						break;
					}
					
					}
					//ʵ������0�˳�
					if (revise1 == 0||revise1==1)
					{
						break;//������ҳ
					}
				
					
				}
				Sleep(2000);
				system("cls");
			}
	}
		else if (choose ==2)
		{
			//ɾ��
			printf("������Ҫɾ��ѧ������ţ�\n");
			scanf_s("%d", &sequence);
			printf("���ٴ�����ȷ��ɾ����\n");
			scanf_s("%d", &sequence);
			int y = sequence;//��ɾ������ʼλ��ֵ
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
			printf("������1������ҳ��");
			int z = 0;
			scanf_s("%d", &z);
			
		}
		else if (choose == 3)
		{
			//�޸�
			while (1)
			{
				printf("������Ҫ�޸�ͬѧ�����\n");
				scanf_s("%d", &sequence);
				if (strcmp(Numa_array[sequence - 1], "\0") != 0) 
				{
					printf("��ǰ��ͬѧ����ϢΪ��\n");
					printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
						sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
						Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
					printf("��������Ҫ�޸ĵ��\n����������1��ѧ������2���Ա�����3����ϵ��ʽ����4��������5,�˳�����0��\n");
					scanf_s("%d", &revise);
					switch (revise)
					{
					case 1:
					{
						if (revise == 1)
						{
							printf("��������ȷ��������");
							scanf_s("%s", Numa_array[sequence - 1], 10);
							//�����ж��Ա��Ƿ�������ȷ
						}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
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
							printf("��������ȷ��ѧ�ţ�");
							scanf_s("%s", Numb_array[sequence - 1], 15);
							//�����ж��Ա��Ƿ�������ȷ
						}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
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
							printf("��������ȷ���Ա�");
							scanf_s("%s", Sex_array[sequence - 1], 3);
							//�����ж��Ա��Ƿ�������ȷ
							if (strcmp(Sex_array[sequence - 1], "��") != 0 && strcmp(Sex_array[sequence - 1], "Ů") != 0)
							{
								printf("���ٴ������Ա��л�Ů��");
								scanf_s("%s", Sex_array[sequence - 1], 3);
							}
						}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
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
							printf("��������ȷ����ϵ��ʽ��");
							scanf_s("%s", Cantact_array[sequence - 1], 20);
							//�����ж��Ա��Ƿ�������ȷ
						}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
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
							printf("��������ȷ����ϵ��ʽ��");
							scanf_s("%s", Cantact_array[sequence - 1], 20);
							//�����ж��Ա��Ƿ�������ȷ
						}
						printf("���޸Ĺ������ϢΪ��\n");
						printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
							sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
							Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
						printf("������������1���������޸�������2");
						scanf_s("%d", &revise);
						if (revise == 1)
						{
							printf("¼����ϣ�����������ҳ��");
							Sleep(2000);
							system("cls");
							break;//������ҳ
						}
						else if (revise == 2)
						{
							break;
						}
					}
					case 0:
					{
						printf("¼����ϣ�����������ҳ��");
						Sleep(2000);
						system("cls");
						break;//������һ��
					}

					default:
					{
						printf("������涨����");
						system("cls");
						break;
					}

				
				}
					//ʵ������0�˳�
				if (revise == 0 || revise == 1)
				{
					break;//������ҳ
				}

				}
			else 
			{
				printf("�����ѧ������Ϣ��δ¼�룬����������ҳ��");
				Sleep(2000);
				system("cls");
				break;
			}
			}
		}
		else if (choose ==4)
		{
			printf("��������Ҫ�鵽ͬѧ����ţ�\n");
			scanf_s("%d", &sequence);
			if (strcmp(Numa_array[sequence - 1], "\0") != 0)
			{
				printf("����ͬѧ��Ϣ���£�\n");
				printf("\t���:%d\t\t������%s\n\tѧ��:%s\t\t�Ա�%s\n\t��ϵ��ʽ��%s\t������:%lf\n",
					sequence, Numa_array[sequence - 1], Numb_array[sequence - 1], Sex_array[sequence - 1],
					Cantact_array[sequence - 1], Attendance_arry[sequence - 1]);
				printf("������1������ҳ��\n");
				scanf_s("%d", &reset1);
				system("cls");
				Sleep(2000);
			}
			else 
			{
				printf("�����ͬѧ����Ϣ��δ¼��!");
				printf("������1������ҳ��\n");
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
			printf("����������ٴ����룡\n");
		}

	}
	
	system("pause");
	return 0;
}