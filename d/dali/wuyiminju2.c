//Room: /d/dali/wuyiminju2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
	set("long",@LONG
����һ��������ķ��ݡ�������ӵĽ��غ����򽲾���������ɽ
�ƣ�һ����ʯΪǽ�ͻ�����ľΪ�����ṹ���ºͺ��˷�����£�����
ƽ����ʯ��Χǽ�����Ժ����һ��ľ�ܣ�����Щɽ����ҰѼ�������
���һ���������ڸ������Ƥ���š�
LONG);
	set("objects", ([
	   __DIR__"npc/lieren": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"wumeng",
	]));
	setup();
	replace_program(ROOM);
}

