//Room: /d/dali/zhengdian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�����Ǵ�����ʹ����������ʵ�ͨ���������ﴦ����£�
�����ڻʵ۲��ڣ������Եò���ô�н��������ǳ��ȡ�
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"hualang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

