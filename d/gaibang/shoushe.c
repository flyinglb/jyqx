//room: shoushe.c
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
������ؤ����ӵ����ᡣ���﻿���˸������ޣ��Թ�������ؤ��
����ʹ�á����������޳���˻������Զ�����ü���������ҹ��������
������˺���ѷεĲ��ҡ�
LONG );
	set("exits",([
		"east"  : "/d/city/pomiao",
	]));
	set("outdoors", "baituo");
	set("objects",([
		"/d/baituo/npc/fox" :1,
		"/d/baituo/npc/wolf" :1,
		"/d/baituo/npc/tiger" :1,
		"/d/baituo/npc/lion" :1,
	]));
	setup();
	replace_program(ROOM);
}

