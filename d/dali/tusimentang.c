//Room: /d/dali/tusimentang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�����Լ�����һЩ������������Ȳ֣����������������ж��׶�
�����޵�Χǽ�����彨���ǹ�ģ�������������������ϵ�����Ъ
ɽ������ʽ����������ʮ�ߣ�����ʮ���壬����ʮ�ߡ���¥��������
����Сͷ�����ص㣬Ҳ�������ҡ�
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"tusihouting",
	    "up"     : __DIR__"tusiyishi",
	    "out"    : __DIR__"tusifu",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

