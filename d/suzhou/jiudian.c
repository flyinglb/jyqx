// Room: /d/suzhou/jiudai.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����һ�����ݳ��������ľ�¥������¥���Ե��Ϊ��ɫ��
ש��ľ��ʯ���߽�¥�ڣ�һ�۱㿴��һ����������ͼ��
�����˱��軭��Ω��ΩФ��¥������ϱ��������ſ���������
Ʒ�裬ֻ����С��æ�Ĳ����ֺ���
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"beidajie2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2": 1,
	]));
	setup();
	replace_program(ROOM);
}

