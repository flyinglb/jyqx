//Room: /d/dali/yuxiashan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ϼɽ");
	set("long",@LONG
��ϼɽ�������ƺ���ɽ�����㣬��������������ͺ���ɽɫ����
��Ϊ֮�㵹��������ʫԻ��
      ��ϼ������������
      ���ƺ�ˮ�����⣬
      ���캬�����ϴ䣬
      Զɽ�ͱ�Ħ��ԣ�
      ˮ��ɽɫ���ӳ��
      �������Ʊ��쾻��
LONG);
	set("objects", ([
	   __DIR__"npc/youke": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "westdown"  : __DIR__"xingyunhu",
	]));
	setup();
	replace_program(ROOM);
}

