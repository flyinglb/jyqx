//Room: /d/dali/jinzhihe.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��֭����");
	set("long",@LONG
����λ����֭���ϣ�ԭ������һ���ز��£������Ժ��ϡ�Ψ��һ��
ʯ�̾���(jingzhuang)�������С��˴�Ϊ��׶״���߲�ʯ�񡣸�Լ����ߣ�
����Ϊ�˽��ε���ʯ�����Ͽ��������������֮���н�ʯ�����Ǳ���֮��
�ܣ������ϲ�֮��ʯ��
LONG);
	set("item_desc", ([
	   "jingzhuang" : "���Ǹ�ϡ����������ȥ����Ҳ������\n",
	]));
	set("objects", ([
	   __DIR__"npc/seng": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"yanchi1",
	    "west"  : __DIR__"xiaojing",
	    "enter" : __DIR__"jingzhuang1",
	]));
	setup();
	replace_program(ROOM);
}

