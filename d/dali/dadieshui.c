//Room: /d/dali/dadieshui.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���ˮ�ٲ�");
	set("long",@LONG
��ɽ��С·Խ���꣬����ׯ������Ұ��Լ�����������������
ˮ���ĺ�������ǰ������һƬ�µص�ǰ�ˣ����ֵ�Ѿ�������䣬�Ǿ�
��ĺ����������Ǵ����乵�ﴫ���ġ������ϵ�֮����С·���ٷ�ʯ
��ǰ��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : __DIR__"chahuashan6",
	    "eastdown"   : __DIR__"xiaojing",
	    "southdown"  : __DIR__"qingxi",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

