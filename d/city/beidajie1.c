// Room: /city/beidajie1.c
// YZC 1995/12/04 

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң������
�����ϱ���ȥ��������һ�����ֵĹ㳡��������һ��������¡�Ŀ�ջ������
���ص����ǽ�����������˵Ҳ�������ǵ��Ļ�ص㡣������һ��Ǯׯ������
�������������Ľ���������
LONG
	);
        set("outdoors", "city");
	set("objects", ([
		CLASS_D("btshan") + "/ouyangke" : 1,
//                 __DIR__"obj/jiao" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west"  : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));
//	set("objects", ([
//		CLASS_D("mingjiao") + "/zhangwuji" : 1,
//	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

