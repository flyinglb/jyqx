
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�������ԶԶ�ľͿ������������ǡ�������ͨ��
��ɽ��
LONG );
	set("exits", ([
		"northwest" : __DIR__"road5",
		"southwest" : "/d/hengshan/jinlongxia",
		"southeast" : __DIR__"road7",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}



