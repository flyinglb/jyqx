// Room: /d/hengshan/jinlongxia.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
����Ͽ�ֳ��������ǽ����ɽ����ڡ���ɽһ��̫��ɽ�����
�������������еı�����������֮Ϊ "����С����" ������ب����
�����һ���н��еĶ��У�������Ϊ "��ɽ����" ����� "̩ɽ
����" ��"��ɽ����"��"��ɽ����"��"��ɽ���"��
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu1",
		"northeast"  : "/d/city2/road6",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
	]));
	set("outdoors", "hengshan");
//        set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}

